#include <Arduino.h>

int ledPin = 4;

unsigned long previousMillis = 0;
int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (ledState == LOW && currentMillis - previousMillis >= 2000) {
    ledState = HIGH;
    previousMillis = currentMillis;
    digitalWrite(ledPin, ledState);
  }
  else if (ledState == HIGH && currentMillis - previousMillis >= 500) {
    ledState = LOW;
    previousMillis = currentMillis;
    digitalWrite(ledPin, ledState);
  }
}