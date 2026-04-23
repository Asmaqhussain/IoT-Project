#include <Arduino.h>

const int ledPin = 2;

byte pattern = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  Serial.println("Enter 8-bit binary pattern (e.g., 10101010):");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');

  
    pattern = strtol(input.c_str(), NULL, 2);

    Serial.print("Pattern received: ");
    Serial.println(input);
  }

 
  for (int i = 7; i >= 0; i--) {
    int bitValue = (pattern >> i) & 1;

    digitalWrite(ledPin, bitValue);

    delay(300);
  }
}