#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;

const int tempPin = 34;
const int servoPin = 5;
const int relayPin = 18;

void setup() {
  Serial.begin(115200);

  myservo.attach(servoPin);
  pinMode(relayPin, OUTPUT);

  digitalWrite(relayPin, LOW);  
}

void loop() {
  int sensorValue = analogRead(tempPin);


  float temperature = map(sensorValue, 4095, 0, 0, 50);

  int angle = map(temperature, 0, 50, 0, 180);
  angle = constrain(angle, 0, 180);

  myservo.write(angle);

  if (temperature > 28) {
    digitalWrite(relayPin, HIGH); 
  } else {
    digitalWrite(relayPin, LOW);   
  }

  Serial.print("Sensor: ");
  Serial.print(sensorValue);
  Serial.print("   Temp (approx): ");
  Serial.print(temperature);
  Serial.print(" °C   Angle: ");
  Serial.print(angle);
  Serial.print("   Relay: ");

  if (temperature > 28) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

  delay(200);
}