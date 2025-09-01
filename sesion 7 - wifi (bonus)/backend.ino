#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "VTR-2768272";
const char* password = "kmrypmXm47bd";

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
  Serial.begin(9600);
  
  // Conectar WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\n✅ WiFi conectado!");
  Serial.print("📡 IP: ");
  Serial.println(WiFi.localIP());

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
