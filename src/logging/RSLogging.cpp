#include <ArduinoLog.h>

#include "RSLogging.h"
#include "../config_global.h"


#define MSECS_PER_SEC               1000
#define SECS_PER_MIN                60
#define SECS_PER_HOUR               3600
#define SECS_PER_DAY                86400


void printPrefix(Print* _logOutput, int logLevel);
void printTimestamp(Print* _logOutput);
void printLogLevel(Print* _logOutput, int logLevel);

RSLogging::RSLogging()
{
    Serial.begin(SERIAL_BAUD_RATE);
    this->begin(LOG_LEVEL, &Serial);
    this->setPrefix(printPrefix);
    this->setShowLevel(false);
}

void printPrefix(Print* _logOutput, int logLevel)
{
    printTimestamp(_logOutput);
    printLogLevel(_logOutput, logLevel);
}

void printTimestamp(Print* _logOutput)
{
    // Total time
    const unsigned long msecs               =  millis();
    const unsigned long secs                =  msecs / MSECS_PER_SEC;

    // Time in components
    const unsigned short MilliSeconds        =  msecs % MSECS_PER_SEC;
    const unsigned short Seconds             =  secs  % SECS_PER_MIN ;
    const unsigned short Minutes             = (secs  / SECS_PER_MIN) % SECS_PER_MIN;
    const unsigned short Hours               = (secs  % SECS_PER_DAY) / SECS_PER_HOUR;

  // Time as string
  char timestamp[20];
  sprintf(timestamp, "%02u:%02u:%02u.%03u ", Hours, Minutes, Seconds, MilliSeconds);
  _logOutput->print(timestamp);
}

void printLogLevel(Print* _logOutput, int logLevel)
{
    /// Show log description based on log level
    switch (logLevel)
    {
        default:
        case 0:_logOutput->print("SILENT " ); break;
        case 1:_logOutput->print("FATAL "  ); break;
        case 2:_logOutput->print("ERROR "  ); break;
        case 3:_logOutput->print("WARNING "); break;
        case 4:_logOutput->print("INFO "   ); break;
        case 5:_logOutput->print("TRACE "  ); break;
        case 6:_logOutput->print("VERBOSE "); break;
    }   
}

RSLogging logger;