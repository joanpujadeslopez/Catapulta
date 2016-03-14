#include <Servo.h>



Servo servoBase;
int angle=90;

void setup(){
  servoBase.attach(9);
  Serial.begin(9600);
}


void loop(){
  unsigned char comando=0;
  if(Serial.available()){//solo leeremos si hay un byte en el buffer
    
    comando=Serial.read();//leemos el byte
    
    if(comando=='a')angulo+=10;//incrementamos 10
    else if(comando=='z')angulo-=10;//decrementamos 10
    angulo=constrain(angulo,0,180);//restringimos el valor de 0 a 180
  }
  miServo.write(angulo);  
  Serial.print("Angulo:");Serial.println(angulo);
  delay(100);
}//End loop
