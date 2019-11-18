//encender y apagar un led
void setup() {
  //Configuramos pines
  pinMode(9,OUTPUT);
}
void loop() {
  //Encedemos Led
  digitalWrite(9,HIGH);
  delay(1000);
  //apagamos Led
  digitalWrite(9,LOW);
  delay(1000);
}
