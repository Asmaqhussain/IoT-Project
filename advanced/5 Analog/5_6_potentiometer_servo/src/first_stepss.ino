#include <Arduino.h>
#include <ESP32Servo.h>

const int POT_PIN = 34;

Servo myservo;

void setup() {
  myservo.attach(5);
}

void loop() {
  int value = analogRead(POT_PIN);

 
  int angle = map(value, 0, 4095, 0, 180);

  myservo.write(angle);

  delay(20);
}