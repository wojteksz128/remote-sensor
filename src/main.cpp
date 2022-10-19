#include <Arduino.h>
#include <ArduinoLog.h>

#include "logging/config_logging.h"
#include "screen/config_screen.h"
#include "network/config_network_manager.h"

void printWelcomeLog();

void setup()
{
	printWelcomeLog();
	networkManager.configure();
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

void loop()
{
	logger.infoln(".");
	delay(1000);
}