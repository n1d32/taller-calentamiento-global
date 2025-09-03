// Sesión 1: Desarmando la "casa"
// Ejemplo básico - Reconocimiento de componentes

const int LED_PIN = 2;

void setup() {
  // Inicializar comunicación serial para monitoreo
  Serial.begin(9600);
  Serial.println("Sistema iniciado - Reconociendo componentes");
  
  // Configurar pines básicos (ejemplo de reconocimiento)
  pinMode(LED_PIN, OUTPUT); // LED integrado en placa Arduino
}

void loop() {
  // Ejemplo simple de funcionamiento básico
  digitalWrite(LED_PIN, HIGH);   // Encender LED
  delay(500);               // Esperar medio segundo
  digitalWrite(LED_PIN, LOW);    // Apagar LED
  delay(500);               // Esperar medio segundo
  
  Serial.println("LED parpadeando - Componentes funcionando");
}
