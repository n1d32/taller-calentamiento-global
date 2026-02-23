#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  pinMode(2, OUTPUT); // LED integrado en la mayoría de ESP32
  
  Serial.println("ESP32 Inicializado!");
  Serial.print("Chip: ");
  Serial.println(ESP.getChipModel());
  Serial.println("Listo para recibir comandos...");
}

// TAREA: Buscar iconos que les gusten
void loop() {
  digitalWrite(2, !digitalRead(2)); // Toggle LED
  Serial.printf("Uptime: %lu segundos\n", millis()/1000);
  delay(500);
}
