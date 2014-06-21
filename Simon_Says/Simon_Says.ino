#include "pitches.h"

const int buttons[] = {2, 3, 4, };
const int leds[] = {8, 9, 10, };
const int numberLeds = sizeof(leds) / sizeof(int);
const int speaker = 12;
int plays[100];
int turn;

const int startMelody[] = {NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_G4};
const int startDuration[] = {100, 200, 100, 200, 100, 400, 100, 100, 100, 100, 200, 100, 500};
const int buttonsMelody[] = {NOTE_G3, NOTE_A3, NOTE_B3, };

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  
  for (int i = 0; i < numberLeds; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  for (int i = 0; i < numberLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(speaker, OUTPUT);
  
  turn = 0;
  playStartSequence();
}

void loop() {
  
  plays[turn] = random(0, numberLeds);
  
  for (int i = 0; i < turn + 1; i++) {
    lightLED(plays[i]);
    delay(250);
  }
  
  int playerTurn = 0;
  
  while(playerTurn <= turn) {
    for (int i = 0; i < numberLeds; i++) {
      boolean pressed = !digitalRead(buttons[i]);
      
      if (pressed) {
        lightLED(i);
        
        if (plays[playerTurn] == i) {
          playerTurn++;
        } else {
          turn = -1;
          playStartSequence();
        }
        break;
      } 
    }
  }
  turn++;
  delay(250);
}

void lightLED(int i) {
  digitalWrite(leds[i], HIGH);
  tone(speaker, buttonsMelody[i], 500);
  delay(500);
  digitalWrite(leds[i], LOW);
}

void playStartSequence() {
  for (int i = 0; i < 13; i++) {
    tone(speaker, startMelody[i], startDuration[i]);
    delay(25);
  }
  
  for (int i = 0; i < numberLeds; i++) {
    digitalWrite(leds[i], HIGH);
  }
  
  delay(1000);
  
  for (int i = 0; i < numberLeds; i++) {
    digitalWrite(leds[i], LOW);
  }
}

