#include <Arduino.h>

const int POT_PIN = 34;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("STARTED");
}

void loop() {
  int value = analogRead(POT_PIN);
  Serial.print("Value: ");
  Serial.println(value);
  delay(300);
}