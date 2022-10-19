#include <ESP8266WiFi.h>

#include "AccessPoint.h"
#include "config_access_point.h"
#include "../configuration/config_global.h"
#include "../logging/config_logging.h"
#include "../screen/config_screen.h"

void printPreRunInfo(AccessPointConfig &apConfig);
void printPostRunInfo(AccessPointConfig &apConfig);

AccessPoint::AccessPoint() : apConfig(AccessPointConfig())
{
  apConfig.localIp = IPAddress(AP_DEFAULT_LOCAL_IP_PARTS);
  apConfig.gateway = IPAddress(AP_DEFAULT_GATEWAY_PARTS);
  apConfig.subnet = IPAddress(AP_DEFAULT_SUBNET_PARTS);
  apConfig.ssid = AP_DEFAULT_AP_SSID;
}

AccessPoint::AccessPoint(AccessPointConfig &apConfig) : apConfig(apConfig)
{ }

void AccessPoint::run() {
  printPreRunInfo(apConfig);
  WiFi.softAPConfig(apConfig.localIp, apConfig.gateway, apConfig.subnet);
  WiFi.softAP(apConfig.ssid);
  printPostRunInfo(apConfig);
}

void printPreRunInfo(AccessPointConfig &apConfig) {
  
  logger.infoln("----- Access Point Mode -----");
  logger.infoln("Init Local IP:\t%p", apConfig.localIp);
  logger.infoln("Init Gateway: \t%p", apConfig.gateway);
  logger.infoln("Init Subnet:  \t%p", apConfig.subnet);
  logger.infoln("Init SSID:    \t%s", apConfig.ssid);

  screen.clear();
  screen.setCursor(0, 0);
  screen.print("Starting AP...");
}

void printPostRunInfo(AccessPointConfig &apConfig) {
  logger.infoln("Access Point \"%s\" started", apConfig.ssid);

  IPAddress apid = WiFi.softAPIP();
  logger.infoln("IP address:   \t%p", apid);

  screen.clear();
  screen.setCursor(0, 0);
  screen.print("AP ");
  screen.print(String(apConfig.ssid));
  screen.setCursor(0, 1);
  screen.print("started.");
  screen.setCursor(15, 1);
  screen.write(CHECK);
}

AccessPoint ap;