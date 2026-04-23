#include <Arduino.h>

int seconds = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(seconds);
  seconds++;
  delay(1000);
}