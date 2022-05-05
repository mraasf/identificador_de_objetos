int trig = 3;
int echo = 4;
int verde = 9;
int azul = 10;
int amarelo = 11;
int vermelho = 12;
int buzina = 13;
long duracao, distancia;

void desligaLeds() {
  digitalWrite(buzina, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
  delay(5);

}
void leituraDistancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duracao = pulseIn(echo, HIGH);
  distancia = (duracao / 2) / 29.1;
  Serial.print(distancia);
  Serial.println(" centimetros ");
}
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(buzina, OUTPUT);

}

void loop() {
  desligaLeds();
  leituraDistancia();

  if (distancia > 100) {
    digitalWrite(verde, HIGH);
    delay(10);
    digitalWrite(verde, LOW);
  }

  if ((distancia < 100) && (distancia > 70 )) {
    digitalWrite(azul, HIGH);
    delay(10);
    digitalWrite(azul, LOW);
  }
  if ((distancia < 70 ) && (distancia > 40)) {
    digitalWrite(amarelo, HIGH);
    delay(10);
    digitalWrite(amarelo, LOW);
  }
  if (distancia < 40 ) {
    digitalWrite(vermelho, HIGH);
    delay(10);
    digitalWrite(vermelho, LOW);

    digitalWrite(buzina, HIGH);
    delay(10);
    digitalWrite(buzina, LOW);

  }


}
