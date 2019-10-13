# Introducción a la programación en Arduino

MakersAsturias - Octubre 2019

En este documento describiremos el código usado en la primera sesión del Taller de Iniciación a Arduino.

Cuando se escriban partes de código, nombres de variables, o elementos que pertenecen al código, se empleará la sintaxis de código, que tiene `este aspecto`.

## Aspectos generales de un *sketch* de Arduino

### Estructura de un *sketch* de Arduino

Un *sketch* (boceto en inglés) es el nombre que reciben los archivos que contienen el código que se va a programar en un Arduino.

Su estructura mínima debe contener dos *funciones*, que se generan automáticamente al crear un nuevo *sketch*, y dentro de las cuales se añade el código que se va a ejecutar. Estas dos funciones son `setup` (configuración, ajuste...) y `loop` (bucle):

- `void setup()`: el código incluido entre las llaves `{` y `}` de la función se ejecuta **una única vez** al encender o resetear el Arduino. En esta función se incluye la configuración de los diferentes pines que se vayan a usar, así como la inicialización y configuración de las comunicaciones, librerías, etc.
- `void loop()`: el código incluido entre sus llaves se ejecuta **una y otra vez hasta que se apaga o resetea el Arduino**. Aquí es donde se ubica el código que realiza las tareas que queremos que realice el Arduino (mover motores, leer sensores, escribir datos, etc)

Además de estas funciones básicas, se pueden añadir otros elementos como funciones adicionales, definiciones de variables, etc. Esto se verá en el ejemplo.

### Comentarios en el código

Cuando se escribe un programa es muy recomendable añadir comentarios para entender mejor qué se pretende hacer. Esto ayuda a otros programadores que lean nuestro código, o a nosotros mismos dentro de un tiempo cuando no recordemos bien el propósito del código.

Hay dos tipos de comentarios:

- Comentarios de línea: comienzan con `//`, y todo lo que se escriba a partir de entonces, y hasta que se pulse INTRO, se interpreta como comentario y no se ejecuta como código. Un comentario puede comenzar al inicio de una línea o en cualquier parte de ella.
- Comentarios de bloque: Comienzan con `/*` y terminan con `*/`. Todo lo que se incluya entre ellas se interpreta como comentarios, incluso los INTRO que haya. Permite escribir párrafos enteros de comentarios sin tener que escribir `//` para cada línea.

## Descripción del ejemplo

El ejemplo consiste en un pequeño programa que toca dos notas alternativamente mediante un zumbador (*buzzer*) conectado a un pin del Arduino.

### Variable para definir el pin del zumbador

Para que el Arduino sepa en qué pin se conecta el zumbador debemos podemos una *variable* que contenga el número del pin usado.

Para definir una variable necesitamos especificar:
- El *tipo* de dato que va a almacenar la variable.
- El nombre de la variable.
- El valor de la variable que se almacena. Este valor puede luego ser modificado por el programador o por el propio código.

Vamos a definir una variable `buzzer` que contenga el número del pin usado, que en este caso será el 13. Como el número del pin es un número entero, tenemos varias opciones para definir su **tipo**, como por ejemplo:
- `byte`: utiliza 1 *byte* (8 bits) para almacenar el valor, y puede almacenar números enteros entre -128 y +127.
- `int`: abreviatura de `integer` (entero en inglés), que utiliza 2 *bytes* para almacenar el valor y permite almacenar números enteros entre -32768 y +32767.

Como los números que definen los pines son bajos, nos basta con un `byte`:

`byte buzzer = 13;`

La creación de variables se hace generalmente **al principio del programa y fuera de la función `setup()`**.


### Función `setup()`

Aquí se configuran pines, librerías, objetos creados, etc. En este ejemplo la unica configuración necesaria es la del pin del zumbador.

El pin va a ser una *salida* del Arduino, ya que le va a enviar señales al zumbador, así que necesitamos decirle al Arduino mediante que el pin es una salida mediante la expresión:

`pinMode(pin, MODO);`

`pin` es el número del pin que se configura, que en este caso será el 13. Podríamos escribir directamente el número aquí, pero como hemos definido la variable `buzzer` que almacena ese mismo valor, usamos el nombre de la variable. Esto que puede parecer redundante, tiene ventajas que se irán viendo.

`MODO` puede ser `INPUT` (entrada) o `OUTPUT` (salida). En nuestro caso, es una salida.

La configuración del pin queda entonces:

`pinMode(buzzer, OUTPUT);`


