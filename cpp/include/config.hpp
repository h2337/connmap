#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <cstdint>
#include <string>

namespace connmap {

constexpr const char* RCFILE = "/.config/connmap/connmaprc";
constexpr const char* RESOURCES = "/.config/connmap/resources/";
constexpr const char* IPV4FILE = "/.config/connmap/resources/ipv4.csv";

class Config {
 public:
  Config();
  bool load();

  uint32_t getLocationX() const { return location_x; }
  uint32_t getLocationY() const { return location_y; }
  uint32_t getMapWidth() const { return map_width; }
  uint32_t getMapHeight() const { return map_width / 2; }
  bool isBlackTheme() const { return black; }
  uint32_t getUpdateInterval() const { return update_interval; }
  std::string getMapFilename() const;

 private:
  uint32_t location_x = 0;
  uint32_t location_y = 0;
  uint32_t map_width = 500;
  bool black = false;
  uint32_t update_interval = 5;
};

}  // namespace connmap

#endif  // CONFIG_HPP