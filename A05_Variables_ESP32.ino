/*
 * A05 - Programación ESP32 - Variables en C++
 * Explicación de tipos de variables mediante ejemplos prácticos
 */

// =============================================
// SECCIÓN 1: VARIABLES CONSTANTES (NO CAMBIAN)
// =============================================

// const - Valor que NO cambia durante la ejecución
// BUENA PRÁCTICA: Nombres en MAYÚSCULAS para constantes
const int PIN_LED = 2;           // Pin GPIO donde está conectado el LED
const float VOLTAJE_REF = 3.3;   // Voltaje de referencia del ESP32
const String NOMBRE_DISPOSITIVO = "ESP32-WROOM"; // Texto constante

// =============================================
// SECCIÓN 2: VARIABLES ENTERAS (int, long)
// =============================================

// int - Números enteros de -32,768 a 32,767 (2 bytes)
int contadorCiclos = 0;          // Contador de ciclos del loop
int velocidadSerial = 115200;    // Velocidad comunicación serie

// long - Números enteros muy grandes (4 bytes)
long tiempoInicio = 0;           // Tiempo cuando empezó el programa
long milisegundosTranscurridos = 0;

// =============================================
// SECCIÓN 3: VARIABLES CON DECIMALES (float)
// =============================================

// float - Números con decimales (4 bytes)
float temperatura = 23.5;        // Temperatura ambiente ejemplo
float voltajeSensor = 2.75;      // Voltaje leído de un sensor
float incrementoTiempo = 0.5;    // Incremento en segundos

// =============================================
// SECCIÓN 4: VARIABLES BOOLEANAS Y CARACTERES
// =============================================

// bool - Solo puede ser true o false (1 byte)
bool sistemaActivo = true;       // Estado general del sistema
bool ledEncendido = false;       // Estado actual del LED
bool wifiConectado = false;      // Estado conexión WiFi

// char - Un solo carácter (1 byte)
char gradoCelsius = 'C';         // Símbolo de grados Celsius
char estadoAnterior = 'A';       // Estado anterior (A=Apagado, E=Encendido)

// =============================================
// SECCIÓN 5: CONFIGURACIÓN INICIAL (SETUP)
// =============================================

void setup() {
  // Inicializar comunicación serie
  Serial.begin(velocidadSerial);
  delay(1000); // Esperar inicialización
  
  // Configurar pin del LED como salida
  pinMode(PIN_LED, OUTPUT);
  
  // Guardar tiempo de inicio
  tiempoInicio = millis();
  
  // Mensaje de información inicial
  Serial.println("==========================================");
  Serial.println("A05 - EJEMPLOS DE VARIABLES EN ESP32");
  Serial.println("==========================================");
  Serial.print("Dispositivo: ");
  Serial.println(NOMBRE_DISPOSITIVO);
  Serial.print("Voltaje referencia: ");
  Serial.print(VOLTAJE_REF);
  Serial.println("V");
  Serial.println("==========================================");
  Serial.println();
}

// =============================================
// SECCIÓN 6: BUCLE PRINCIPAL (LOOP)
// =============================================

void loop() {
  // Actualizar contador de ciclos
  contadorCiclos = contadorCiclos + 1;  // contadorCiclos++
  
  // Calcular tiempo transcurrido
  milisegundosTranscurridos = millis() - tiempoInicio;
  
  // =============================================
  // DEMOSTRACIÓN: USO DE VARIABLES ENTERAS
  // =============================================
  if (contadorCiclos % 5 == 0) {  // Cada 5 ciclos
    Serial.println("--- VARIABLES ENTERAS ---");
    Serial.print("Ciclos ejecutados: ");
    Serial.println(contadorCiclos);
    Serial.print("Tiempo transcurrido: ");
    Serial.print(milisegundosTranscurridos / 1000);
    Serial.println(" segundos");
    Serial.println();
  }
  
  // =============================================
  // DEMOSTRACIÓN: USO DE VARIABLES CON DECIMALES
  // =============================================
  if (contadorCiclos % 7 == 0) {  // Cada 7 ciclos
    // Simular lectura de sensor con valores aleatorios
    temperatura = 20.0 + (random(0, 200) / 10.0);  // 20.0°C a 40.0°C
    voltajeSensor = (random(0, 330)) / 100.0;       // 0.0V a 3.3V
    
    Serial.println("--- VARIABLES DECIMALES ---");
    Serial.print("Temperatura simulada: ");
    Serial.print(temperatura);
    Serial.print(" °");
    Serial.println(gradoCelsius);
    Serial.print("Voltaje sensor: ");
    Serial.print(voltajeSensor);
    Serial.println(" V");
    Serial.println();
  }
  
  // =============================================
  // DEMOSTRACIÓN: USO DE VARIABLES BOOLEANAS
  // =============================================
  if (contadorCiclos % 3 == 0) {  // Cada 3 ciclos
    // Alternar estado del LED
    ledEncendido = !ledEncendido;  // Cambiar true/false
    
    // Controlar LED físico
    digitalWrite(PIN_LED, ledEncendido);
    
    Serial.println("--- VARIABLES BOOLEANAS ---");
    Serial.print("Sistema activo: ");
    Serial.println(sistemaActivo ? "SI" : "NO");
    Serial.print("LED encendido: ");
    Serial.println(ledEncendido ? "SI" : "NO");
    Serial.print("WiFi conectado: ");
    Serial.println(wifiConectado ? "SI" : "NO");
    Serial.println();
  }
  
  // =============================================
  // DEMOSTRACIÓN: OPERACIONES CON VARIABLES
  // =============================================
  if (contadorCiclos % 10 == 0) {  // Cada 10 ciclos
    Serial.println("--- OPERACIONES CON VARIABLES ---");
    
    // Operaciones matemáticas
    int dobleCiclos = contadorCiclos * 2;
    float temperaturaFahrenheit = (temperatura * 9/5) + 32;
    
    Serial.print("Doble de ciclos: ");
    Serial.println(dobleCiclos);
    Serial.print("Temperatura en Fahrenheit: ");
    Serial.print(temperaturaFahrenheit);
    Serial.println(" °F");
    
    // Operaciones de comparación
    bool temperaturaAlta = (temperatura > 30.0);
    bool voltajeNormal = (voltajeSensor >= 2.5 && voltajeSensor <= 3.0);
    
    Serial.print("Temperatura alta (>30°C): ");
    Serial.println(temperaturaAlta ? "SI" : "NO");
    Serial.print("Voltaje normal (2.5V-3.0V): ");
    Serial.println(voltajeNormal ? "SI" : "NO");
    Serial.println();
    
    Serial.println("==========================================");
  }
  
  // Espera entre ciclos
  delay(1000);  // 1 segundo entre iteraciones
}
