// Sesión 4: Actuadores – comunicando con señales
// Ejemplo básico - Control de LEDs monocolores y RGB según estado del sistema

// Pines para LEDs monocolores
const int ledVerde = 9;    // LED verde - estado normal
const int ledAmarillo = 10; // LED amarillo - estado intermedio  
const int ledRojo = 11;    // LED rojo - estado crítico

// Pines para LED RGB (común cátodo)
const int rgbRojo = 5;     // Pin PWM para componente rojo del RGB
const int rgbVerde = 6;    // Pin PWM para componente verde del RGB
const int rgbAzul = 7;     // Pin PWM para componente azul del RGB

// Sensor de entrada simulado (potenciómetro)
const int sensorPin = A0;

// Variables
float valorSensor;
int estadoSistema = 0; // 0 = normal, 1 = intermedio, 2 = crítico

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema de actuadores - Control de LEDs monocolores y RGB");
  
  // Configurar pines de LEDs monocolores
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  // Configurar pines PWM para LED RGB
  pinMode(rgbRojo, OUTPUT);
  pinMode(rgbVerde, OUTPUT);
  pinMode(rgbAzul, OUTPUT);
  
  // Configurar pin del sensor
  pinMode(sensorPin, INPUT);
  
  // Apagar todos los LEDs al inicio
  apagarLEDs();
  apagarRGB();
}

void loop() {
  // Leer valor del sensor (0-1023)
  int lecturaSensor = analogRead(sensorPin);
  
  // Convertir a valor normalizado (0-100%)
  valorSensor = map(lecturaSensor, 0, 1023, 0, 100);
  
  // Determinar estado del sistema basado en el valor del sensor
  if (valorSensor > 70.0) {
    estadoSistema = 2; // Crítico
  } else if (valorSensor > 40.0) {
    estadoSistema = 1; // Intermedio
  } else {
    estadoSistema = 0; // Normal
  }
  
  // Controlar LEDs monocolores según estado
  controlarLEDs();
  
  // Controlar LED RGB con colores intermedios
  controlarRGB();
  
  // Mostrar información
  Serial.print("Valor sensor: ");
  Serial.print(lecturaSensor);
  Serial.print(" | Valor normalizado: ");
  Serial.print(valorSensor);
  Serial.print("% | Estado: ");
  
  switch(estadoSistema) {
    case 0: 
      Serial.println("Normal (Verde)");
      break;
    case 1:
      Serial.println("Intermedio (Amarillo/Naranja)");
      break;
    case 2:
      Serial.println("Crítico (Rojo)");
      break;
  }
  
  delay(1000);
}

void controlarLEDs() {
  // Apagar todos los LEDs monocolores primero
  apagarLEDs();
  
  // Encender el LED correspondiente al estado
  switch(estadoSistema) {
    case 0: // Normal - LED verde
      digitalWrite(ledVerde, HIGH);
      break;
    case 1: // Intermedio - LED amarillo
      digitalWrite(ledAmarillo, HIGH);
      break;
    case 2: // Crítico - LED rojo
      digitalWrite(ledRojo, HIGH);
      break;
  }
}

void controlarRGB() {
  // Apagar LED RGB primero
  apagarRGB();
  
  // Controlar LED RGB según el estado y valor del sensor
  switch(estadoSistema) {
    case 0: // Normal - Verde puro
      analogWrite(rgbVerde, 255);
      analogWrite(rgbRojo, 0);
      analogWrite(rgbAzul, 0);
      break;
    case 1: // Intermedio - Mezcla según valor exacto
      // Crear gradiente entre amarillo y naranja
      int intensidadRojo = map(valorSensor, 40, 70, 150, 255);
      int intensidadVerde = map(valorSensor, 40, 70, 255, 100);
      analogWrite(rgbRojo, intensidadRojo);
      analogWrite(rgbVerde, intensidadVerde);
      analogWrite(rgbAzul, 0);
      break;
    case 2: // Crítico - Rojo puro
      analogWrite(rgbRojo, 255);
      analogWrite(rgbVerde, 0);
      analogWrite(rgbAzul, 0);
      break;
  }
}

void apagarLEDs() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
}

void apagarRGB() {
  analogWrite(rgbRojo, 0);
  analogWrite(rgbVerde, 0);
  analogWrite(rgbAzul, 0);
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

// Función para demostración de colores RGB (opcional)
void demostracionRGB() {
  Serial.println("Demostración de colores RGB:");
  
  // Rojo
  analogWrite(rgbRojo, 255);
  analogWrite(rgbVerde, 0);
  analogWrite(rgbAzul, 0);
  Serial.println("  Rojo");
  delay(1000);
  
  // Verde
  analogWrite(rgbRojo, 0);
  analogWrite(rgbVerde, 255);
  analogWrite(rgbAzul, 0);
  Serial.println("  Verde");
  delay(1000);
  
  // Azul
  analogWrite(rgbRojo, 0);
  analogWrite(rgbVerde, 0);
  analogWrite(rgbAzul, 255);
  Serial.println("  Azul");
  delay(1000);
  
  // Amarillo (Rojo + Verde)
  analogWrite(rgbRojo, 255);
  analogWrite(rgbVerde, 255);
  analogWrite(rgbAzul, 0);
  Serial.println("  Amarillo");
  delay(1000);
  
  // Magenta (Rojo + Azul)
  analogWrite(rgbRojo, 255);
  analogWrite(rgbVerde, 0);
  analogWrite(rgbAzul, 255);
  Serial.println("  Magenta");
  delay(1000);
  
  // Cian (Verde + Azul)
  analogWrite(rgbRojo, 0);
  analogWrite(rgbVerde, 255);
  analogWrite(rgbAzul, 255);
  Serial.println("  Cian");
  delay(1000);
  
  // Blanco (todos los colores)
  analogWrite(rgbRojo, 255);
  analogWrite(rgbVerde, 255);
  analogWrite(rgbAzul, 255);
  Serial.println("  Blanco");
  delay(1000);
  
  // Apagar
  apagarRGB();
  Serial.println("  Apagado");
}
