#include <Arduino.h>

const int POT_PIN = 34;
const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(POT_PIN);

  int brightness = map(value, 0, 4095, 0, 255);

  analogWrite(LED_PIN, brightness);

  delay(10);
}