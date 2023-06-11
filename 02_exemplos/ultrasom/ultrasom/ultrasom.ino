/*========================================
  TESTE DO SENSOR ULTRASÔNICO

  DATA: 2023-06-11

  FONTE: https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-ultrasonico-hc-sr04
/========================================*/

/*========================================*/

/* BIBLIOTECA AUXILIAR */
#include <Ultrasonic.h>

/*========================================*/

/* DEFINIÇÕES DOS PINOS DO ULTRASOM*/
#define uEcho 8      // PINO ECHO - RECEBE
#define uTrigger 13  // PINO TRIGGER - ENVIA

/*========================================*/

/* INICIALIZA O SENSOR E VARIÁVEIS */
Ultrasonic ultrasonic(uTrigger, uEcho);

int distancia;
String resultado;

/*========================================*/

void setup() {
  pinMode(uEcho, INPUT);      // RECEBE OS DADOS
  pinMode(uTrigger, OUTPUT);  // ENVIA OS DADOS
  Serial.begin(9600);         // INICIO DA PORTAL SERIAL
}

void loop() {
  ultrasom(); // CHAMADA DA FUNÇÃO
  Serial.print("Distancia: "); // EXIBE O TEXTO NO MONITOR SERIAL
  Serial.print(resultado);    // EXIBE A DISTÂNCIA MEDIDA
  Serial.println("cm");
}

/*========================================*/

/* FUNÇÕES AUXILIARES */

void ultrasom() {
  digitalWrite(uTrigger, LOW);  // PULSO BAIXO PARA O TRIGGER
  delayMicroseconds(2);         // DELAY DE 2 MICROSSEGUNDOS
  digitalWrite(uTrigger, HIGH); // PULSO NO ALTO
  delayMicroseconds(10);        // DELAY DE 10 MICROSSEGUNDOS
  digitalWrite(uTrigger, LOW);  // PULSO BAIXO PARA O TRIGGER

  /*
    FUNÇÃO 'RANGING' CONVERTE O TEMPO DE RESPOSTA DO ECHO EM CENTIMENTROS
    E ARMAZENA NA VARIAVEL < DISTANCIA >
  */
  distancia = (ultrasonic.Ranging(CM));
  resultado = String(distancia);
  delay(500);
}
