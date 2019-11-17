//encender y apagar un led
#define pinLed 9
//variable
int t1=1000;
void setup() {
  //Configuramos pines
  pinMode(pinLed,OUTPUT);
  //Habilitamos puerto serie, para chequeo
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()>0){
    char inByte=Serial.read();
  }
  //Encedemos Led
  digitalWrite(pinLed,HIGH);
  delay(t1);
  //apagamos Led
  digitalWrite(pinLed,LOW);
  delay(t1);
}
