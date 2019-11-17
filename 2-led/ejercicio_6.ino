//encender y apagar un led
#define pinLed 9

void setup() {
  //Configuramos pines
  pinMode(pinLed,OUTPUT);
  //Habilitamos puerto serie, para chequeo
  Serial.begin(9600);
  Serial.print("0: off | 1: on");
}
void intermitentes(int t1){
  //Encedemos Led
  digitalWrite(pinLed,HIGH);
  delay(t1);
  //apagamos Led
  digitalWrite(pinLed,LOW);
  delay(t1);
}
void loop() {
  if(Serial.available()>0){
    char inByte=Serial.read();
    if(inByte=='0'){
      digitalWrite(pinLed,LOW);
    }
    if(inByte=='1'){ 
      intermitentes(1000);
    }
  }
}
