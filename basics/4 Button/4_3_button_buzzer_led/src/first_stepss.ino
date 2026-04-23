#include <Arduino.h>

#define BUTTON_PIN 21
int LED_PIN = 4;
int BUZZER_PIN = 18;

int buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {   
    digitalWrite(BUZZER_PIN, HIGH); 
    digitalWrite(LED_PIN, LOW);    
  } else {
    digitalWrite(BUZZER_PIN, LOW); 
    digitalWrite(LED_PIN, HIGH);   
  }
}