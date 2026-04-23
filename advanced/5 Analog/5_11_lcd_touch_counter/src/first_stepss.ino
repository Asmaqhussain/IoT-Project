#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int BUTTON_PIN = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;
int lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Touch Counter");
  lcd.setCursor(0, 1);
  lcd.print("Count: 0");
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    counter++;

    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(counter);
    lcd.print("   ");
  }

  lastButtonState = buttonState;
  delay(50);
}