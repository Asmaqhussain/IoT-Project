#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;

const int potPin = 34;
const int servoPin = 5;

int sensorValue = 0;
int angle = 0;

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
}

void loop() {
  sensorValue = analogRead(potPin);


  angle = map(sensorValue, 0, 4095, 0, 180);

  myservo.write(angle);

  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print("  Servo angle: ");
  Serial.println(angle);

  delay(50);
}