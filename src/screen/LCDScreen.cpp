#include "LCDScreen.h"
#include "../configuration/config_global.h"

LCDScreen::LCDScreen() : lcd(LiquidCrystal_I2C(LCD_ADDRESS, LCD_COLS, LCD_ROWS))
{
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.createChar(CHECK, CHECK_LAYOUT);
  lcd.createChar(CROSS, CROSS_LAYOUT);
  lcd.createChar(DEGREE, DEGREE_LAYOUT);
  lcd.createChar(TEMP_ICON, TEMP_ICON_LAYOUT);
  lcd.createChar(PRESSURE, PRESSURE_LAYOUT);
  lcd.createChar(TIME_ICON, TIME_ICON_LAYOUT);
}

void LCDScreen::clear() {
  lcd.clear();
}

void LCDScreen::home() {
  lcd.home();
}

void LCDScreen::noDisplay() {
  lcd.noDisplay();
}

void LCDScreen::display() {
  lcd.display();
}

void LCDScreen::noBlink() {
  lcd.noBlink();
}

void LCDScreen::blink() {
  lcd.blink();
}

void LCDScreen::noCursor() {
  lcd.noCursor();
}

void LCDScreen::cursor() {
  lcd.cursor();
}

void LCDScreen::scrollDisplayLeft() {
  lcd.scrollDisplayLeft();
}

void LCDScreen::scrollDisplayRight() {
  lcd.scrollDisplayRight();
}

void LCDScreen::printLeft() {
  lcd.printLeft();
}

void LCDScreen::printRight() {
  lcd.printRight();
}

void LCDScreen::leftToRight() {
  lcd.leftToRight();
}

void LCDScreen::rightToLeft() {
  lcd.rightToLeft();
}

void LCDScreen::shiftIncrement() {
  lcd.shiftIncrement();
}

void LCDScreen::shiftDecrement() {
  lcd.shiftDecrement();
}

void LCDScreen::noBacklight() {
  lcd.noBacklight();
}

void LCDScreen::backlight() {
  lcd.backlight();
}

void LCDScreen::autoscroll() {
  lcd.autoscroll();
}

void LCDScreen::noAutoscroll() {
  lcd.noAutoscroll();
}

void LCDScreen::setCursor(uint8_t col, uint8_t row) {
  lcd.setCursor(col, row);
}


#if defined(ARDUINO) && ARDUINO >= 100
inline size_t LCDScreen::write(uint8_t value) {
  return lcd.write(value);
}

#else
inline void LCDScreen::write(uint8_t value) {
  lcd.write(value);
}

void LCDScreen::blink_on() {
  blink();
}

void LCDScreen::blink_off() {
  noBlink();
}

void LCDScreen::cursor_on() {
  cursor();
}

void LCDScreen::cursor_off() {
  noCursor()
}

void LCDScreen::setBacklight(uint8_t new_val) {
  lcd.setBacklight(new_val);
}

void LCDScreen::printstr(const char c[]) {
  print(c);
}

#endif

LCDScreen screen;