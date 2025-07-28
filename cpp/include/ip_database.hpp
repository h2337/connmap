#ifndef IP_DATABASE_HPP
#define IP_DATABASE_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace connmap {

struct IPRange {
  uint32_t start;
  uint32_t end;
  double latitude;
  double longitude;
};

class IPDatabase {
 public:
  static IPDatabase& getInstance();

  bool init();
  IPRange getCoordinates(const std::string& ip) const;

 private:
  IPDatabase() = default;
  ~IPDatabase() = default;
  IPDatabase(const IPDatabase&) = delete;
  IPDatabase& operator=(const IPDatabase&) = delete;

  uint32_t ipToUint32(const std::string& ip) const;

  std::vector<IPRange> ranges;
  bool initialized = false;
};

}  // namespace connmap

#endif  // IP_DATABASE_HPP