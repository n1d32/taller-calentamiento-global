#include <Arduino.h>

// El script inicial será una versión simplificada:
// void setup() {
//   Serial.begin(115200);
//   pinMode(2, OUTPUT); 
// }
// void loop() {
//   digitalWrite(2, HIGH); // LED arriba
//   Serial.printf("El LED se ha encendido");
//   delay(1000);
//   digitalWrite(2, LOW); // LED abajo
//   delay(1000);
// }

// El script final incluirá modificaciones del estudiante, cada una
// con un objetivo de aprendizaje particular.
// 1. El estudiante aprenderá la estructura general con setup y void
// 2. Luego cambiará valores de delay modificando el script simple original
// 3. Aprenderá los diferentes tipos de variables (int, char, etc) y cómo asignarlas
// 4. Partirá con el LED externo y luego se le dirá que también hay uno interno
int PIN_LED = 2; // LED integrado en la mayoría de ESP32
int TIEMPO_ARRIBA = 500;
char* mensaje = "LED encendido";

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT); 
}

void loop() {
  digitalWrite(PIN_LED, HIGH); // LED arriba
  Serial.printf(mensaje);
  delay(TIEMPO_ARRIBA);
  digitalWrite(PIN_LED, LOW); // LED abajo
  delay(TIEMPO_ARRIBA);
}

