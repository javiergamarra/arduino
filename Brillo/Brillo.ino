int led = 9;
int brillo = 0;

void setup()  { 
  
} 

void loop()  { 
  for(brillo = 0 ; brillo <= 5000; brillo +=50) { 
    analogWrite(led, brillo);         
    delay(300);                            
  } 

  if (brillo >= 5000) {
    brillo = 0;
  }
}


