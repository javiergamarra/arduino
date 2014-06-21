// 2-dimensional array of row pin numbers:
const int row[8] = {
  2,7,19,5,13,18,12,16 };

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6,11,10,3,17,4,8,9  };

int pixels[8][8];           

void setup() {
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    pinMode(col[thisPin], OUTPUT); 
    pinMode(row[thisPin], OUTPUT);  
    digitalWrite(col[thisPin], HIGH);    
  }

  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = HIGH;
    }
  }
}

void loop() {
  //digitalWrite(row[0], HIGH);
  //digitalWrite(col[0], HIGH);
}
