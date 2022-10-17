#ifndef rs_logging_rslogging
#define rs_logging_rslogging

#include <ArduinoLog.h>

class RSLogging : public Logging
{
public:
    RSLogging();
};

extern RSLogging logger;

#endif  // rs_logging_rslogging