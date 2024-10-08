#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int button1Pin = 8;
const int button2Pin = 9;  

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  lcd.setCursor(0, 0); 
  lcd.print("LCD1602"); 
  lcd.setCursor(1, 1); 
  lcd.print("start");

  if (button1State == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("I2C LCD"); 
    lcd.setCursor(1, 1); 
    lcd.print("che do 1");
    delay(3000);
    lcd.clear();
  }

  if (button2State == HIGH) {
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("I2C LCD"); 
    lcd.setCursor(1, 1); 
    lcd.print("che do 2");
    delay(3000);
    lcd.clear();
  }
}


