#ifndef rs_network_accesspointconfig
#define rs_network_accesspointconfig

#include <IPAddress.h>

struct AccessPointConfig {
  IPAddress localIp;
  IPAddress gateway;
  IPAddress subnet;
  char *ssid;
};

#endif  // rs_network_accesspointconfig
