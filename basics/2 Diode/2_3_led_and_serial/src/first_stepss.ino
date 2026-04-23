#include <Arduino.h>

int ledPin = 4;

unsigned long previousMillis = 0;
unsigned long previousSecond = 0;

int ledState = LOW;
int seconds = 0;

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

  if (currentMillis - previousSecond >= 1000) {
    previousSecond = currentMillis;
    seconds++;

    Serial.print("Seconds: ");
    Serial.println(seconds);
  }
}