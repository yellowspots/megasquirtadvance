#include "LiquidCrystal_I2C.h"

#include <Wire.h>

int lcd_Columns = 20;
int lcd_Row = 4;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println();
  Serial.println("whattup im looking...");
  byte count = 0;
  Wire.begin();
  for(byte i = 8; i < 120; i++) {
      Wire.beginTransmission (i);
      if (Wire.endTransmission () == 0) {
        Serial.print("gotcha bitch:");
        Serial.print(i, DEC);
        Serial.print(" (0x");
        Serial.println(")");
        count++;
        delay(1);
      }
  }
  Serial.println("im done lol");
  Serial.print("eeeeehheeeee i found it ");
  Serial.print(count, DEC);
  Serial.println("device(s)");
  
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("butter dog...");
  delay(200);
}
