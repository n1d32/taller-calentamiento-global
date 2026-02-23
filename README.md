# Taller: Sistemas Embebidos - De Sensores a Actuadores

Un taller práctico que guía a los participantes a través del proceso completo de diseño e implementación de los denominados "sistemas embebidos". Desde el análisis de componentes hasta la integración de sensores, procesamiento de datos y control de actuadores, este taller proporciona una base sólida en electrónica y programación de microcontroladores.

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

### Actividad central
- Presentar un prototipo funcional que responda a condiciones del entorno
- En grupos, desarmar el dispositivo, identificando "bloques" funcionales (sensores, control, actuadores)
- Elaborar un mapa colectivo en papel: qué hace cada parte y cómo se conecta con las demás

### Metodología
Trabajo colaborativo, diálogo reflexivo sobre "qué pasaría si esta pieza no estuviera"

---

## Sesión 2: Actuadores – comunicando con señales

### Objetivo transversal
Desarrollar la noción de comunicación efectiva: transformar datos en señales comprensibles

### Objetivos específicos
- **Electrónica**: Conectar LEDs monocolores
- **Programación**: Encender el LED integrado y luego modificando el código para cambiar la tasa de parpadeo

### Actividad central
- Cada grupo discute y modifica el código presentado
- Discutir cómo crear y controlar las variables que definen la tasa de parpadeo del LED
- Crear una variable global que controle todos los LED

### Metodología
Aprendizaje cooperativo, prueba y error, acompañamiento cercano por parte de guías

---

## Sesión 3: Sensores – escuchando al entorno

### Objetivo transversal
Desarrollar la capacidad de observación y medición de variables del entorno

### Objetivos específicos
- **Electrónica**: Conectar y probar sensores básicos (ej: potenciómetros para simulación, sensores de temperatura, luz, etc.)
- **Programación**: Escribir un código sencillo que lea un sensor y muestre datos en el monitor serial

### Actividad central
Cada grupo trabaja con un tipo de sensor distinto, lo conecta y observa cómo cambia el valor al modificar las condiciones (ej: variar un potenciómetro, cambiar la iluminación)

### Metodología
Rotación de estaciones, donde cada grupo experimenta con distintos sensores; cierre colectivo con puesta en común

---

## Sesión 4: Procesando la información – el "cerebro"

### Objetivo transversal
Comprender cómo se pueden combinar múltiples datos en indicadores significativos

### Objetivos específicos
- **Electrónica**: Entender el rol de la placa controladora como "puente" entre sensores y actuadores
- **Programación**: Programar operaciones básicas sobre datos de sensores (ej: promedio, suma ponderada, mapeo de valores)

### Actividad central
- Implementar un modelo simplificado: combinar lecturas de múltiples sensores para calcular un "estado del sistema"
- Ver cómo la combinación de factores da lugar a un índice único que representa el estado general

### Metodología
Dinámica de metáforas ("el cerebro toma decisiones según lo que escucha de sus sentidos"), ejercicios prácticos con ejemplos

---


## Sesión 5: Reconstrucción colectiva del sistema

### Objetivo transversal
Practicar el trabajo en equipo y la integración de componentes en un sistema funcional

### Objetivos específicos
- **Electrónica**: Integrar sensores, placa controladora y actuadores en un prototipo funcional
- **Programación**: Integrar lecturas múltiples en un código coherente que calcule estados y controle actuadores

### Actividad central
- En equipos, integrar progresivamente los componentes hasta tener un sistema operativo completo
- Comparar el resultado con el mapa conceptual creado en la primera sesión

### Metodología
Trabajo colaborativo, con roles repartidos (armado físico, conexiones, codificación, testing)

---

## Sesión 6: Modificaciones creativas y presentación final

### Objetivo transversal
Desarrollar creatividad y autonomía para modificar y mejorar sistemas existentes

### Objetivos específicos
- **Electrónica**: Implementar modificaciones físicas opcionales (ej: añadir actuadores adicionales, sensores extra)
- **Programación**: Implementar mejoras en el código (ej: modos especiales, logging de datos, interfaces adicionales)

### Actividad central
- Cada grupo propone y desarrolla una mejora o variación al sistema base
- Presentación de resultados al resto, con reflexión sobre el proceso de diseño y aprendizaje

### Metodología
Feria creativa, intercambio horizontal, reflexión crítica sobre el proceso de aprendizaje

---

## Sesión 7: Conexión y control remoto (Bonus)

### Objetivo transversal
Explorar conceptos avanzados de conectividad y control distribuido

### Objetivos específicos
- **Electrónica**: Configurar conexión WiFi y servidor web embebido
- **Programación**: Implementar una API REST básica y interfaz web para control remoto

### Actividad central
- Conectar el sistema a una red WiFi local
- Desarrollar una interfaz web simple para monitorear y controlar el sistema remotamente
- Experimentar con el control del sistema desde diferentes dispositivos

### Metodología
Demostración guiada, experimentación práctica, discusión sobre aplicaciones reales

---

## Materiales necesarios para las 7 sesiones

### Sesión 1: Desarmando el sistema
- Prototipo funcional pre-ensamblado (1 por grupo)
- Herramientas básicas (destornilladores, pinzas)
- Papel y materiales para diagramación

### Sesión 2: Sensores
- Placas Arduino/ESP32 (1 por grupo)
- Potenciómetros (3-4 por grupo, para simular diferentes tipos de sensores)
- Cables jumper (conjunto suficiente para conexiones)
- Protoboards (1 por grupo)
- Computadoras con Arduino IDE instalado
- Cables USB para programación

### Sesión 3: Procesamiento de información
- Placas Arduino/ESP32 (1 por grupo)
- Potenciómetros (3 por grupo, para simular múltiples sensores)
- Cables jumper
- Protoboards (1 por grupo)
- Computadoras con Arduino IDE
- Cables USB

### Sesión 4: Actuadores
- Placas Arduino/ESP32 (1 por grupo)
- LEDs monocolores (rojo, amarillo, verde - 1 de cada por grupo)
- LED RGB (1 por grupo)
- Resistencias 220Ω (4 por grupo: 3 para LEDs monocolores, 1 para RGB)
- Potenciómetros (1-2 por grupo, para simular entradas de sensor)
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
