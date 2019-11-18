//encender y apagar un led
//introducimos pulsador
#define pinLed 9
#define button 3
//variable

int status_button=0;
void setup() {
  //Configuramos pines
  pinMode(pinLed,OUTPUT);
  pinMode(button,INPUT);
  //Habilitamos puerto serie, para chequeo
  Serial.begin(9600);
}
void intermitente(int t1){
  //Encedemos Led
  digitalWrite(pinLed,HIGH);
  delay(t1);
  //apagamos Led
  digitalWrite(pinLed,LOW);
  delay(t1);
}
void loop() {
  //leemos estado boton
  status_button=digitalRead(button);
  if(status_button==HIGH){
    intermitente(1000);
  }
  else{
    digitalWrite(pinLed,LOW);
  }
}
