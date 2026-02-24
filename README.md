# Taller: Sistemas Embebidos - De Sensores a Actuadores

Un taller práctico que guía a los participantes a través del proceso completo de diseño e implementación de sistemas embebidos. Desde el análisis de componentes hasta la integración de sensores, procesamiento de datos y control de actuadores, este taller proporciona una base sólida en electrónica y programación de microcontroladores.

El taller está diseñado como un framework genérico que puede adaptarse a múltiples temáticas (monitoreo ambiental, automatización, robótica, etc.), permitiendo a los instructores personalizar el contenido según sus necesidades específicas.

---

## Objetivos

- **Visualizar** de forma tangible cómo un sistema complejo puede descomponerse en componentes manejables
- **Enseñar** los fundamentos de medición y procesamiento de señales usando sensores y microcontroladores
- **Aprender** conceptos de programación y electrónica observando consecuencias inmediatas y tangibles de las decisiones de diseño
- **Desarrollar** habilidades de pensamiento sistémico, trabajo en equipo y resolución de problemas técnicos

---

# Calendarización
- 6 sesiones de 45 min o 3 sesiones de 90 minutos

---

## Sesión 1: Desarmando el sistema

### Objetivos transversales
- Comprender que un problema complejo puede analizarse en partes más simples (pensamiento analítico/sintético).
- Imaginar analogías entre sistemas como sensor - procesamiento - actuador versus sentidos - cerebro - movimiento.

### Objetivos específicos
- **Electrónica**: Reconocer los componentes físicos: sensores, actuadores, placa Arduino/ESP32, cables, resistencias
- **Programación**: Reconocer que el funcionamiento está gobernado por un código que conecta entradas (sensores) con salidas (actuadores)

### Implementación práctica
El código de esta sesión implementa un sistema interactivo LED-botón donde:
- Un LED se enciende y apaga en intervalos aleatorios
- Los participantes deben presionar un botón solo cuando el LED está encendido
- El sistema proporciona feedback visual cuando se presiona incorrectamente
- Se implementa debounce para manejar ruido en las entradas del botón

### Conceptos técnicos cubiertos
- Control de LEDs digitales
- Lectura de entradas digitales con debounce
- Estados del sistema y manejo de feedback
- Comunicación serial para monitoreo

### Actividad central
- Presentar un prototipo funcional que responda a condiciones del entorno
- En grupos, desarmar el dispositivo, identificando "bloques" funcionales (sensores, control, actuadores)
- Elaborar un mapa colectivo en papel: qué hace cada parte y cómo se conecta con las demás

### Metodología
Trabajo colaborativo, diálogo reflexivo sobre "qué pasaría si esta pieza no estuviera"

### Resultado esperado
Los participantes comprenden la relación entre código y hardware, identificando cómo las decisiones de programación afectan el comportamiento físico del sistema.

---

## Sesión 2: Actuadores – comunicando con señales

### Objetivo transversal
Desarrollar la noción de comunicación efectiva: transformar datos en señales comprensibles

### Objetivos específicos
- **Electrónica**: Conectar LEDs monocolores
- **Programación**: Encender el LED integrado y modificar el código para cambiar la tasa de parpadeo

### Implementación práctica
El código de esta sesión implementa un sistema básico de control de LED donde:
- Se controla un LED integrado en la placa ESP32
- Los participantes modifican variables para cambiar el comportamiento
- Se introducen diferentes tipos de variables (int, char, etc.)
- Se muestra cómo asignar valores y usar constantes

### Conceptos técnicos cubiertos
- Configuración de pines como salida
- Control digital HIGH/LOW
- Uso de variables y constantes
- Comunicación serial para depuración
- Temporización con delay()

### Actividad central
- Cada grupo discute y modifica el código presentado
- Discutir cómo crear y controlar las variables que definen la tasa de parpadeo del LED
- Crear una variable global que controle todos los LED

### Metodología
Aprendizaje cooperativo, prueba y error, acompañamiento cercano por parte de guías

### Resultado esperado
Los participantes comprenden cómo el código controla dispositivos físicos y cómo modificar variables afecta el comportamiento del sistema.

---

## Sesión 3: Sensores – escuchando al entorno

### Objetivo transversal
Desarrollar la capacidad de observación y medición de variables del entorno

### Objetivos específicos
- **Electrónica**: Conectar y probar sensores básicos (ej: potenciómetros para simulación, sensores de temperatura, luz, etc.)
- **Programación**: Escribir un código sencillo que lea un sensor y muestre datos en el monitor serial

