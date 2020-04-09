//Aplicacion que recibe el anguno de posicion para el servo desde la app ArduServo.apk
//Modulo bluetoth hc05 o hc06 y conexion TX y RX invertido del modulo a los puertos del arduino marcados con tx y rx
//EA1IRT 2019.
#include <Servo.h> 

Servo ServoAndroid;
int rxAng; //Caracter recibido por bluetooth
int ang = 90; //Ángulo inicial 90 grados

void setup(){

  ServoAndroid.attach(11,550,2500); //Servomotor: PIN11 y parametros de ajuste del servo
  Serial.begin(9600); //baudrate=9600
  
  }

void loop(){
  
  if(Serial.available()){ // "Si se detecta un angulo"
    rxAng = Serial.read(); // Se lee el caracter desde la app android

   
       
    ang = constrain(ang,0,180); //Limitamos los valores maximos de angulo
    ang = rxAng;
    }
    Serial.print (ang);
    ServoAndroid.write(ang); //Enviamos el valor del angulorecibido al Servo
    delay(100); //tiempo de espera 100ms
  }
