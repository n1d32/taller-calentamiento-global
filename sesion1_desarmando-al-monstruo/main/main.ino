#include <Arduino.h>

// Definición de pines
const int ledPinVerde = 19;      // Primer LED (verde)
const int ledPinRojo = 13;       // Segundo LED (rojo)
const int buttonPinVerde = 21;    // Botón para el primer LED (verde)
const int buttonPinRojo = 12;    // Botón para el segundo LED (rojo)

// Variables para el control de los botones
unsigned long lastDebounceTimeVerde = 0;
const unsigned long debounceDelayVerde = 50; // Tiempo de debounce en milisegundos
int lastButtonStateVerde = HIGH; // Estado anterior del botón (HIGH cuando no presionado con pull-up)
int buttonStateVerde = HIGH;     // Estado actual del botón

unsigned long lastDebounceTimeRojo = 0;
const unsigned long debounceDelayRojo = 50; // Tiempo de debounce en milisegundos
int lastButtonStateRojo = HIGH; // Estado anterior del botón (HIGH cuando no presionado con pull-up)
int buttonStateRojo = HIGH;     // Estado actual del botón

// Variables de estado del sistema
enum SystemState { NORMAL, FEEDBACK };
SystemState currentState = NORMAL;

// Variables para control de LEDs
bool lastLEDWasVerde = true;     // Para probabilidad 70/30
int currentActiveLED = 0;        // 0 para verde, 1 para rojo

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Configurar pines
  pinMode(ledPinVerde, OUTPUT);
  pinMode(ledPinRojo, OUTPUT);
  pinMode(buttonPinVerde, INPUT_PULLUP); // Usar resistencia pull-up interna
  pinMode(buttonPinRojo, INPUT_PULLUP);  // Usar resistencia pull-up interna
  
  // Inicializar semilla aleatoria
  randomSeed(analogRead(0));
  
  Serial.println("ESP32 Inicializado - Sistema 2 LEDs + 2 Botones con Feedback Visual");
  Serial.print("Chip: ");
  Serial.println(ESP.getChipModel());
  Serial.println("Instrucciones:");
  Serial.println("1. Se encenderá aleatoriamente un LED (verde en pin 13 o rojo en pin 15)");
  Serial.println("2. Probabilidad: 70% mismo LED que antes, 30% LED diferente");
  Serial.println("3. Presiona el botón CORRECTO cuando el LED esté ENCENDIDO:");
  Serial.println("   - LED Verde encendido → Botón Verde (pin 2)");
  Serial.println("   - LED Rojo encendido → Botón Rojo (pin 12)");
  Serial.println("4. Presionar botón INCORRECTO o cuando LED apagado → Feedback de error");
  Serial.println("Feedback de error: LEDs parpadean rápidamente");
  Serial.println("Listo para comenzar...");
  Serial.println("--------------------");
}

// Función para verificar el estado del botón verde con debounce
bool isButtonVerdePressed() {
  int readingVerde = digitalRead(buttonPinVerde);
  
  // Si el estado cambió (debido a ruido o presionar real)
  if (readingVerde != lastButtonStateVerde) {
    lastDebounceTimeVerde = millis(); // Reiniciar el temporizador de debounce
  }
  
  if ((millis() - lastDebounceTimeVerde) > debounceDelayVerde) {
    // Si el estado ha sido estable por más tiempo que el delay de debounce
    if (readingVerde != buttonStateVerde) {
      buttonStateVerde = readingVerde;
      
      // Solo reportar cuando el botón pasa de NO presionado a PRESIONADO
      if (buttonStateVerde == LOW) {
        lastButtonStateVerde = readingVerde;
        return true;
      }
    }
  }
  
  lastButtonStateVerde = readingVerde;
  return false;
}

// Función para verificar el estado del botón rojo con debounce
bool isButtonRojoPressed() {
  int readingRojo = digitalRead(buttonPinRojo);
  
  // Si el estado cambió (debido a ruido o presionar real)
  if (readingRojo != lastButtonStateRojo) {
    lastDebounceTimeRojo = millis(); // Reiniciar el temporizador de debounce
  }
  
  if ((millis() - lastDebounceTimeRojo) > debounceDelayRojo) {
    // Si el estado ha sido estable por más tiempo que el delay de debounce
    if (readingRojo != buttonStateRojo) {
      buttonStateRojo = readingRojo;
      
      // Solo reportar cuando el botón pasa de NO presionado a PRESIONADO
      if (buttonStateRojo == LOW) {
        lastButtonStateRojo = readingRojo;
        return true;
      }
    }
  }
  
  lastButtonStateRojo = readingRojo;
  return false;
}

// Función para verificar si algún botón fue presionado
// Retorna: 0 = ninguno, 1 = verde, 2 = rojo
int checkButtonsPressed() {
  if (isButtonVerdePressed()) {
    return 1;
  }
  if (isButtonRojoPressed()) {
    return 2;
  }
  return 0;
}

