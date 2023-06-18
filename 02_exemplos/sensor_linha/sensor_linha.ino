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
  /* VERIFICA SE O SENHOR DETECTOU A LINHA DA ARENA */
  if (!digitalRead(3) || !digitalRead(4)) {
    Serial.println("LINHA.");
    parado();
    delay(1);
    tras();
    delay(300);
    parado();
    delay(1);
    girarA();
    delay(600);
    parado();
  }
  frente();
  delay(10);
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
void girarA() {
  Serial.println("GIRANDO RODA ESQUERDA.");
  /* MOTOR A - GIRANDO */
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  /* MOTOR B  PARADO */
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

/* GIRAR - MOTOR B - DIREITO */
void girarB() {
  Serial.println("GIRANDO RODA DIREITA.");
  /* MOTOR A - PARADO */
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  /* MOTOR B - GIRANDO */
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}
