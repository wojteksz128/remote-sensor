#include <ArduinoJson.h>
#include <LittleFS.h>

#include "ConfigManager.h"
#include "config_global.h"
#include "config_config_manager.h"

ConfigManager::ConfigManager()
{
	LittleFS.begin();
	this->ssid = new char[64];
	this->pass = new char[64];
}

ConfigManager::~ConfigManager()
{
	delete[] this->ssid;
	delete[] this->pass;
}

bool ConfigManager::load()
{
	File configFile = LittleFS.open(CONFIG_FILE_PATH, "r");
	if (!configFile)
	{
		return false;
	}

	size_t size = configFile.size();

	char *buf = new char[size];

	configFile.readBytes(buf, size);

	StaticJsonDocument<200> jsonDocument;
	DeserializationError error = deserializeJson(jsonDocument, buf);

	if (error)
	{
		delete buf;
		return false;
	}

	const char *ssid = jsonDocument[CONFIG_SSID_LABEL];
	strcpy(this->ssid, ssid);
	const char *pass = jsonDocument[CONFIG_PASS_LABEL];
	strcpy(this->pass, pass);

	delete buf;
	configFile.close();
	return true;
}

bool ConfigManager::save()
{
	StaticJsonDocument<200> jsonDocument;
	JsonObject json = jsonDocument.to<JsonObject>();
	json[CONFIG_SSID_LABEL] = this->ssid;
	json[CONFIG_PASS_LABEL] = this->pass;

	File configFile = LittleFS.open(CONFIG_FILE_PATH, "w");
	if (!configFile)
	{
		return false;
	}
	serializeJson(jsonDocument, configFile);
	configFile.close();
	return true;
}

bool ConfigManager::reset()
{
	setSSID("");
	setPassword("");
	return save();
}

bool ConfigManager::isDeviceConfigured()
{
	return this->ssid[0] != '\0';
}

void ConfigManager::getSSID(char *buf)
{
	strcpy(buf, this->ssid);
}

void ConfigManager::setSSID(const char *ssid)
{
	strcpy(this->ssid, ssid);
}

void ConfigManager::getPassword(char *buf)
{
	strcpy(buf, this->pass);
}

void ConfigManager::setPassword(const char *password)
{
	strcpy(this->pass, password);
}

ConfigManager configManager;