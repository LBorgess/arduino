void setup() {
  
  /* PINOS PARA CONTROLAR O MOTOR A [ESQUERDO] */
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  /* PINOS PARA CONTROLAR O MOTOR B [DIREITO] */
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

// ========================================
/* FRENTE */

  /* MOTOR A - PARA FRENTE */
  //digitalWrite(9, LOW);
  //digitalWrite(10, HIGH);
  
  /* MOTOR B  PARA FRENTE */
  //digitalWrite(11, HIGH);
  //digitalWrite(12, LOW);

// ========================================
/* TRÁS */

  /* MOTOR A - PARA TRÁS */
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  
  /* MOTOR B  PARA TRÁS */
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);


// ========================================
/* GIRAR - MOTOR A */

  /* MOTOR A - GIRANDO */
  //digitalWrite(9, HIGH);
  //digitalWrite(10, LOW);
  
  /* MOTOR B  PARADO */
  //digitalWrite(11, LOW);
  //digitalWrite(12, LOW);

// ========================================
/* GIRAR - MOTOR B */

  /* MOTOR A - PARADO */
  //digitalWrite(9, LOW);
  //digitalWrite(10, LOW);
  
  /* MOTOR B - GIRANDO */
  //digitalWrite(11, LOW);
  //digitalWrite(12, HIGH);

// ========================================
/* MOTORES DESLIGADOS */

  //digitalWrite(9, LOW);
  //digitalWrite(10, LOW);
  //digitalWrite(11, LOW);
  //digitalWrite(12, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
}