### Implementación práctica
El código de esta sesión implementa un sistema modular donde:
- Se lee el estado de un botón como entrada digital
- Se controla un LED con tiempos configurables
- Se introduce la modularización del código en funciones
- Se practica la documentación y comentarios del código

### Conceptos técnicos cubiertos
- Lectura de entradas digitales con pull-up interno
- Modularización del código en funciones
- Documentación y comentarios
- Comunicación serial para mostrar estados
- Separación de responsabilidades en el código

### Actividad central
Cada grupo trabaja con un tipo de sensor distinto, lo conecta y observa cómo cambia el valor al modificar las condiciones (ej: variar un potenciómetro, cambiar la iluminación)

### Metodología
Rotación de estaciones, donde cada grupo experimenta con distintos sensores; cierre colectivo con puesta en común

### Resultado esperado
Los participantes aprenden a leer entradas del entorno y estructurar su código de manera modular y documentada.

---

## Sesión 4: Procesando la información – el "cerebro"

### Objetivo transversal
Comprender cómo se pueden combinar múltiples datos en indicadores significativos

### Objetivos específicos
- **Electrónica**: Entender el rol de la placa controladora como "puente" entre sensores y actuadores
- **Programación**: Programar operaciones básicas sobre datos de sensores (ej: promedio, suma ponderada, mapeo de valores)

### Implementación práctica
El código de esta sesión implementa un sistema de monitoreo ambiental donde:
- Se leen datos de temperatura y humedad usando un sensor DHT11
- Se procesan los datos para crear un modelo simplificado
- Se validan las lecturas del sensor
- Se muestran los datos procesados en el monitor serial

### Conceptos técnicos cubiertos
- Uso de bibliotecas externas (DHT)
- Lectura de sensores analógicos/digitales
- Procesamiento de datos (operaciones matemáticas)
- Validación de lecturas de sensores
- Formateo de salida serial

### Actividad central
- Implementar un modelo simplificado: combinar lecturas de múltiples sensores para calcular un "estado del sistema"
- Ver cómo la combinación de factores da lugar a un índice único que representa el estado general

### Metodología
Dinámica de metáforas ("el cerebro toma decisiones según lo que escucha de sus sentidos"), ejercicios prácticos con ejemplos

### Resultado esperado
Los participantes comprenden cómo procesar datos de sensores para tomar decisiones y crear indicadores significativos.

---

## Sesión 5: Reconstrucción colectiva del sistema

### Objetivo transversal
Practicar el trabajo en equipo y la integración de componentes en un sistema funcional

### Objetivos específicos
- **Electrónica**: Integrar sensores, placa controladora y actuadores en un prototipo funcional
- **Programación**: Integrar lecturas múltiples en un código coherente que calcule estados y controle actuadores

### Implementación práctica
El código de esta sesión integra conceptos anteriores en un sistema completo donde:
- Se combina control de LED con lectura de botón
- Se implementa un sistema de feedback visual
- Se manejan múltiples estados del sistema
- Se integra debounce y temporización

### Conceptos técnicos cubiertos
- Integración de múltiples componentes
- Manejo de estados del sistema
- Feedback visual al usuario
- Temporización y control de flujo
- Integración de entradas y salidas

### Actividad central
- En equipos, integrar progresivamente los componentes hasta tener un sistema operativo completo
- Comparar el resultado con el mapa conceptual creado en la primera sesión

### Metodología
Trabajo colaborativo, con roles repartidos (armado físico, conexiones, codificación, testing)

### Resultado esperado
Los participantes integran todos los conceptos aprendidos en un sistema funcional completo, comprendiendo cómo interactúan los diferentes componentes.

---

## Sesión 6: Modificaciones creativas y presentación final

### Objetivo transversal
Desarrollar creatividad y autonomía para modificar y mejorar sistemas existentes

### Objetivos específicos
- **Electrónica**: Implementar modificaciones físicas opcionales (ej: añadir actuadores adicionales, sensores extra)
- **Programación**: Implementar mejoras en el código (ej: modos especiales, logging de datos, interfaces adicionales)

### Implementación práctica
El código de esta sesión presenta un sistema extendido con mejoras creativas donde:
- Se monitorean múltiples sensores (temperatura, CO2, luz)
- Se controlan múltiples actuadores (LEDs, buzzer, ventilador)
- Se implementan mejoras como ventilación automática y alarmas
- Se incluye un sistema de reset manual
- Se realiza monitoreo avanzado con estadísticas

### Conceptos técnicos cubiertos
- Sistemas multi-sensor
- Control de múltiples actuadores
- Implementación de mejoras creativas
- Monitoreo y logging avanzado
- Interacción del usuario
- Manejo de condiciones críticas

