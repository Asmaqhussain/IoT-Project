#include <Arduino.h>

const int POT_PIN = 34;
const int BUZZER_PIN = 5;

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int frequency = map(potValue, 0, 4095, 200, 1000);

  tone(BUZZER_PIN, frequency);

  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print("  Freq: ");
  Serial.println(frequency);

  delay(100);
}