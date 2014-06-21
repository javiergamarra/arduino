int element = 8;
int valorPotenciometro;

void setup()  { 
  Serial.begin(9600);
} 

void loop()  { 
 Serial.println(analogRead(A2));
 //tuning con los valores leidos
 valorPotenciometro = map(analogRead(A2), 400, 500, 0, 5000); 
 tone(element, valorPotenciometro, 250);
}
