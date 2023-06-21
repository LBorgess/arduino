/*
	CÓDIGO PRINCIPAL - EM DESENVOLVIMENTO
*/

/* BIBLIOTECA AUXILIAR */
#include <HCSR04.h>

/* VARIAVEIS DOS SENSORES DE LINHA */
bool sensorLinhaDireito  = 0;
bool sensorLinhaEsquerdo = 0;

/* PINOS DO ULTRASOM */
#define ECHO 5
#define GATILHO 6

/* INICIALIZA O SENSOR USANDO OS PINOS DEFINIDOS */
UltraSonicDistanceSensor distanceSensor(GATILHO, ECHO);

void setup() {
  /* COMUNICAÇÃO DA PORTA SERIAL */
  Serial.begin(9600);

  /* DEFINIÇÃO DO PINO DO PUSH BUTTON */
  pinMode(2, INPUT_PULLUP);

  /* DEFINIÇÃO DOS SENSORES DE LINHA */
  // SENSOR DE LINHA DO LADO ESQUERDO
  pinMode(3, INPUT);
  // SENSOR DE LINHA DO LADO DIREITO
  pinMode(4, INPUT);

  /* DEFINIÇÃO DOS PINOS SENSOR ULTRASOM */
  // PINO ECHO
  pinMode(ECHO, INPUT);
  // PINO TRIGGER / GATILHO
  pinMode(GATILHO, OUTPUT);

  /* DEFINIÇÃO DOS PINOS DOS MOTORES */
  /* PINOS PARA CONTROLAR O MOTOR A [ESQUERDO] */
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  /* PINOS PARA CONTROLAR O MOTOR B [DIREITO] */
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  // ========================================
  // CONFIGURAÇÃO PARA DEIXAR O ROBO PARADO
  // ANTES DE INICIAR A LUTA
  while (digitalRead(2) == LOW) {
    Serial.println("AGUARDANDO.");
    delay(10);
    parado();

    if (digitalRead(2) == HIGH) {
      delay(10);
      frente();
    }
  }
}

void loop() {
  /* VARIAVEL DE DISTANCIA */
  int distancia = 0;

  /* ATRIBUIÇÃO DOS SENSORES DE LINHA */
  sensorLinhaEsquerdo  = digitalRead(3);
  sensorLinhaDireito = digitalRead(4);

  /* ATRIBUI O VALOR DA FUNÇÃO DA BIBLIOTECA */
  distancia = distanceSensor.measureDistanceCm();

  /* DETECTA A LINHA PRETA */
  if((sensorLinhaDireito == 0) && (sensorLinhaEsquerdo == 0)){
    Serial.print("Direito: ");
    Serial.println(sensorLinhaDireito);
    Serial.print("Esquerdo: ");
    Serial.println(sensorLinhaEsquerdo);
    parado();
    delay(500);
    tras();
    delay(750);    
    horario();
    delay(750);
  }
  frente();
}

// ========================================
// FUNÇÕES DOS MOTORES
// ========================================

/* MOTORES DESLIGADOS */
void parado() {
  Serial.println("PARADO.");
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

/* FRENTE */
void frente() {
  Serial.println("FRENTE.");
  /* MOTOR A - PARA FRENTE */
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);

  /* MOTOR B  PARA FRENTE */
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}

/* TRÁS */
void tras() {
  Serial.println("TRAS.");
  /* MOTOR A - PARA TRÁS */
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  /* MOTOR B  PARA TRÁS */
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}

/* GIRAR - MOTOR A - ESQUERDO */
void horario() {
  Serial.println("GIRANDO RODA ESQUERDA.");
  /* MOTOR A - GIRANDO */
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  /* MOTOR B  PARADO */
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

/* GIRAR - MOTOR B - DIREITO */
void antihorario() {
  Serial.println("GIRANDO RODA DIREITA.");
  /* MOTOR A - PARADO */
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  /* MOTOR B - GIRANDO */
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}