### Actividad central
- Cada grupo propone y desarrolla una mejora o variación al sistema base
- Presentación de resultados al resto, con reflexión sobre el proceso de diseño y aprendizaje

### Metodología
Feria creativa, intercambio horizontal, reflexión crítica sobre el proceso de aprendizaje

### Resultado esperado
Los participantes aplican creativamente los conceptos aprendidos, proponiendo y desarrollando mejoras al sistema base.

---

## Sesión 7: Conexión y control remoto (Bonus)

### Objetivo transversal
Explorar conceptos avanzados de conectividad y control distribuido

### Objetivos específicos
- **Electrónica**: Configurar conexión WiFi y servidor web embebido
- **Programación**: Implementar una API REST básica y interfaz web para control remoto

### Implementación práctica
El código de esta sesión implementa un sistema de control remoto donde:
- Se configura conexión WiFi a una red local
- Se implementa un servidor web embebido en el ESP32
- Se crea una API REST para consultar y actualizar estados
- Se manejan headers CORS para permitir acceso desde interfaces web
- Se controlan variables del sistema remotamente

### Conceptos técnicos cubiertos
- Configuración de conexión WiFi
- Implementación de servidor web embebido
- API REST básica (GET, POST, OPTIONS)
- Manejo de headers CORS
- Control remoto de variables del sistema
- Integración con interfaces web

### Actividad central
- Conectar el sistema a una red WiFi local
- Desarrollar una interfaz web simple para monitorear y controlar el sistema remotamente
- Experimentar con el control del sistema desde diferentes dispositivos

### Metodología
Demostración guiada, experimentación práctica, discusión sobre aplicaciones reales

### Resultado esperado
Los participantes comprenden cómo extender sistemas embebidos con conectividad, permitiendo control y monitoreo remoto.

---

## Materiales necesarios para las 7 sesiones

### Sesión 1: Desarmando el sistema
- Prototipo funcional pre-ensamblado (1 por grupo)
- Herramientas básicas (destornilladores, pinzas)
- Papel y materiales para diagramación

### Sesión 2: Actuadores
- Placas Arduino/ESP32 (1 por grupo)
- LEDs monocolores (rojo, amarillo, verde - 1 de cada por grupo)
- LED RGB (1 por grupo)
- Resistencias 220Ω (4 por grupo: 3 para LEDs monocolores, 1 para RGB)
- Cables jumper (conjunto suficiente para conexiones)
- Protoboards (1 por grupo)
- Computadoras con Arduino IDE instalado
- Cables USB para programación

### Sesión 3: Sensores
- Placas Arduino/ESP32 (1 por grupo)
- Potenciómetros (3-4 por grupo, para simular diferentes tipos de sensores)
- Sensores básicos (temperatura, luz, etc. según disponibilidad)
- Cables jumper
- Protoboards (1 por grupo)
- Computadoras con Arduino IDE
- Cables USB

### Sesión 4: Procesamiento de información
- Placas Arduino/ESP32 (1 por grupo)
- Sensores DHT11 (temperatura y humedad)
- Potenciómetros (2-3 por grupo, para simulación adicional)
- Cables jumper
- Protoboards (1 por grupo)
- Computadoras con Arduino IDE
- Cables USB

### Sesión 5: Reconstrucción colectiva
- Todos los componentes de sesiones anteriores
- Materiales para estructura/carcasa (opcional)
- Herramientas de montaje

### Sesión 6: Modificaciones creativas
- Componentes adicionales opcionales (buzzers, motores, sensores extra, etc.)
- Materiales para modificaciones físicas
- Computadoras para desarrollo de código

### Sesión 7: Conexión y control remoto (Bonus)
- Placas ESP32 con WiFi (1 por grupo)
- Router WiFi con acceso a Internet
- Computadoras con navegador web
- Smartphones/tablets para testing (opcional)

---

## Notas para instructores

Este taller está diseñado como un framework adaptable. Para personalizarlo a una temática específica:

1. **Definir el contexto**: ¿Qué sistema se está monitoreando/controlando? (ej: invernadero, estación meteorológica, sistema de riego)
2. **Seleccionar sensores apropiados**: Elegir sensores relevantes para la temática
3. **Definir lógica de procesamiento**: ¿Cómo se interpretan los datos? ¿Qué estados/alertas son relevantes?
4. **Elegir actuadores significativos**: ¿Qué feedback/acciones son apropiadas para el contexto?
5. **Preparar ejemplos contextualizados**: Adaptar los ejemplos de código y actividades a la temática

La estructura pedagógica y los objetivos de aprendizaje permanecen consistentes, permitiendo reutilizar el mismo material base con diferentes aplicaciones.
