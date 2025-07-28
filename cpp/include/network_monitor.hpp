#ifndef NETWORK_MONITOR_HPP
#define NETWORK_MONITOR_HPP

#include <memory>
#include <string>
#include <vector>

namespace connmap {

class NetworkMonitor {
 public:
  NetworkMonitor();
  ~NetworkMonitor();

  void refresh();
  std::vector<std::string> getConnections();

 private:
  FILE* ss_output = nullptr;
  void closeStream();
};

}  // namespace connmap

#endif  // NETWORK_MONITOR_HPP