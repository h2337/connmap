#include "network_monitor.hpp"

#include <cstdio>
#include <cstring>
#include <iostream>

namespace connmap {

NetworkMonitor::NetworkMonitor() {}

NetworkMonitor::~NetworkMonitor() { closeStream(); }

void NetworkMonitor::refresh() {
  closeStream();

  ss_output =
      popen("ss -atun4 | grep ESTAB | awk '{print $6}' | cut -f1 -d\":\"", "r");

  if (!ss_output) {
    std::cerr << "Failed to run ss command\n";
    throw std::runtime_error("Failed to run ss command");
  }
}

std::vector<std::string> NetworkMonitor::getConnections() {
  std::vector<std::string> connections;

  if (!ss_output) {
    return connections;
  }

  char ip[16];
  while (fgets(ip, sizeof(ip), ss_output) != nullptr) {
    ip[strcspn(ip, "\n")] = 0;

    if (strlen(ip) >= 7) {
      connections.push_back(std::string(ip));
    }
  }

  closeStream();
  return connections;
}

void NetworkMonitor::closeStream() {
  if (ss_output) {
    pclose(ss_output);
    ss_output = nullptr;
  }
}

}  // namespace connmap