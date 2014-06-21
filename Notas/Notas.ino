#include "pitches.h"

void setup() {
  for (int nota = 0; nota < 5000; nota++) {
    tone(8, nota, 250);
    delay(300);
    noTone(8);
  }
}

void loop() {
}
