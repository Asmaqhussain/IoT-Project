#include <Arduino.h>

#define BUTTON_PIN 21

int buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);
}