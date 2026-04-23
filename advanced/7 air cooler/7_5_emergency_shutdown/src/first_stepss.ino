#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;

const int tempPin = 34;
const int servoPin = 5;
const int relayPin = 18;
const int touchPin = 4;

volatile bool shutdown = false;

// Interrupt Service Routine
void IRAM_ATTR emergencyStop() {
  shutdown = true;
}

void setup() {
  Serial.begin(115200);

  myservo.attach(servoPin);
  pinMode(relayPin, OUTPUT);
  pinMode(touchPin, INPUT_PULLUP);

  digitalWrite(relayPin, LOW);

  attachInterrupt(digitalPinToInterrupt(touchPin), emergencyStop, FALLING);

  Serial.println("System started");
  Serial.println("Press button for EMERGENCY SHUTDOWN");
}

void loop() {
  if (shutdown) {
    myservo.write(0);
    digitalWrite(relayPin, LOW);

    Serial.println("!!! EMERGENCY SHUTDOWN ACTIVATED !!!");

    while (true) {
      // Stay stopped forever
    }
  }

  int sensorValue = analogRead(tempPin);

  // Reverse mapping for this Wokwi NTC module
  float temperature = map(sensorValue, 4095, 0, 0, 50);

  int angle = map(temperature, 0, 50, 0, 180);
  angle = constrain(angle, 0, 180);

  myservo.write(angle);

  if (temperature > 28) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("   Relay: ");
  Serial.println(temperature > 28 ? "ON" : "OFF");

  delay(200);
}