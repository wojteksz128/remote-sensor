#include "LCDScreen.h"

static uint8_t checkCode[8] = { 0x00, 0x01, 0x03, 0x16, 0x1C, 0x08, 0x00, 0x00 };
static uint8_t crossCode[8] = { 0x00, 0x1B, 0x0E, 0x04, 0x0E, 0x1B, 0x00, 0x00 };
static uint8_t degreeCode[8] = { 0x02, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00 };
static uint8_t tempIconCode[8] = { 0x04, 0x06, 0x04, 0x06, 0x04, 0x0E, 0x0E, 0x00 };
static uint8_t pressureCode[8] = { 0x00, 0x04, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00 };
static uint8_t timeIconCode[8] = { 0x00, 0x00, 0x0E, 0x15, 0x17, 0x11, 0x0E, 0x00 };


LCDScreen::LCDScreen() : lcd(LiquidCrystal_I2C(0x3F, 16, 2))
{
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.createChar(CHECK, checkCode);
  lcd.createChar(CROSS, crossCode);
  lcd.createChar(DEGREE, degreeCode);
  lcd.createChar(TEMP_ICON, tempIconCode);
  lcd.createChar(PRESSURE, pressureCode);
  lcd.createChar(TIME_ICON, timeIconCode);
}

LCDScreen& LCDScreen::getInstance()
{
  static LCDScreen instance;
  return instance;
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