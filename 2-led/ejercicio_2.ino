//encender y apagar un led
#define pinLed 9
//variable
int t1=1000;
void setup() {
  //Configuramos pines
  pinMode(pinLed,OUTPUT);
}
void loop() {
  //Encedemos Led
  digitalWrite(pinLed,HIGH);
  delay(t1);
  //apagamos Led
  digitalWrite(pinLed,LOW);
  delay(t1);
}
