# Taller: Casa víctima del calentamiento global

Sensores que monitorean y regulan parámetros básicos asociados al calentamiento global. Un modelo sencillo calcula el aumento de temperatura resultante de la combinación de estos parámetros y, en función del nivel de calor alcanzado, activa una luz verde, amarilla o roja. La luz se proyecta al interior de una vivienda, de modo que esta se ilumina con el color correspondiente, generando la impresión de que las personas en su interior se están sobrecalentando.

---

## Objetivos

- **Visualizar** de forma emocional e inmediata cómo distintas variables contribuyen al "calentamiento" de un sistema cerrado
- **Enseñar** a medir y combinar señales ambientales (temperatura, CO₂, radiación, consumo) en un modelo simple de "estado climático"
- **Aprender** elementos tanto de programación como de sistemas complejos observando una consecuencia tangible e inmediata, como la alerta visual (verde/amarilla/roja) que actúa como señal de riesgo
- **Generar conciencia** sobre la suma de factores y cómo pequeñas acciones (ventilación, consumo energético, etc.) modifican el balance térmico

---

## Sesión 1: Desarmando la "casa"

### Objetivo transversal
Comprender que un problema complejo puede analizarse en partes más simples (pensamiento analítico/sintético)

### Objetivos específicos
- **Electrónica**: Reconocer los componentes físicos: sensores, luces LED, placa Arduino/ESP32, cables, resistencias
- **Programación**: Reconocer que el funcionamiento está gobernado por un código que conecta entradas (sensores) con salidas (luces)

### Actividad central
- Presentar la maqueta de la casa iluminándose según condiciones ambientales
- En grupos, desarmar el dispositivo, identificando "bloques" (sensores, control, actuadores)
- Elaborar un mapa colectivo en papel: qué hace cada parte y cómo se conecta con las demás

### Metodología
Trabajo colaborativo, diálogo reflexivo sobre "qué pasaría si esta pieza no estuviera"

---

## Sesión 2: Sensores – escuchando al entorno

### Objetivo transversal
Desarrollar la capacidad de observación y medición de variables invisibles (ver lo oculto)

### Objetivos específicos
- **Electrónica**: Conectar y probar sensores básicos (ej: temperatura, CO₂, luz, consumo eléctrico simulado)
- **Programación**: Escribir un código sencillo que lea un sensor y muestre datos en el monitor serial

### Actividad central
Cada grupo trabaja con un sensor distinto, lo conecta y observa cómo cambia el valor al modificar el entorno (ej: calentar con la mano, encender un fósforo para CO₂)

### Metodología
Rotación de estaciones, donde cada grupo experimenta con distintos sensores; cierre colectivo con puesta en común

---

## Sesión 3: Procesando la información – el "cerebro"

### Objetivo transversal
Comprender cómo se pueden simplificar muchos datos en una sola idea o índice (modelar la realidad)

### Objetivos específicos
- **Electrónica**: Entender el rol de la placa controladora como "puente" entre sensores y actuadores
- **Programación**: Programar operaciones básicas sobre datos de sensores (ej: promedio, suma ponderada)

### Actividad central
- Probar un modelo simplificado: si la temperatura es >X y el CO₂ >Y, el "estado" sube
- Ver cómo la combinación de factores da lugar a un índice único (ej: 0 = fresco, 1 = alerta, 2 = riesgo)

### Metodología
Dinámica de metáforas ("el cerebro toma decisiones según lo que escucha de sus sentidos"), ejercicios prácticos con ejemplos

---

## Sesión 4: Actuadores – hablando con señales

### Objetivo transversal
Desarrollar la noción de comunicación: del dato invisible a la señal comprensible

### Objetivos específicos
- **Electrónica**: Conectar LEDs de tres colores y aprender cómo se controlan desde la placa
- **Programación**: Programar condicionales ("if") para encender luces según el índice climático

### Actividad central
- Cada grupo hace un pequeño programa que encienda un LED según el valor leído de un sensor
- Avanzar hacia que se ilumine la casa completa con verde/amarillo/rojo

### Metodología
Aprendizaje cooperativo, prueba y error, acompañamiento cercano por parte de guías

---

## Sesión 5: Reconstrucción colectiva de la casa

### Objetivo transversal
Practicar el trabajo en equipo y la construcción conjunta de un sistema complejo

### Objetivos específicos
- **Electrónica**: Integrar sensores, placa y LEDs en una sola maqueta funcional
- **Programación**: Integrar lecturas múltiples en un código que calcule el estado climático y encienda la señal correspondiente

### Actividad central
- En equipos, ir uniendo piezas del sistema hasta volver a tener la casa operativa
- Comparar con el mapa hecho en la primera sesión

### Metodología
Trabajo colaborativo, con roles repartidos (armado físico, conexiones, codificación)

---

## Sesión 6: Modificaciones creativas y presentación final

### Objetivo transversal
Desarrollar creatividad y autonomía para modificar y mejorar lo aprendido

### Objetivos específicos
- **Electrónica**: Implementar un cambio físico opcional (ej: añadir un ventilador, un buzzer, un sensor extra)
- **Programación**: Implementar un cambio en el código (ej: que parpadee en rojo cuando pasa cierto umbral, o que registre máximos)

### Actividad central
- Cada grupo propone y desarrolla una pequeña mejora o variación
- Presentación de resultados al resto, con reflexión final sobre el impacto de sus cambios en la "casa" y el clima

### Metodología
Feria creativa, intercambio horizontal, reflexión crítica sobre el aprendizaje y el problema socioambiental
