#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4);
int pinA = 2, pinB = 3, pinSW = 4;  //CLK,DT,SW
int val0 = 0, val1 = 0;
int valSW;
int i = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinSW, INPUT_PULLUP);
  //-------------------------------
  lcd.setCursor(0, 0);
  lcd.print("Menu: > Music");
  lcd.setCursor(0, 1);
  lcd.print("        Picture");
  lcd.setCursor(0, 2);
  lcd.print("        Video");
  lcd.setCursor(0, 3);
  lcd.print("        Next");
  //-------------------------------
}
void loop() {
  valSW = digitalRead(pinSW);
  if (valSW == LOW) {
    while (digitalRead(pinSW) == LOW)
      ;
    Tone();
  }
  val1 = digitalRead(pinA);
  if (val1 != val0) {
    if (digitalRead(pinB) != val1) {
      i++;
      if (i >= 3) {
        i = 3;
      }
    } else {
      i--;
      if (i <= 0) {
        i = 0;
      }
    }
    switch (i) {
      case 0:
        if (i == 0) {
          menu1();
          Tone();
        }
        break;
      case 1:
        if (i == 1) {
          menu2();
          Tone();
        }
        break;
      case 2:
        if (i == 2) {
          menu3();
          Tone();
        }
        break;
      case 3:
        if (i == 3) {
          menu4();
          Tone();
        }
        break;
    }
    //----------------------------------------
  }
  val0 = val1;
}
//----------------------------------------
void menu1() {
  lcd.setCursor(0, 0);
  lcd.print("Menu: > Music");
  lcd.setCursor(0, 1);
  lcd.print("        Picture");
  lcd.setCursor(0, 2);
  lcd.print("        Video");
  lcd.setCursor(0, 3);
  lcd.print("        Next");
  if(valSW == LOW){
    //
  }
}
void menu2() {
  lcd.setCursor(0, 0);
  lcd.print("Menu:   Music");
  lcd.setCursor(0, 1);
  lcd.print("      > Picture");
  lcd.setCursor(0, 2);
  lcd.print("        Video");
  lcd.setCursor(0, 3);
  lcd.print("        Next");
}
void menu3() {
  lcd.setCursor(0, 0);
  lcd.print("Menu:   Music");
  lcd.setCursor(0, 1);
  lcd.print("        Picture");
  lcd.setCursor(0, 2);
  lcd.print("      > Video");
  lcd.setCursor(0, 3);
  lcd.print("        Next");
}
void menu4() {
  lcd.setCursor(0, 0);
  lcd.print("Menu:   Music");
  lcd.setCursor(0, 1);
  lcd.print("        Picture");
  lcd.setCursor(0, 2);
  lcd.print("        Video");
  lcd.setCursor(0, 3);
  lcd.print("      > Next");
}
void Tone() {
  tone(5, 2000, 50);
}
void Music(){
  //
}
//-----------------------End Program Main---------------------
//-----------------------Note Data----------------------------
// val = digitalRead(pinSW);
// if (val == 0) {
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Music: > Thame");
//   lcd.setCursor(0, 1);
//   lcd.print("         Title");
//   lcd.setCursor(0, 2);
//   lcd.print("         Repeat");
//   lcd.setCursor(0, 3);
//   lcd.print("         Next");
// }
// val = 0;
//-----------------------End Note Data------------------------