#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int rxPin = 8; 
const int txPin = 9; 
SoftwareSerial bluetooth(rxPin, txPin);
void setup() {
  lcd.begin(16, 2);
  bluetooth.begin(9600);
}
void loop() {
  if (bluetooth.available()) {
    char receivedChar = bluetooth.read();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bluetooth: ");
    lcd.setCursor(0, 1);
    lcd.print(receivedChar);
  }
}
