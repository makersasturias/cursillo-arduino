//encender y apagar un led
#define pinLed 9
//variable
int t1=1000;
void setup() {
  //Configuramos pines
  pinMode(pinLed,OUTPUT);
  //Habilitamos puerto serie, para chequeo
  Serial.begin(9600);
  Serial.println("PRUEBA TALLER");
  Serial.println("0: off | 1: on");
}
void loop() {
  if(Serial.available()){
    char inByte=Serial.read();
    if(inByte=='0'){
      digitalWrite(pinLed,LOW);
    }
    if(inByte=='1'){ 
      //Encedemos Led
      digitalWrite(pinLed,HIGH);
      delay(t1);
      //apagamos Led
      digitalWrite(pinLed,LOW);
      delay(t1);
    }
  }
}
