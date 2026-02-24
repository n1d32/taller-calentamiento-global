#include <Arduino.h>

// Definición de pines
const int ledPin = 2;      // LED integrado en la mayoría de ESP32
const int buttonPin = 13;   // Pin para el botón (usar resistencia pull-up interna)

// Variables para el control del botón
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; // Tiempo de debounce en milisegundos
int lastButtonState = HIGH; // Estado anterior del botón (HIGH cuando no presionado con pull-up)
int buttonState = HIGH;     // Estado actual del botón

// Variables de estado del sistema
enum SystemState { NORMAL, FEEDBACK };
SystemState currentState = NORMAL;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Configurar pines
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Usar resistencia pull-up interna
  
  Serial.println("ESP32 Inicializado - Sistema LED + Botón con Feedback Visual");
  Serial.print("Chip: ");
  Serial.println(ESP.getChipModel());
  Serial.println("Instrucciones:");
  Serial.println("1. Presiona el botón cuando el LED esté ENCENDIDO → Continúa normal");
  Serial.println("2. Presiona el botón cuando el LED esté APAGADO → Feedback visual de error");
  Serial.println("Feedback de error: LED parpadea rápidamente y luego se apaga 2 segundos");
  Serial.println("Listo para comenzar...");
  Serial.println("--------------------");
}

// Función para verificar el estado del botón con debounce
bool isButtonPressed() {
  int reading = digitalRead(buttonPin);
  
  // Si el estado cambió (debido a ruido o presionar real)
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reiniciar el temporizador de debounce
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Si el estado ha sido estable por más tiempo que el delay de debounce
    if (reading != buttonState) {
      buttonState = reading;
      
      // Solo reportar cuando el botón pasa de NO presionado a PRESIONADO
      if (buttonState == LOW) {
        lastButtonState = reading;
        return true;
      }
    }
  }
  
  lastButtonState = reading;
  return false;
}

// Función para feedback visual de error
void wrongPressFeedback() {
  Serial.println("¡Error! Presionaste cuando el LED estaba APAGADO");
  
  // Apagar LED al inicio (por si acaso)
  digitalWrite(ledPin, LOW);
  
  // Parpadeo rápido (10 flashes a 100ms de intervalo)
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  
  // Mantener LED apagado por 2 segundos como feedback adicional
  delay(1000);
  
  Serial.println("Feedback completado - Volviendo a operación normal");
}

// Función para manejar la lógica del botón
void handleButtonPress() {
  // Ignorar pulsaciones durante feedback
  if (currentState != NORMAL) {
    return;
  }
  
  if (isButtonPressed()) {
    // Pequeña pausa para estabilizar la lectura
    delay(10);
    
    // Verificar el estado del LED en el momento del press
    if (digitalRead(ledPin) == HIGH) {
      // Presión correcta - no hacer nada especial
      Serial.println("¡Correcto! Presionaste cuando el LED estaba ENCENDIDO");
    } else {
      // Presión incorrecta - activar feedback
      Serial.println("Detectada presión incorrecta - Activando feedback...");
      currentState = FEEDBACK;
      wrongPressFeedback();
      currentState = NORMAL;
    }
    
    // Esperar a que se suelte el botón
    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }
  }
}

void ledManagement() {
  // Solo gestionar LED si estamos en estado normal
  if (currentState != NORMAL) {
    return;
  }
  
  // Encender LED con tiempo aleatorio
  digitalWrite(ledPin, HIGH);
  int randomOn = random(300, 500);
  
  // Durante el tiempo ON, verificar el botón periódicamente
  unsigned long onStartTime = millis();
  while (millis() - onStartTime < randomOn) {
    handleButtonPress();
    delay(10); // Pequeña pausa para no saturar el CPU
  }
  
  // Apagar LED con tiempo aleatorio
  digitalWrite(ledPin, LOW);
  int randomOff = random(800, 1200);
  
  // Durante el tiempo OFF, verificar el botón periódicamente
  unsigned long offStartTime = millis();
  while (millis() - offStartTime < randomOff) {
    handleButtonPress();
    delay(10); // Pequeña pausa para no saturar el CPU
  }
}

void loop() {
  ledManagement();
}
