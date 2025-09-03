// Sesión 5: Reconstrucción colectiva de la casa
// Ejemplo básico - Sistema integrado completo

// Sensores
const int sensorTempPin = A0;    // Temperatura
const int sensorCO2Pin = A1;     // CO2 (simulado)
const int sensorLuzPin = A2;     // Luz (simulado)

// Actuadores (LEDs)
const int ledVerde = 9;
const int ledAmarillo = 10;
const int ledRojo = 11;

// Variables del sistema
float temperatura;
int nivelCO2;
int nivelLuz;
int estadoClimatico; // 0 = fresco, 1 = alerta, 2 = riesgo

// Umbrales para el modelo climático
const float TEMP_ALERTA = 25.0;
const float TEMP_RIESGO = 30.0;
const int CO2_ALERTA = 800;
const int CO2_RIESGO = 1000;
const int LUZ_ALERTA = 70;

void setup() {
  Serial.begin(9600);
  Serial.println("=== SISTEMA CASA INTEGRADO ===");
  Serial.println("Reconstrucción completa del sistema");
  
  // Configurar pines de entrada (sensores)
  pinMode(sensorTempPin, INPUT);
  pinMode(sensorCO2Pin, INPUT);
  pinMode(sensorLuzPin, INPUT);
  
  // Configurar pines de salida (actuadores)
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  // Estado inicial
  apagarLEDs();
  Serial.println("Sistema listo para monitoreo climático");
  Serial.println("=====================================");
}

void loop() {
  // Fase 1: Lectura de sensores
  leerTodosLosSensores();
  
  // Fase 2: Procesamiento de datos
  calcularEstadoClimatico();
  
  // Fase 3: Actuación (control de LEDs)
  controlarIluminacion();
  
  // Fase 4: Monitoreo y feedback
  mostrarEstadoSistema();
  
  delay(2000); // Ciclo cada 2 segundos
}

void leerTodosLosSensores() {
  // Leer todos los sensores del sistema
  temperatura = map(analogRead(sensorTempPin), 0, 1023, 0, 500) / 10.0;
  nivelCO2 = map(analogRead(sensorCO2Pin), 0, 1023, 300, 2000);
  nivelLuz = map(analogRead(sensorLuzPin), 0, 1023, 0, 100);
}

void calcularEstadoClimatico() {
  // Modelo integrado de evaluación climática
  int puntuacionTotal = 0;
  
  // Evaluar temperatura
  if (temperatura > TEMP_RIESGO) puntuacionTotal += 3;
  else if (temperatura > TEMP_ALERTA) puntuacionTotal += 2;
  else if (temperatura > 20.0) puntuacionTotal += 1;
  
  // Evaluar CO2
  if (nivelCO2 > CO2_RIESGO) puntuacionTotal += 3;
  else if (nivelCO2 > CO2_ALERTA) puntuacionTotal += 2;
  else if (nivelCO2 > 500) puntuacionTotal += 1;
  
  // Evaluar luz
  if (nivelLuz > LUZ_ALERTA) puntuacionTotal += 1;
  
  // Determinar estado final
  if (puntuacionTotal >= 5) {
    estadoClimatico = 2; // Riesgo
  } else if (puntuacionTotal >= 3) {
    estadoClimatico = 1; // Alerta
  } else {
    estadoClimatico = 0; // Fresco
  }
}

void controlarIluminacion() {
  // Control integrado de todos los LEDs
  apagarLEDs();
  
  switch(estadoClimatico) {
    case 0: // Fresco - Verde estable
      digitalWrite(ledVerde, HIGH);
      break;
      
    case 1: // Alerta - Amarillo parpadeante
      parpadearLED(ledAmarillo, 3, 200);
      break;
      
    case 2: // Riesgo - Rojo parpadeante rápido
      parpadearLED(ledRojo, 5, 100);
      break;
  }
}

void mostrarEstadoSistema() {
  Serial.println("\n--- MONITOREO EN TIEMPO REAL ---");
  Serial.print("Temperatura: "); Serial.print(temperatura); Serial.println(" °C");
  Serial.print("CO₂: "); Serial.print(nivelCO2); Serial.println(" ppm");
  Serial.print("Luz: "); Serial.print(nivelLuz); Serial.println(" %");
  
  Serial.print("Estado climático: ");
  switch(estadoClimatico) {
    case 0: Serial.println("FRESCO ✅"); break;
    case 1: Serial.println("ALERTA ⚠️"); break;
    case 2: Serial.println("RIESGO 🔴"); break;
  }
  Serial.println("--------------------------------");
}

void apagarLEDs() {
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
}

void parpadearLED(int pin, int veces, int duracion) {
  for (int i = 0; i < veces; i++) {
    digitalWrite(pin, HIGH);
    delay(duracion);
    digitalWrite(pin, LOW);
    if (i < veces - 1) delay(duracion);
  }
}
