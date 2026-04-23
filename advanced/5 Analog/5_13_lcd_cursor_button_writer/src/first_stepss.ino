#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int POT_PIN = 34;
const int BUTTON_PIN = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

int lastButtonState = HIGH;
int lastColumn = -1;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("Cursor:");
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int column = map(potValue, 0, 4095, 0, 15);

  if (column != lastColumn) {
    lcd.setCursor(8, 1);
    lcd.print("   ");
    lcd.setCursor(8, 1);
    lcd.print(column);
    lastColumn = column;
  }

  int buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    lcd.setCursor(column, 0);
    lcd.print("*");
  }

  lastButtonState = buttonState;
  delay(50);
}