#ifndef rs_network_accesspoint
#define rs_network_accesspoint

#include "AccessPointConfig.h"

class AccessPoint {
  private:
    AccessPointConfig apConfig;
  public:
    AccessPoint();
    AccessPoint(AccessPointConfig &apConfig);
    void run();
};

#endif  // rs_network_accesspoint
