// Sesión 3: Procesando la información – el "cerebro"
// Ejemplo básico - Combinación de datos de múltiples sensores

// Pines para sensores simulados
const int sensorTempPin = A0;    // Sensor de temperatura
const int sensorCO2Pin = A1;     // Sensor de CO2 (simulado)
const int sensorLuzPin = A2;     // Sensor de luz (simulado)

// Variables para almacenar lecturas
float temperatura;
int nivelCO2;
int nivelLuz;

// Estado climático calculado
int estadoClimatico = 0; // 0 = fresco, 1 = alerta, 2 = riesgo

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema de procesamiento climático iniciado");
  
  // Configurar pines de entrada
  pinMode(sensorTempPin, INPUT);
  pinMode(sensorCO2Pin, INPUT);
  pinMode(sensorLuzPin, INPUT);
}

void loop() {
  // Leer todos los sensores
  leerSensores();
  
  // Procesar datos y calcular estado climático
  calcularEstadoClimatico();
  
  // Mostrar resultados
  mostrarInformacion();
  
  delay(2000); // Esperar 2 segundos entre ciclos
}

void leerSensores() {
  // Leer y convertir valores de sensores
  temperatura = map(analogRead(sensorTempPin), 0, 1023, 0, 500) / 10.0;
  nivelCO2 = map(analogRead(sensorCO2Pin), 0, 1023, 300, 2000);
  nivelLuz = map(analogRead(sensorLuzPin), 0, 1023, 0, 100);
}

void calcularEstadoClimatico() {
  // Modelo simple de estado climático
  int puntuacion = 0;
  
  if (temperatura > 28.0) puntuacion += 2;
  else if (temperatura > 25.0) puntuacion += 1;
  
  if (nivelCO2 > 1000) puntuacion += 2;
  else if (nivelCO2 > 800) puntuacion += 1;
  
  if (nivelLuz > 80) puntuacion += 1;
  
  // Determinar estado climático basado en puntuación
  if (puntuacion >= 4) {
    estadoClimatico = 2; // Riesgo
  } else if (puntuacion >= 2) {
    estadoClimatico = 1; // Alerta
  } else {
    estadoClimatico = 0; // Fresco
  }
}

void mostrarInformacion() {
  Serial.println("=== DATOS CLIMÁTICOS ===");
  Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println(" °C");
  Serial.print("CO2: "); Serial.print(nivelCO2); Serial.println(" ppm");
  Serial.print("Luz: "); Serial.print(nivelLuz); Serial.println(" %");
  
  Serial.print("Estado climático: ");
  switch(estadoClimatico) {
    case 0: Serial.println("FRESCO (verde)"); break;
    case 1: Serial.println("ALERTA (amarillo)"); break;
    case 2: Serial.println("RIESGO (rojo)"); break;
  }
  Serial.println("========================");
}
