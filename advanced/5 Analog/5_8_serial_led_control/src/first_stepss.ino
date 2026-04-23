#include <Arduino.h>

const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.read(); 
    digitalWrite(LED_PIN, HIGH);
  }
}