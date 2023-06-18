void setup() {
  /* DEFINIÇÃO DO PINO DO PUSH BUTTON */
  pinMode(2, INPUT_PULLUP);

  /* DEFINIÇÃO DOS PINOS DOS MOTORES */
  /* PINOS PARA CONTROLAR O MOTOR A [ESQUERDO] */
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  /* PINOS PARA CONTROLAR O MOTOR B [DIREITO] */
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  Serial.begin(9600);

  // ========================================
  // CONFIGURAÇÃO PARA DEIXAR O ROBO PARADO
  // ANTES DE INICIAR A LUTA
  while(digitalRead(2) == LOW){
    Serial.println("AGUARDANDO.");
    delay(1);
    parado();

    if(digitalRead(2) == HIGH){
      delay(1);
      frente();
    }
  }
}

void loop() {
}

// ========================================
// FUNÇÕES DOS MOTORES
// ========================================

/* MOTORES DESLIGADOS */
void parado() {
  Serial.println("PARADO");
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

/* FRENTE */
void frente() {
  Serial.println("FRENTE");
  /* MOTOR A - PARA FRENTE */
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);

  /* MOTOR B  PARA FRENTE */
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}

/* TRÁS */
void tras() {
  Serial.println("TRAS");
  /* MOTOR A - PARA TRÁS */
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  /* MOTOR B  PARA TRÁS */
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}

/* GIRAR - MOTOR A - ESQUERDO */
void girarA() {
  Serial.println("GIRANDO ESQUERDO");
  /* MOTOR A - GIRANDO */
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  /* MOTOR B  PARADO */
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
}

/* GIRAR - MOTOR B - DIREITO */
void girarB() {
  Serial.println("GIRANDO DIREITO");
  /* MOTOR A - PARADO */
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  /* MOTOR B - GIRANDO */
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
}
