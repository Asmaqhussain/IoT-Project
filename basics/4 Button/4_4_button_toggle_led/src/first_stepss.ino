#include <Arduino.h>

#define BUTTON_PIN 21
int LED_PIN = 4;

int buttonState;
int lastButtonState = HIGH;
bool ledState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    delay(200);
  }

  lastButtonState = buttonState;
}