### Función `loop()`

Nuestro ejemplo se limita a hacer sonar alternativamente dos notas en el zumbador.

#### Frecuencia y duración de la nota

Para hacer sonar una nota necesitamos definir la frecuencia y la duración (cuánto va a durar) de la misma:

```c++
float nota = 440.0;
int ciclos = 200;
``` 

Mediante `nota` definimos una frecuencia de 440 Hz, que se corresponde con un La. Aunque podríamos definirlo como `int`, más adelante veremos que lo usaremos en una división, así que lo definiremos como `float`.

El lenguaje de Arduino, que es C++, tiene un comportamiento un poco especial cuando se dividen números, ya que si queremos que el resultado de una división sea un número con decimales uno de los dos números que se dividen (numerador o denominador, o ambos) debe ser un `float`. Si no, al dividir por ejemplo 5/4 nos daría un resultado de 1 (número entero) en lugar de 1.25 (número decimal), es decir se trunca al número entero anterior.

Con `ciclos` hacemos que el pin del zumbador haga 200 ciclos, donde cada ciclo consiste en poner el pin a 5V, esperar un tiempo y volver a ponerlo a 0V. Como es un simple contador (va a tomar valores 0, 1, ...) lo definimos como `int`.

#### Retardo (duración de cada ciclo)

Como dijimos, vamos a ejecutar 200 veces un ciclo que se compone de:

```c++
digitalWrite(buzzer, HIGH);
delay(retardo);
digitalWrite(buzzer, LOW);
delay(retardo);
```

La función `digitalWrite(buzzer, HIGH)` hace que el pin `buzzer` se ponga en estado `HIGH` (alto), es decir en el pin se tienen 5V. Del mismo modo, `digitalWrite(buzzer, LOW)` pone el pin en nivel `LOW` (bajo), es decir a 0V.

La línea `delay(retardo)` hace que el Arduino espere un tiempo igual a `retardo` en milisegundos, es decir que tras poner el pin a 5V espera un tiempo y luego lo pone a 0V, tras lo cual vuelve a esperar.

El valor del retardo viene dado por:

```c++
int retardo = 1000000 * (1/nota) / 2;
```

Este cálculo nos lo creeremos, para no alargar mucho la explicación con cosas que no son programación en sí.

#### Bucle de 200 repeticiones

Hasta ahora hemos hecho un ciclo de una nota La de 440 Hz, pero si no creamos más ciclos no escucharemos nada, ya que el ciclo dura tan poco que no lo percibimos. Para que escuchemos el sonido debemos repetir el ciclo.

Una de las formas de hacer repeticiones es mediante los bucles `for`, que tiene la estructura siguiente:

```c++
    for (int i=inicio; condición; i++ 
    {
        <una acción a repetir>
        ...
        <otra acción a repetir>
    }
```

En C++ (y en Arduino) `i++` es una expresión que es equivalente a `i = i + 1`, es decir incrementa en una unidad su valor.

En lenguaje natural lo podríamos enunciar como:

> Para cada valor de `i`, empezando en `inicio`, y mientras se cumpla la condición `condición`, ejecuta el código que está entre las llaves y luego incrementa el valor de `i` en 1 unidad.

En nuestro caso la definición del bucle es:

> Para cada valor de `i`, empezando en `0`, y mientras se cumpla que `i` es menor que `ciclos` (200), ejecuta el ciclo definido más arriba, y luego incrementa `i` en una unidad.

En la primera repetición `i` vale 0, se ejecuta el ciclo y se incrementa `i`, que pasa a valer 1. Llegará un momento en el que `i` se incrementará y pasará  valer 201, por lo que en la siguiente ejecución del bucle ya no se cumple la condición, y no se ejecuta el ciclo.

Tras salir del bucle `for`, se pasa a la siguiente línea a ejecutar, que en nuestro ejemplo es la segunda nota.

Para esta segunda nota definiremos una nueva frecuencia y una nueva duración, se vuelve a calcular el retardo y se vuelve a ejecutar el bucle de ciclos.

Es importante notar que para la segunda nota no hay que definir el tipo de las variables `nota` y `ciclos`, que ya se definieron antes como `float` y `int` respectivamente. Si se definieran de nuevo, el compilador mostraría un error.

Una vez se termine el segundo bucle `for`, se terminarían las acciones a ejecutar dentro de `loop()`, y se volvería a empezar desde el principio del mismo, definiendo la primera nota.
