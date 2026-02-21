#include <WiFi.h>
#include <WebServer.h>
#include "wifi_config.h"

WebServer server(80); // Puerto 80

// Función para agregar headers CORS
void addCORSHeaders() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
}

// Variables que quieres controlar
int ledBrightness = 50;
String deviceName = "Ciencia al Tiro - Modulo 1";
bool enableFeature = true;

void setup() {
  Serial.begin(115200);
  
  // Configurar pin 2 como salida para el LED
  pinMode(2, OUTPUT);
  
  // Conectar WiFi con timeout
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  Serial.print("Conectando a WiFi: ");
  Serial.println(ssid);
  
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 15000) {
    delay(500);
    Serial.print(".");
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi conectado!");
    Serial.print("📡 IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ Falló la conexión WiFi!");
    Serial.println("Estado: " + String(WiFi.status()));
  }

  // Configurar rutas API
  server.on("/api/status", HTTP_GET, []() {
    addCORSHeaders();
    server.send(200, "application/json", 
      "{\"brightness\":" + String(ledBrightness) + 
      ",\"name\":\"" + deviceName + 
      "\",\"feature\":" + String(enableFeature) + "}");
  });

  server.on("/api/update", HTTP_POST, []() {
    addCORSHeaders();
    if (server.hasArg("brightness")) {
      ledBrightness = server.arg("brightness").toInt();
    }
    if (server.hasArg("name")) {
      deviceName = server.arg("name");
    }
    if (server.hasArg("feature")) {
      enableFeature = server.arg("feature") == "true";
    }
    
    server.send(200, "application/json", "{\"status\":\"updated\"}");
    Serial.println("✅ Valores actualizados desde backend!");
  });

  // Handler para preflight requests (OPTIONS)
  server.on("/api/status", HTTP_OPTIONS, []() {
    addCORSHeaders();
    server.send(200);
  });

  server.on("/api/update", HTTP_OPTIONS, []() {
    addCORSHeaders();
    server.send(200);
  });

  server.begin();
  Serial.println("🚀 Servidor HTTP iniciado");
}

void loop() {
  server.handleClient(); // Manejar peticiones
  
  // Usar las variables en tu lógica
  analogWrite(2, ledBrightness);
  delay(100);
}
