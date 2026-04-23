#include <Arduino.h>

const int sensorPin = 34;
const int ledPin = 2;

int sensorMin = 4095;
int sensorMax = 0;
int sensorValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  Serial.println("Calibration started...");
  Serial.println("Change the light level for 5 seconds.");

  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  Serial.println("Calibration finished.");
  Serial.print("Minimum light value: ");
  Serial.println(sensorMin);
  Serial.print("Maximum light value: ");
  Serial.println(sensorMax);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  Serial.print("Current sensor value: ");
  Serial.println(sensorValue);

 
  if (sensorValue >= sensorMax - 50) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}