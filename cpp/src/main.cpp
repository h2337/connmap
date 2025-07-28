#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

#include "cairo_renderer.hpp"
#include "config.hpp"
#include "ip_database.hpp"
#include "network_monitor.hpp"
#include "x11_window.hpp"

int main() {
  try {
    // Load configuration
    auto config = std::make_unique<connmap::Config>();
    if (!config->load()) {
      std::cerr << "Failed to load configuration\n";
      return 1;
    }

    // Initialize IP database
    if (!connmap::IPDatabase::getInstance().init()) {
      std::cerr << "Failed to initialize IP database\n";
      return 1;
    }

    // Create X11 window
    auto window = std::make_unique<connmap::X11Window>(
        config->getLocationX(), config->getLocationY(), config->getMapWidth(),
        config->getMapHeight());

    if (!window->init()) {
      std::cerr << "Failed to initialize X11 window\n";
      return 1;
    }

    // Create Cairo renderer
    auto renderer = std::make_unique<connmap::CairoRenderer>(
        window->getDisplay(), window->getWindow(),
        window->getVisualInfo().visual, config->getMapWidth(),
        config->getMapHeight());

    // Create network monitor
    auto monitor = std::make_unique<connmap::NetworkMonitor>();

    // Get map filename
    std::string mapFilename = config->getMapFilename();
    if (mapFilename.empty()) {
      std::cerr << "Failed to get map filename\n";
      return 1;
    }

    // Main loop
    while (true) {
      // Clear and draw world map
      renderer->clear();
      renderer->drawWorld(mapFilename);

      // Get network connections
      monitor->refresh();
      auto connections = monitor->getConnections();

      // Draw connection points
      for (const auto& ip : connections) {
        auto range = connmap::IPDatabase::getInstance().getCoordinates(ip);
        if (range.start != 0) {
          renderer->drawPoint(range.latitude, range.longitude);
        }
      }

      // Flush rendering
      renderer->flush();

      // Process window events
      window->processEvents();

      // Sleep based on drag state
      if (!window->isDragging()) {
        std::this_thread::sleep_for(
            std::chrono::seconds(config->getUpdateInterval()));
      } else {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
      }
    }

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}