// Función para feedback visual de error
void wrongPressFeedback() {
  Serial.println("¡Error! Presionaste botón incorrecto o cuando el LED estaba APAGADO");
  
  // Apagar ambos LEDs al inicio
  digitalWrite(ledPinVerde, LOW);
  digitalWrite(ledPinRojo, LOW);
  
  // Parpadeo rápido de ambos LEDs (3 flashes a 100ms de intervalo)
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPinVerde, HIGH);
    digitalWrite(ledPinRojo, HIGH);
    delay(100);
    digitalWrite(ledPinVerde, LOW);
    digitalWrite(ledPinRojo, LOW);
    delay(100);
  }
  
  // Mantener LEDs apagados por 1 segundo como feedback adicional
  delay(1000);
  
  Serial.println("Feedback completado - Volviendo a operación normal");
}

// Función para manejar la lógica de los botones
void handleButtonPress() {
  // Ignorar pulsaciones durante feedback
  if (currentState != NORMAL) {
    return;
  }
  
  int buttonPressed = checkButtonsPressed();
  
  if (buttonPressed > 0) {
    // Pequeña pausa para estabilizar la lectura
    delay(10);
    
    // Determinar qué LED debería estar encendido según currentActiveLED
    bool verdeShouldBeOn = (currentActiveLED == 0);
    bool rojoShouldBeOn = (currentActiveLED == 1);
    
    // Verificar si el botón presionado es el correcto
    bool correctButton = false;
    
    if (verdeShouldBeOn && buttonPressed == 1) {
      // LED verde encendido y botón verde presionado → CORRECTO
      correctButton = true;
    } else if (rojoShouldBeOn && buttonPressed == 2) {
      // LED rojo encendido y botón rojo presionado → CORRECTO
      correctButton = true;
    }
    
    // Verificar el estado actual del LED que debería estar encendido
    bool ledIsOn = false;
    if (verdeShouldBeOn) {
      ledIsOn = (digitalRead(ledPinVerde) == HIGH);
    } else {
      ledIsOn = (digitalRead(ledPinRojo) == HIGH);
    }
    
    if (ledIsOn && correctButton) {
      // Presión correcta - LED encendido y botón correcto
      Serial.print("¡Correcto! Presionaste botón ");
      Serial.print(buttonPressed == 1 ? "Verde" : "Rojo");
      Serial.println(" cuando el LED correspondiente estaba ENCENDIDO");
    } else {
      // Presión incorrecta - activar feedback
      Serial.print("¡Error! Presionaste botón ");
      Serial.print(buttonPressed == 1 ? "Verde" : "Rojo");
      Serial.print(" pero ");
      if (!ledIsOn) {
        Serial.println("el LED estaba APAGADO");
      } else {
        Serial.println("era el botón INCORRECTO para este LED");
      }
      Serial.println("Activando feedback...");
      currentState = FEEDBACK;
      wrongPressFeedback();
      currentState = NORMAL;
    }
    
    // Esperar a que se suelte el botón presionado
    if (buttonPressed == 1) {
      while (digitalRead(buttonPinVerde) == LOW) {
        delay(10);
      }
    } else {
      while (digitalRead(buttonPinRojo) == LOW) {
        delay(10);
      }
    }
  }
}

void ledManagement() {
  // Solo gestionar LEDs si estamos en estado normal
  if (currentState != NORMAL) {
    return;
  }
  
  // Apagar ambos LEDs primero
  digitalWrite(ledPinVerde, LOW);
  digitalWrite(ledPinRojo, LOW);
  
  // Decidir qué LED encender (70% mismo que antes, 30% el otro)
  bool selectSameLED = random(100) < 70; // 70% de probabilidad
  
  if (selectSameLED) {
    // Mantener mismo LED que antes
    // lastLEDWasVerde ya indica cuál fue el último
  } else {
    // Cambiar al otro LED
    lastLEDWasVerde = !lastLEDWasVerde;
  }
  
  // Actualizar currentActiveLED
  currentActiveLED = lastLEDWasVerde ? 0 : 1;
  
  // Encender el LED seleccionado
  if (lastLEDWasVerde) {
    digitalWrite(ledPinVerde, HIGH);
    Serial.println("LED Verde ENCENDIDO (pin 13)");
  } else {
    digitalWrite(ledPinRojo, HIGH);
    Serial.println("LED Rojo ENCENDIDO (pin 15)");
  }
  
  // Tiempo ON aleatorio (300-500ms)
  int randomOn = random(300, 500);
  
  // Durante el tiempo ON, verificar los botones periódicamente
  unsigned long onStartTime = millis();
  while (millis() - onStartTime < randomOn) {
    handleButtonPress();
    delay(10); // Pequeña pausa para no saturar el CPU
  }
  
  // Apagar el LED que estaba encendido
  if (lastLEDWasVerde) {
    digitalWrite(ledPinVerde, LOW);
  } else {
    digitalWrite(ledPinRojo, LOW);
  }
  
  // Tiempo OFF aleatorio (800-1200ms)
  int randomOff = random(800, 1200);
  
  // Durante el tiempo OFF, verificar los botones periódicamente
  unsigned long offStartTime = millis();
  while (millis() - offStartTime < randomOff) {
    handleButtonPress();
    delay(10); // Pequeña pausa para no saturar el CPU
  }
}

void loop() {
  ledManagement();
}
