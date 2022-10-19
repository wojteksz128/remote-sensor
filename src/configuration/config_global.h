#ifndef rs_config_global
#define rs_config_global

#include <ArduinoLog.h>

// ============= Configuration loading ==============

#define CONFIG_FILE_PATH        "/config.json"
#define CONFIG_SSID_LABEL       "ssid"
#define CONFIG_PASS_LABEL       "pass"

// ============= Network configuration ==============

#define AP_DEFAULT_LOCAL_IP_PARTS        192,168,1,1
#define AP_DEFAULT_GATEWAY_PARTS         192,168,1,1
#define AP_DEFAULT_SUBNET_PARTS          255,255,255,0
#define AP_DEFAULT_AP_SSID               (char*)"remote-sensor Config"

// =========== Logging configuration ================

#define SERIAL_BAUD_RATE        115200

#define LOG_LEVEL               LOG_LEVEL_NOTICE

// ========= LCD Screen configuration ===============

#define LCD_ADDRESS             0x3F
#define LCD_COLS                16
#define LCD_ROWS                2

#define CHECK                   0
#define CROSS                   1
#define DEGREE                  2
#define TEMP_ICON               3
#define PRESSURE                4
#define TIME_ICON               5

#define CHECK_LAYOUT            new uint8_t[8] { 0x00, 0x01, 0x03, 0x16, 0x1C, 0x08, 0x00, 0x00 }
#define CROSS_LAYOUT            new uint8_t[8] { 0x00, 0x1B, 0x0E, 0x04, 0x0E, 0x1B, 0x00, 0x00 }
#define DEGREE_LAYOUT           new uint8_t[8] { 0x02, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00 }
#define TEMP_ICON_LAYOUT        new uint8_t[8] { 0x04, 0x06, 0x04, 0x06, 0x04, 0x0E, 0x0E, 0x00 }
#define PRESSURE_LAYOUT         new uint8_t[8] { 0x00, 0x04, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00 }
#define TIME_ICON_LAYOUT        new uint8_t[8] { 0x00, 0x00, 0x0E, 0x15, 0x17, 0x11, 0x0E, 0x00 }

#endif  // rs_config_global