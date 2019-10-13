/*****************************************************************************+*
MakersAsturias
Taller de Introducción a Arduino - 1
11 de Octubre de 2019

IMPORTANTE
Esta versión del programa es provisional para que los asistentes al taller tengan
el archivo lo antes posible. Se actualizará por otra versión con comentarios y
explicaciones adicionales.

Este sketch contiene el código usado en el taller de introducción a Arduino.
*******************************************************************************/

byte buzzer = 13;   // Pin del Arduino en el que se conecta el zumbador

void setup() {
  // Configuramos el pin del zumbador como SALIDA, usando la variable que creamos
  // para definir el número del pin al que se conecta.
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Se tocan alternativamente las dos notas

  // Nota 1
  float nota = 440.0;                 // 440 Hz es un La
  int ciclos = 200;                   // Toca la nota durante 200 ciclos
  int retardo = 1000000*(1/nota)/2;   // Retardo medido en microsegundos
  for (int i=0; i<ciclos; i++) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(retardo);
  }

  // Nota 2
  nota = 880.0;                       // 880 Hz es un La más agudo
  ciclos = 400;                       // Toca la nota durante 400 ciclos
  int retardo = 1000000*(1/nota)/2;   // Retardo medido en microsegundos
  for (int i=0; i<ciclos; i++) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(retardo);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(retardo);

  // Se termina el loop, y se vuelve a empezar con la primera nota
}
