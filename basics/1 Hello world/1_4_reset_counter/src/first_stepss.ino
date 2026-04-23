#include <Arduino.h>

int seconds = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(seconds);
  seconds++;

  if (seconds > 10) {
    seconds = 0;
  }

  delay(1000);
}