#pragma once

#include <cstdint>

namespace config {
struct WindowConfig {
  static constexpr uint16_t INITIAL_WIDTH = 1600;
  static constexpr uint16_t INITIAL_HEIGHT = 900;

  static constexpr uint16_t SMALL_FONT_SIZE = 15;
  static constexpr uint16_t MEDIUM_FONT_SIZE = 25;
  static constexpr uint16_t LARGE_FONT_SIZE = 35;

  static constexpr uint16_t FPS = 10;
  static constexpr float MAX_FRAME_TIME = 0.1;
};
}  // namespace config
