/*
 *Titulo:            Desarrollo de Alarma para el acceso a una puerta
 *Fecha Entrega:     14/03/2018
 *Autor:             Marco Antonio Moreno Cortés
 *
 *--------------------------------------------------------------------------------------
 *Desarrollo:
 *
 *
 *Este programa realizado en Arduino simulara el Acceso a una puerta utilizando 
 *reed switch y un led y adicionalmente se pondrá controlar la frecuencia del 
 *tono de un buzzer con un potenciómetro el cual podrá disminuir o aumentar la 
 *frecuencia del tono del buzzer esto quiere decir que se podrá cambiar tono.
 *
 *La manera en que funcionara el circuito armado es la siguiente:
 *
 *El reed switch siendo este un interruptor eléctrico activado por un campo magnético 
 *simulara el acceso a una puerta ya que consta de dos contactos que en estado normal 
 *están separados el cual simularan cuando puerta abierta y se activara el buzzer o 
 *zumbador y el led y al acercarse un campo magnético en este caso un imán se juntará 
 *y simularan cuando la puerta está cerrada y se desactivara buzzer y el led volviendo 
 *a un estado normal. 
 *
 */



/* Definición de constantes y asignación a los pines */ 

int led=13;           //Variable asignado al ping 13= led.
int reedwitch=5;      //Variable asignado al ping 5=reed switch.
int buzzer=8;         //Variable asignado al ping 8=buzzer.
int val=0;
int potenciometro=A0;//A0 la variable donde se almacenará lo valores leeidos del potenciómetro para luego utilizarlos como parámetros de frecuencia.
int frecuencia;      //Variable que guardara la frecuencia.
int tono;            //Tono valor que se leea en el potenciómetro será almacena en esta variable.
int duracion=800;    //Duración de frecuencia.


//Método encargado de recoger información de las variables utilizadas en void loop()
//configurando los métodos de trabajo de los pines utilizados de salida y entrada.
void setup() {
//
pinMode(led,OUTPUT);
pinMode(reedwitch,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(tono,INPUT);
//Abre el puerto serie y fija la velocidad en baudios para la transmisión de datos en serie.
//El valor típico de velocidad para comunicarse con el ordenador es 9600, aunque otras velocidades pueden ser soportadas.
Serial.begin(9600);
}


//Contiene el programa que se ejecutara ciclicamente
void loop() {

val=digitalRead(reedwitch);//Lee el valor en el reedwitch
if(val==LOW){//Condicion  la cual hará toda la funcionalidad del circuito armado mientras el valor recibido por el reed witch este bajo 
 //activara el ping del led y buzzer para abrir la comunicación y tendra un tiempo que permanecera apagado con la función delay.
 digitalWrite(led,HIGH);
 digitalWrite(buzzer,HIGH);
 delay(250);
 //desactivara led, buzzer
 digitalWrite(led,LOW);
 digitalWrite(buzzer,LOW);
 //tono es igual a la lectura que se hace el potenciómetro el cual puede leer valores del 0-1023
 tono=analogRead(potenciometro);
 //"map" nos permite convertir un rango de variación en otro con toda sencillez, tono 
 // en donde 100 es la frecuencia minima que se puede seleccionar y 3000 la maxima
 frecuencia=map(tono,0,1023,100,3000);
 tone(buzzer,frecuencia,duracion);
 Serial.print("Frecuencia= ");
 Serial.println(frecuencia);//Muestra en consola de arduino la frecuencia.
 delay(100);//si aumenta el delay la frecuencia sera menor y si se disminuye sera mayor 
  }
  else{
   digitalWrite(led,LOW);
   digitalWrite(buzzer,LOW);
      }
}
