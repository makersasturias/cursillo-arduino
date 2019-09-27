INSTALAR ARDUINO.

INSTALAR IDE.

Existen varios IDEs para trabajar con Arduino, como NETBEAM, Platformio,
etc, pero como iniciación es recomendable trabajar con el proporcionado
por Arduino.

WINDOWS:

<span style="font-weight: normal">Descargar la última versión del IDE de
Arduino desde: <http://arduino.cc/en/Main/Software></span>

Elegir la opción de Windows Installer, aunque también es posible
descargar la versión comprimida en zip.

Ejecutar el instalador descargado. Si existe una versión anterior el
instalador nos avisa y nos desinstala. En el caso que hayamos hecho
modificaciones en el directorio de instalación las perderemos.

<img src="Guia_htm_1c42262133b0d34a.png" width="332" height="192" />  
  

  
  

  
  

  
  

  
  

  
  

<img src="Guia_htm_82f157b7cd393cf4.png" width="331" height="227" />  
  

![](Guia_htm_dbcf5d19c205272e.gif)  
  

  
  

  
  

  
  

  
  

  
  

  
  

  
  

<img src="Guia_htm_4a7a46a0f9f849d1.png" width="336" height="232" />  
  

  
  

  
  

  
  

  
  

  
  

  
  

  
  

<img src="Guia_htm_891a7f500a7a660d.png" width="357" height="169" />  
  

  
  

  
  

  
  

  
  

  
  

  
  

  
  

MAC OS:

Descargar la ultima versión de Arduino IDE en
<http://arduino.cc/en/Main/Software> y descargaremos un fichero .zip, el
cual sera descomprimido automáticamente o manualmente dependiendo de la
configuración del safari.

LINUX:

Descargar la ultima versión de Arduino Ide en
<http://arduino.cc/en/Main/Software> se deberá de escoger entre nuestra
versión 32, 64 bits o ARM y descargar el fichero. Extraeremos el fichero
en la carpeta escogida recordando que sera ejecutado el IDE desde aquí.

Abrir la carpeta creada en la extracción y hacer click con el botón
derecho al fichero instalar y escogemos Run in Terminal.

Otra manera es abriendo el terminal y abrir la carpeta creada. Teclear
el comando ./instal.sh y esperar a que el proceso termine. Se debería de
encontrar un nuevo icono en el escritorio.

Puede ser que cuando carguemos un ketchup a nuestro arruino nos salga un
error “Error opening serial port...” es porque se necesitan permisos
para el puerto serie. Deberemos de hacer:

1.  Abrimos el terminal y tecleamos ls -l *dev/*<span
    style="font-style: normal">ttyACM\*</span>

2.  Conseguiremos algo así: crw-rw----l root dialout 188, 0 5 apr 23.01
    ttyACM0

  
  

  
  

  
  

  
  

  
  

  
  
