#include <Arduino.h>
#include <ArduinoLog.h>

#include "logging/RSLogging.h"


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

    delay(1000);
}

void loop() {
  logger.infoln(".");
  delay(1000);
}