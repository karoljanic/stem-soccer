#pragma once

#include <cstdint>

namespace config {
struct WindowConfig {
  static constexpr uint16_t WIDTH = 800;
  static constexpr uint16_t HEIGHT = 600;
  static constexpr uint16_t FPS = 60;
  static constexpr float MAX_FRAME_TIME = 0.25F;
};
} // namespace config
