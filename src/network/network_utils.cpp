#include <ESP8266WiFi.h>

#include "network_utils.h"

void resetWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}