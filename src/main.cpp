#include <Arduino.h>
#include <ArduinoLog.h>

#include "logging/RSLogging.h"
#include "screen/LCDScreen.h"


void printWelcomeLog();

void setup() {
  printWelcomeLog();
}

void printWelcomeLog()
{
    Serial.println();
    logger.infoln("==================================================");
    logger.infoln("====== Booted remote-sensor by wojteksz128 =======");
    logger.infoln("==================================================");

    screen.setCursor(3, 0);
    screen.print("hrt-sensor");
    screen.setCursor(1, 1);
    screen.print("by wojteksz128");

    delay(1000);
}

void loop() {
  logger.infoln(".");
  delay(1000);
}