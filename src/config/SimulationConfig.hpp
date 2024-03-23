#pragma once

#include <cstdint>

namespace config {
struct SimulationConfig {
  static constexpr uint16_t STADIUM_WIDTH = 41;
  static constexpr uint16_t STADIUM_LENGTH = 61;
  static constexpr uint16_t STADIUM_HEIGHT = 15;
  static constexpr uint16_t PITCH_WIDTH = 23;
  static constexpr uint16_t PITCH_LENGTH = 37;
  static constexpr uint16_t GOAL_WIDTH = 5;
  static constexpr uint16_t GOALKEEPER_FIELD_LENGTH = 5;
  static constexpr uint16_t GOALKEEPER_FIELD_WIDTH = 11;

  static constexpr uint16_t STADIUM_BLOCK_WIDTH = 45.0F;
  static constexpr uint16_t STADIUM_BLOCK_HEIGHT = 26.0F;
  static constexpr float STADIUM_BLOCK_SCALE = 0.5F;

  static constexpr float BALL_SCALE = 0.3F;
  static constexpr float BALL_ROTATION = 50.0F;

  static constexpr uint16_t PLAYER_WALK_WIDTH = 15;
  static constexpr int16_t PLAYER_NO_WALK_WIDTH = 13;
  static constexpr uint16_t PLAYER_HEIGHT = 19;
  static constexpr float PLAYER_SCALE = 2.5F;

  static constexpr uint8_t PLAYER_MOVE_ANIMATION_FRAMES = 5;
  static constexpr float PLAYER_MOVE_ANIMATION_TRANSLATION = 0.2F;
};
} // namespace config
