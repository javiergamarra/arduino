
#include <Servo.h>

Servo myServo;
const int pinServo = 9;
const int angleMax = 90;


void setup() {
  myServo.attach(pinServo);
  Serial.begin(9600);
  myServo.write(0); // Angle = 0º
}

void loop() {
  //myServo.write(180);
  if(Serial.available() > 0) {
    char dato = Serial.read();
    if(dato == 'T') {
      // Mover el Servo en una dirección
      for(int i=0;i<angleMax;i++) {
        myServo.write(i);
        Serial.println(i);
        delay(10);
      }
      delay(5000);
      myServo.write(0); // Mover a posición inicial
    }
    else if(dato == '_')
    {
      Serial.println("CERO");
      myServo.write(0); // Mover a posición inicial
    }
  }

}
