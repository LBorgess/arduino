/*
  CÓDIGO EXEMPLO - EMPRESA

  CÓDIGO QUE VEIO COM O KIT

  CÓDIGO DE EXEMPLO SIMPLES, SEM O USO DO ULTRASOM
*/
void setup() {
  
  /* SENSORES DE LINHA */

  pinMode(11, INPUT);  // Sensor do lado direito  [VERDE]
  pinMode(12, INPUT);  // Sensor do lado esquerdo [AZUL]

  /* BOTÃO PUSH */

  pinMode(2, INPUT_PULLUP); // Push button [AZUL]

  /* PONTE H */

  pinMode(5, OUTPUT); // [LARANJA]
  pinMode(6, OUTPUT); // [ROXO]
  pinMode(9, OUTPUT); // [VERDE]
  pinMode(10, OUTPUT); // [AZUL]

  Serial.begin(9600);

  while (digitalRead(2) == 0) {
    delay(1);
    stop();
    Serial.println("AGUARDANDO");
  }
}

void loop() {
  /* VERIFICA DA LINHA */
  if (digitalRead(12) || digitalRead(11)) {  //verifica
    Serial.println("LINHA DETECTADA");
    stop();
    delay(1);
    re();
    delay(300);
    stop();
    delay(1);
    girar();
    delay(600);
    stop();
  }

  frente();
  delay(1);
}
void re() {
  Serial.println("RE");
  analogWrite(5, 0);
  analogWrite(6, 200);
  analogWrite(9, 0);
  analogWrite(10, 200);
}
void frente() {
  Serial.println("FRENTE");
  analogWrite(5, 200);
  analogWrite(6, 0);
  analogWrite(9, 200);
  analogWrite(10, 0);
}
void girar() {
  Serial.println("GIRANDO");
  analogWrite(5, 0);
  analogWrite(6, 200);
  analogWrite(9, 200);
  analogWrite(10, 0);
}
void stop() {
  Serial.println("PARADO");
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(9, 0);
  analogWrite(10, 0);
}