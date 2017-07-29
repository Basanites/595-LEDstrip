#include "Arduino.h"

uint8_t dataPin = 8;
uint8_t clockPin = 9;
uint8_t latchPin = 10;

void setup() {
  // set shift register pins as OUTPUT
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  // pull all pins LOW to avoid weird behaviour
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
}

void loop() {
  for (size_t i = 0; i < 8; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 1 << i);
    digitalWrite(latchPin, HIGH);
    delay(100);
  }
  for (size_t i = 0; i < 8; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, 128 >> i);
    digitalWrite(latchPin, HIGH);
    delay(100);
  }
}
