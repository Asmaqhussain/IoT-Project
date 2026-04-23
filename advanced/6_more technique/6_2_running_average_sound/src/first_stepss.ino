#include <Arduino.h>

const int inputPin = 34;     
const int numReadings = 10;  

int readings[numReadings];   
int readIndex = 0;      
long total = 0;            
int average = 0;            
void setup() {
  Serial.begin(115200);

 
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }

  Serial.println("Running average of 10 values");
}

void loop() {
 
  total = total - readings[readIndex];


  readings[readIndex] = analogRead(inputPin);

  total = total + readings[readIndex];


  readIndex = (readIndex + 1) % numReadings;


  average = total / numReadings;

 
  Serial.print("Raw: ");
  Serial.print(readings[(readIndex + numReadings - 1) % numReadings]);
  Serial.print("   Average: ");
  Serial.println(average);

  delay(20);
}