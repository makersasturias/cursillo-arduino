/*****************************************************************************+*
MakersAsturias
Taller de Introducción a Arduino - 1
11 de Octubre de 2019

IMPORTANTE
Esta versión del programa es provisional para que los asistentes al taller tengan
el archivo lo antes posible.. Se actualizará por otra versión con comentarios y
explicaciones adicionales.

Este sketch contiene el código usado en el taller de introducción a Arduino.
*******************************************************************************/

byte buzzer = 13;   // Pin del Arduino en el que se conecta el zumbador


void tocaNota(float nota, int ciclos) {
  // Retardo medido en microsegundos
  int retardo = 1000000*(1/nota)/2;

  // Función para tocar una nota
  for (int i=0; i<ciclos; i++) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(retardo);
  }
}

void setup() {
  // Configuramos el pin del zumbador como SALIDA, usando la variable que creamos
  // para definir el número del pin al que se conecta.
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Se tocan alternativamente las dos notas
  tocaNota(440.0, 200);
  tocaNota(880.0, 400);
}
