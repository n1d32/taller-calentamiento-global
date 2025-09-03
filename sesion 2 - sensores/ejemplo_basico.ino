// Sesión 2: Sensores – escuchando al entorno
// Ejemplo básico - Lectura de sensor de temperatura (simulado)

// Simulación de sensor de temperatura (usando potenciómetro en pin A0)
const int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando lectura de sensores");
  
  // Configurar pin del sensor
  pinMode(sensorPin, INPUT);
}

void loop() {
  // Leer valor del sensor (0-1023)
  int sensorValue = analogRead(sensorPin);
  
  // Convertir a temperatura simulada (0-50°C)
  float temperatura = map(sensorValue, 0, 1023, 0, 500) / 10.0;
  
  // Mostrar datos en monitor serial
  Serial.print("Valor sensor: ");
  Serial.print(sensorValue);
  Serial.print(" | Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  // Pequeña pausa entre lecturas
  delay(1000);
  
  // Ejemplo de detección de cambios
  if (temperatura > 30.0) {
    Serial.println("¡Temperatura alta detectada!");
  } else if (temperatura < 15.0) {
    Serial.println("Temperatura baja detectada");
  }
}
