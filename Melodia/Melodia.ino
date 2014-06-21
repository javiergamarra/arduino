#include "pitches.h"

int melodia[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

int duracion[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
  for (int nota = 0; nota < 8; nota++) {

    int duracionNota = 1000 / duracion[nota];
    tone(8, melodia[nota], duracionNota);

    delay(duracionNota * 1.30);
    noTone(8);
  }
}

void loop() {
}
