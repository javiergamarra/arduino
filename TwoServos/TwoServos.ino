#include <Servo.h> 

Servo myservo;
Servo mymotor;

void setup() 
{ 
  mymotor.attach(9);
  myservo.attach(10);
} 

void loop() 
{
  myservo.detach();
  
  mymotor.attach(9);
  mymotor.write(0);
  delay(1000);
  mymotor.detach();
  
  myservo.attach(10);
 for (int i = 0; i < 180; i++) {
  myservo.write(i);
  delay(15);
 }

} 
