#include <Arduino.h>

// Modularizar
// El estudiante debe aprender a comentar su código
// Los estudiantes aprenden de código libre al revisar en conjunto
// Aprenderá a modularizar usando diferentes funciones
int pinLed = 15; // LED integrado en la mayoría de ESP32
int tiempoArriba = 1000;
int tiempoAbajo = 500;
// char* mensaje = "LED encendido";

const int pinBoton = 13;   // Pin para el botón (usar resistencia pull-up interna)
int estadoBoton;

void setup() {
  Serial.begin(115200);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBoton, INPUT_PULLUP);
}

void leerEstadoBoton () {
   estadoBoton = digitalRead(pinBoton);
   Serial.print("Estado del botón: ");
   Serial.print(estadoBoton);
   Serial.println("");
}

void cambiarEstadoLed() {
  digitalWrite(pinLed, HIGH); // LED arriba
  // Serial.println(mensaje);
  leerEstadoBoton();
  delay(tiempoArriba);
  digitalWrite(pinLed, LOW); // LED abajo
  delay(tiempoAbajo);
}

void loop() {
  cambiarEstadoLed();
}