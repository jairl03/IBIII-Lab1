// Definición de pines
const int pinDAC = 25; // Salida DAC del ESP32

// Parámetros de la Ecuación de Nernst simulada
// A pH 7, el voltaje base suele ser la mitad de la escala (1.65V) o se diseña una referencia.
// Usaremos la relación estándar centrada en 1.65V para pH 7:
const float V_REF_NEUTRAL = 1.65; // Voltaje para pH 7
const float PENDIENTE_NERNST = 0.05916; // V por unidad de pH (a 25°C)

void setup() {
  // Inicializar comunicación serial
  Serial.begin(115200);
  while (!Serial); // Esperar conexión serie

  Serial.println("=== LABORATORIO 1: Acondicionamiento de Señales de Alta Impedancia ===");
  Serial.println("Simulador de Electrodo de pH con ESP32");
  Serial.println("Ingrese un valor de pH entre 0 y 14:");
}

void loop() {
  if (Serial.available() > 0) {
    // Leer el valor de pH ingresado
    float pH = Serial.parseFloat();

    // Limpiar buffer serie
    while (Serial.available() > 0) {
      Serial.read();
    }

    // Limitar el rango del pH a los límites físicos lógicos (0 - 14)
    if (pH < 0.0) pH = 0.0;
    if (pH > 14.0) pH = 14.0;

    // Aplicar la ecuación de Nernst centrada en pH 7 = 1.65V
    // Fórmula: V = V_neutral - (pendiente * (pH - 7))
    // Nota: El signo negativo indica que a mayor pH, menor potencial en electrodos típicos de vidrio.
    float voltajeTeorico = V_REF_NEUTRAL - (PENDIENTE_NERNST * (pH - 7.0));

    // Asegurar que el voltaje esté dentro de los límites del DAC del ESP32 (0V a 3.3V)
    if (voltajeTeorico < 0.0) voltajeTeorico = 0.0;
    if (voltajeTeorico > 3.3) voltajeTeorico = 3.3;

    // Convertir el voltaje a un código digital de 8 bits (0 a 255) para el DAC
    int codigo8bits = (int)((voltajeTeorico / 3.3) * 255);

    // Escribir la señal analógica en el pin GPIO25
    dacWrite(pinDAC, codigo8bits);

    // Mostrar los resultados en el Monitor Serial para el registro de la Tabla 1
    Serial.print("pH Ingresado: ");
    Serial.print(pH, 2);
    Serial.print("  |  Voltaje Teórico (DAC): ");
    Serial.print(voltajeTeorico, 4);
    Serial.print(" V  |  Código DAC (0-255): ");
    Serial.println(codigo8bits);
  }
}