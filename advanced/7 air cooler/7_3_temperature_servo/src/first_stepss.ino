#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;

const int tempPin = 34;
const int servoPin = 5;

void setup() {
  Serial.begin(115200);
  myservo.attach(servoPin);
}

void loop() {
  int sensorValue = analogRead(tempPin);

 
  float temperature = map(sensorValue, 4095, 0, 0, 50);

  int angle = map(temperature, 0, 50, 0, 180);
  angle = constrain(angle, 0, 180);

  myservo.write(angle);

  Serial.print("Temp (approx): ");
  Serial.print(temperature);
  Serial.print(" °C   Angle: ");
  Serial.println(angle);

  delay(200);
}