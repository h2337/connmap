#include "config.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

namespace connmap {

Config::Config() {}

bool Config::load() {
  const char* home = std::getenv("HOME");
  if (!home) {
    std::cerr << "HOME environment variable not set\n";
    return false;
  }

  std::string filename = std::string(home) + RCFILE;
  std::ifstream configFile(filename);

  if (!configFile.is_open()) {
    std::cerr << "Failed to open the config file: " << filename << "\n";
    return false;
  }

  std::string line;
  while (std::getline(configFile, line)) {
    std::istringstream iss(line);
    std::string name, value;

    if (iss >> name >> value) {
      if (name == "location_x") {
        location_x = std::stoul(value);
      } else if (name == "location_y") {
        location_y = std::stoul(value);
      } else if (name == "map_width") {
        map_width = std::stoul(value);
      } else if (name == "black") {
        black = (value == "true");
      } else if (name == "update_interval") {
        update_interval = std::stoul(value);
      }
    }
  }

  configFile.close();
  return true;
}

std::string Config::getMapFilename() const {
  const char* home = std::getenv("HOME");
  if (!home) {
    return "";
  }

  std::string mapName = black ? "w1000b.png" : "w1000.png";
  return std::string(home) + RESOURCES + mapName;
}

}  // namespace connmap