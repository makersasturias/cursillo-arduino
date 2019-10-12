
byte buzzer = 13;   // Pin del arduino


void tocaNota(float nota, int ciclos) {
  // Retardo medido en microsegundos
  int retardo = 1000000*(1/nota)/2;
  
  for (int i=0; i<ciclos; i++) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(retardo);
  }
}

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tocaNota(440.0, 200);
  tocaNota(880.0, 400);
}
