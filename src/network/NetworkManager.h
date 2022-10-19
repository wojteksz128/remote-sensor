#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H


enum NetworkType {
  NONE, EXTERNAL_NETWORK, ACCESS_POINT
};

class NetworkManager {
  private:
    NetworkType networkType = NONE;
    bool loadConfiguration();
    void connectWithNetwork(bool configLoaded);
    void runAccessPoint();
    void configure_mDNS();
  public:
    NetworkManager();
    void configure();
    NetworkType getNetworkType();
};

#endif  // NETWORK_MANAGER_H