#ifndef rs_configuration_configmanager
#define rs_configuration_configmanager

class ConfigManager
{
private:
	char *ssid;
	char *pass;

public:
	ConfigManager();
	~ConfigManager();
	
	bool load();
	bool save();
	bool reset();
	bool isDeviceConfigured();
	void getSSID(char *buf);
	void setSSID(const char *ssid);
	void getPassword(char *buf);
	void setPassword(const char *password);
};

#endif // rs_configuration_configmanager
