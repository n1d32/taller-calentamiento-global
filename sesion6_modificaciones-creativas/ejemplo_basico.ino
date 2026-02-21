// Sesión 6: Modificaciones creativas y presentación final
// Ejemplo básico - Sistema extendido con mejoras creativas

// Sensores base
const int sensorTempPin = A0;
const int sensorCO2Pin = A1;
const int sensorLuzPin = A2;

// Actuadores base (LEDs)
const int ledVerde = 9;
const int ledAmarillo = 10;
const int ledRojo = 11;

// Mejoras creativas (componentes adicionales)
const int buzzerPin = 6;          // Buzzer para alertas sonoras
const int ventiladorPin = 5;      // Ventilador para enfriamiento
const int botonResetPin = 2;      // Botón para reset manual

// Variables del sistema
float temperatura;
int nivelCO2;
int nivelLuz;
int estadoClimatico;
unsigned long ultimoCambio = 0;
bool alarmaActiva = false;
float temperaturaMaxima = 0;
int lecturasRiesgo = 0;

// Configuración de umbrales
const float TEMP_ALERTA = 25.0;
const float TEMP_RIESGO = 30.0;
const int CO2_RIESGO = 1000;
const int LUZ_ALERTA = 70;

void setup() {
  Serial.begin(9600);
  Serial.println("=== SISTEMA MEJORADO - MODIFICACIONES CREATIVAS ===");
  
  // Configurar pines base
  pinMode(sensorTempPin, INPUT);
  pinMode(sensorCO2Pin, INPUT);
  pinMode(sensorLuzPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  // Configurar mejoras creativas
  pinMode(buzzerPin, OUTPUT);
  pinMode(ventiladorPin, OUTPUT);
  pinMode(botonResetPin, INPUT_PULLUP);
  
  // Estado inicial
  apagarTodo();
  Serial.println("Sistema mejorado listo - ¡Modo creativo activado!");
  Serial.println("================================================");
}

void loop() {
  // Leer sensores
  leerSensores();
  
  // Procesar datos y calcular estado
  calcularEstado();
  
  // Aplicar mejoras creativas
  aplicarMejorasCreativas();
  
  // Controlar actuadores principales
  controlarActuadores();
  
  // Monitoreo avanzado
  monitoreoAvanzado();
  
  // Manejar interacción del usuario
  manejarBotonReset();
  
  delay(1000);
}

void leerSensores() {
  temperatura = map(analogRead(sensorTempPin), 0, 1023, 0, 500) / 10.0;
  nivelCO2 = map(analogRead(sensorCO2Pin), 0, 1023, 300, 2000);
  nivelLuz = map(analogRead(sensorLuzPin), 0, 1023, 0, 100);
  
  // Registrar temperatura máxima
  if (temperatura > temperaturaMaxima) {
    temperaturaMaxima = temperatura;
  }
}

void calcularEstado() {
  int puntuacion = 0;
  
  if (temperatura > TEMP_RIESGO) puntuacion += 3;
  else if (temperatura > TEMP_ALERTA) puntuacion += 2;
  
  if (nivelCO2 > CO2_RIESGO) puntuacion += 2;
  if (nivelLuz > LUZ_ALERTA) puntuacion += 1;
  
  int estadoAnterior = estadoClimatico;
  
  if (puntuacion >= 4) estadoClimatico = 2;
  else if (puntuacion >= 2) estadoClimatico = 1;
  else estadoClimatico = 0;
  
  // Registrar cambio de estado
  if (estadoClimatico != estadoAnterior) {
    ultimoCambio = millis();
    Serial.print("Cambio de estado: ");
    Serial.println(estadoClimatico);
  }
  
  // Contar lecturas en estado riesgo
  if (estadoClimatico == 2) {
    lecturasRiesgo++;
  }
}

void aplicarMejorasCreativas() {
  // MEJORA 1: Ventilador automático en temperaturas altas
  if (temperatura > 28.0) {
    digitalWrite(ventiladorPin, HIGH);
    Serial.println("Ventilador activado - Enfriando sistema");
  } else {
    digitalWrite(ventiladorPin, LOW);
  }
  
  // MEJORA 2: Alarma sonora en estado riesgo prolongado
  if (estadoClimatico == 2 && millis() - ultimoCambio > 10000) {
    activarAlarma();
  } else {
    desactivarAlarma();
  }
  
  // MEJORA 3: Parpadeo especial según condiciones específicas
  if (temperatura > TEMP_RIESGO && nivelCO2 > CO2_RIESGO) {
    // Condición crítica - parpadeo rápido de ambos LEDs
    parpadearCritico();
  }
}

void controlarActuadores() {
  apagarLEDs();
  
  switch(estadoClimatico) {
    case 0:
      digitalWrite(ledVerde, HIGH);
      break;
    case 1:
      parpadearLED(ledAmarillo, 2, 300);
      break;
    case 2:
      parpadearLED(ledRojo, 4, 150);
      break;
  }
}

void monitoreoAvanzado() {
  Serial.println("\n--- MONITOREO AVANZADO ---");
  Serial.print("Temp: "); Serial.print(temperatura); Serial.print("°C");
  Serial.print(" | CO2: "); Serial.print(nivelCO2); Serial.print("ppm");
  Serial.print(" | Luz: "); Serial.print(nivelLuz); Serial.println("%");
  
  Serial.print("Estado: ");
  switch(estadoClimatico) {
    case 0: Serial.print("Fresco"); break;
    case 1: Serial.print("Alerta"); break;
    case 2: Serial.print("RIESGO"); break;
  }
  
  Serial.print(" | Temp max: "); Serial.print(temperaturaMaxima); Serial.println("°C");
  Serial.print("Alertas riesgo: "); Serial.println(lecturasRiesgo);
  Serial.println("----------------------------");
}

void manejarBotonReset() {
  if (digitalRead(botonResetPin) == LOW) {
    delay(50); // Debounce
    if (digitalRead(botonResetPin) == LOW) {
      resetSistema();
      while (digitalRead(botonResetPin) == LOW); // Esperar a soltar
    }
  }
}

void resetSistema() {
  temperaturaMaxima = 0;
  lecturasRiesgo = 0;
  Serial.println("=== SISTEMA REINICIADO ===");
  Serial.println("Estadísticas limpiadas");
}

void activarAlarma() {
  if (!alarmaActiva) {
    tone(buzzerPin, 1000, 500);
    alarmaActiva = true;
    Serial.println("ALARMA ACTIVADA - Condición crítica prolongada!");
  }
}

void desactivarAlarma() {
  if (alarmaActiva) {
    noTone(buzzerPin);
    alarmaActiva = false;
  }
}

void parpadearCritico() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledAmarillo, HIGH);
    delay(100);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAmarillo, LOW);
    delay(100);
  }
}

void apagarTodo() {
  apagarLEDs();
  digitalWrite(ventiladorPin, LOW);
  noTone(buzzerPin);
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
