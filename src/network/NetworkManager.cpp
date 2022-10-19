#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>

#include "config_access_point.h"
#include "config_network_manager.h"
#include "network_utils.h"
#include "NetworkManager.h"
#include "../configuration/config_config_manager.h"
#include "../configuration/config_global.h"
#include "../logging/config_logging.h"
#include "../screen/config_screen.h"

bool NetworkManager::loadConfiguration() {
  if (!configManager.load()) {
    logger.warningln("Settings cannot be loaded.");
  } else {
    logger.infoln("Settings loaded.");
  }

  return configManager.isDeviceConfigured();
}

void NetworkManager::connectWithNetwork(bool configLoaded) {
  if (!configLoaded) {
    return;
  }
  
  char ssid[64], pass[64];
  configManager.getSSID(ssid);
  configManager.getPassword(pass);

  WiFi.begin(ssid, pass);
  logger.info("Connecting");

  screen.clear();
  screen.setCursor(0, 0);
  screen.print("Connecting");

  uint8_t tryCounter = 0;
  while (WiFi.status() != WL_CONNECTED 
  && tryCounter <= NETWORK_CONNECT_TIMEOUT * NETWORK_DOTS_EVERY_SECOND) {
    delay(1000/NETWORK_DOTS_EVERY_SECOND);
    Serial.print(".");
    if (tryCounter % 3 == 0) {
      screen.setCursor(10, 0);
      screen.print("   ");
      screen.setCursor(10, 0);
    }
    screen.print(".");
    ++tryCounter;
  }
  
  Serial.println();

  if (WiFi.status() != WL_CONNECTED) {
    logger.errorln("Device cannot connect with any network around");
    screen.setCursor(15, 0);
    screen.write(CROSS);
    return;
  }
  logger.infoln("Connected to %S", WiFi.SSID());
  logger.infoln("IP address:\t%p", WiFi.localIP());

  screen.clear();
  screen.setCursor(0, 0);
  screen.print("Connected to");
  screen.setCursor(15, 0);
  screen.write(CHECK);
  screen.setCursor(0, 1);
  screen.print(WiFi.SSID());
  
  networkType = EXTERNAL_NETWORK;
}

void NetworkManager::runAccessPoint() {
    resetWifi();
    ap.run();
    networkType = ACCESS_POINT;
}

void NetworkManager::configure_mDNS() {
  if (!MDNS.begin("hrt-sensor")) {
    logger.errorln("Error setting up MDNS responder!");
  }
  logger.infoln("mDNS responder started");
}

NetworkManager::NetworkManager() {

}

void NetworkManager::configure() {
  bool configLoaded = loadConfiguration();
  connectWithNetwork(configLoaded);

  delay(1000);

  if (networkType == NONE) {
    runAccessPoint();
  }

  delay(1000);

  configure_mDNS();
}

NetworkType NetworkManager::getNetworkType() {
  return networkType;
}

NetworkManager networkManager;