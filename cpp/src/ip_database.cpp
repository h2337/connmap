#include "ip_database.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#include "config.hpp"

namespace connmap {

IPDatabase& IPDatabase::getInstance() {
  static IPDatabase instance;
  return instance;
}

bool IPDatabase::init() {
  if (initialized) return true;

  const char* home = std::getenv("HOME");
  if (!home) {
    std::cerr << "HOME environment variable not set\n";
    return false;
  }

  std::string ipv4File = std::string(home) + IPV4FILE;

  // Read IP ranges with coordinates
  std::ifstream ipFile(ipv4File);
  if (!ipFile.is_open()) {
    std::cerr << "Failed to open IP database file: " << ipv4File << "\n";
    return false;
  }

  std::string line;
  while (std::getline(ipFile, line)) {
    std::istringstream iss(line);
    std::string startStr, endStr, latStr, lonStr;

    if (std::getline(iss, startStr, ',') && std::getline(iss, endStr, ',') &&
        std::getline(iss, latStr, ',') && std::getline(iss, lonStr, ',')) {
      IPRange range;
      range.start = std::stoul(startStr);
      range.end = std::stoul(endStr);
      range.latitude = std::stod(latStr);
      range.longitude = std::stod(lonStr);
      ranges.push_back(range);
    }
  }
  ipFile.close();

  initialized = true;
  return true;
}

IPRange IPDatabase::getCoordinates(const std::string& ip) const {
  if (!initialized) {
    return {0, 0, 0, 0};
  }

  uint32_t ipNum = ipToUint32(ip);

  // Binary search for the IP range
  auto it = std::lower_bound(
      ranges.begin(), ranges.end(), ipNum,
      [](const IPRange& range, uint32_t value) { return range.end < value; });

  if (it != ranges.end() && ipNum >= it->start && ipNum <= it->end) {
    return *it;
  }

  return {0, 0, 0, 0};
}

uint32_t IPDatabase::ipToUint32(const std::string& ip) const {
  std::istringstream iss(ip);
  std::string part;
  uint32_t result = 0;
  int shift = 24;

  while (std::getline(iss, part, '.') && shift >= 0) {
    result |= (std::stoul(part) << shift);
    shift -= 8;
  }

  return result;
}

}  // namespace connmap