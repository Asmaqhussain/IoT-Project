#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;

void setup() {
  Serial.begin(115200);
  myServo.attach(5);
  Serial.println("Enter angle (0-180):");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int angle = input.toInt();
    angle = constrain(angle, 0, 180);
    myServo.write(angle);

    Serial.print("Moved to: ");
    Serial.println(angle);
  }
}