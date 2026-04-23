#include <Arduino.h>

int ledPin = 4;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, 255);
  delay(1000);

  analogWrite(ledPin, 0);
  delay(1000);
}