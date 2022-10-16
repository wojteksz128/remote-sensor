#include <Arduino.h>
#include <ArduinoLog.h>

#include "logging/config.h"

void setup() {
  setupLogging();
  printWelcomeLog();
}

void loop() {
  Log.infoln(".");
  delay(1000);
}