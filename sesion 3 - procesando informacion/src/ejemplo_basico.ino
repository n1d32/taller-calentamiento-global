#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("✅ DHT library cargada correctamente");
}

void loop() {
  readTemperature();
}


void readTemperature() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float m = makeModel(h, t);

  if (!isnan(h) && !isnan(t)) {
    Serial.printf("🌡️ Temp: %.1f°C, 💧 Hum: %.1f%%\n", t, h);
    Serial.printf("🌡️ Modelo: %.1f°C\n", m);
  } else {
    Serial.println("❌ Error reading DHT sensor!");
  }
  
  delay(2000);
}

float makeModel(float h, float t) {
  return h + t;
}