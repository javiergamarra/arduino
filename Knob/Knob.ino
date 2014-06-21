// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
 
Servo myservo; 
 
void setup() 
{ 
  myservo.attach(9);
} 
 
void loop() 
{ 
  int val = analogRead(0);
  Serial.println(val);
  myservo.write(map(val, 0, 1023, 0, 179));
  delay(15);
} 
