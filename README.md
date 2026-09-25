# IBIII-Lab1-Acondicionamiento de señales de alta impedancia
Repositorio del Laboratorio 1 del curso de Intrumentación Biomédica III en el cual se realizó un buffer para alta impedancia que ocurren con los electrodos para pH.

## Objetivo

• Identificar experimentalmente el efecto de carga (loading error) al conectar una fuente de alta impedancia a un instrumento de medición.
• Diseñar e implementar un buffer de alta impedancia de entrada utilizando un amplificador operacional con entrada JFET (TL084).
• Comparar el desempeño de un buffer implementado con un amplificador de entrada bipolar (LM324) frente a uno de entrada JFET (TL084).
• Generar, mediante un microcontrolador ESP32, una señal simulada de electrodo de pH en tres puntos de referencia (pH 4, 7 y 10) y usarla para poner a prueba el buffer.

## Cómo reproducir el experimento

1. Cargar el archivo de código .ino en el ESP32 usando el IDE de Arduino (Recuerda colocarlo con board: "ESP32 Dev Module").
2. Armar el circuito siguiendo el esquemático:
   - Etapa 1: GPIO25 del ESP32 directo al osciloscopio.
   - Etapa 2: Simular alta impedancia con R1 = 1 MΩ entre GPIO25 y el punto de medición.
   - Etapa 3: conectar el Nodo A a la entrada no inversora del TL084 (configuración seguidor de voltaje), alimentado con ±9 V. Repetir con el LM324 para comparar.
3. Abrir el Monitor Serial (115200 baudios) e ingresar un valor de pH entre 0 y 14.
4. Medir el voltaje en cada nodo con el multímetro y el osciloscopio, para pH = 4, 7 y 10, y registrar los valores.

## Autores

- Tito Fernandez, Dante Adrian
- Lázaro Canales, Jair Renato
- Arroyo Ramos, Rosbeth Nayelhy
- Sotomayor Villanueva, Genny Solanghe 

