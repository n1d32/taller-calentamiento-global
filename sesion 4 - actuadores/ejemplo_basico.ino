// Sesión 4: Actuadores – hablando con señales
// Ejemplo básico - Control de LEDs según estado climático

// Pines para LEDs de colores
const int ledVerde = 9;    // LED verde - estado fresco
const int ledAmarillo = 10; // LED amarillo - estado alerta  
const int ledRojo = 11;    // LED rojo - estado riesgo

// Sensor de temperatura simulado
const int sensorTempPin = A0;

// Variables
float temperatura;
int estadoClimatico = 0; // 0 = fresco, 1 = alerta, 2 = riesgo

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema de actuadores - Control de LEDs");
  
  // Configurar pines
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(sensorTempPin, INPUT);
  
  // Apagar todos los LEDs al inicio
  apagarLEDs();
}

void loop() {
  // Leer temperatura
  temperatura = map(analogRead(sensorTempPin), 0, 1023, 0, 500) / 10.0;
  
  // Determinar estado climático basado en temperatura
  if (temperatura > 30.0) {
    estadoClimatico = 2; // Riesgo
  } else if (temperatura > 25.0) {
    estadoClimatico = 1; // Alerta
  } else {
    estadoClimatico = 0; // Fresco
  }
  
  // Controlar LEDs según estado
  controlarLEDs();
  
  // Mostrar información
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("°C | Estado: ");
  
  switch(estadoClimatico) {
    case 0: 
      Serial.println("Fresco (Verde)");
      break;
    case 1:
      Serial.println("Alerta (Amarillo)");
      break;
    case 2:
      Serial.println("Riesgo (Rojo)");
      break;
  }
  
  delay(1000);
}

void controlarLEDs() {
  // Apagar todos los LEDs primero
  apagarLEDs();
  
  // Encender el LED correspondiente al estado
  switch(estadoClimatico) {
    case 0: // Fresco - LED verde
      digitalWrite(ledVerde, HIGH);
      break;
    case 1: // Alerta - LED amarillo
      digitalWrite(ledAmarillo, HIGH);
      break;
    case 2: // Riesgo - LED rojo
      digitalWrite(ledRojo, HIGH);
      break;
  }
}

void apagarLEDs() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
}

// Función adicional para parpadeo de alerta (ejemplo avanzado)
void parpadearAlerta(int pinLED, int veces, int duracion) {
  for (int i = 0; i < veces; i++) {
    digitalWrite(pinLED, HIGH);
    delay(duracion);
    digitalWrite(pinLED, LOW);
    delay(duracion);
  }
}
