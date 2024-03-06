#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

namespace config {
struct WindowConfig {
  static constexpr uint16_t WIDTH = 1600;
  static constexpr uint16_t HEIGHT = 900;
  static constexpr uint16_t SMALL_FONT_SIZE = 15;
  static constexpr uint16_t MEDIUM_FONT_SIZE = 25;
  static constexpr uint16_t LARGE_FONT_SIZE = 35;
  static constexpr float SIMULATION_AREA_BLOCK_WIDTH = 90.0F;
  static constexpr float SIMULATION_AREA_BLOCK_HEIGHT = 52.0F;
  static constexpr uint16_t FPS = 10;
  static constexpr float MAX_FRAME_TIME = 0.25F;
};

static sf::Vector2f cartesianToIsometric(float xCoord, float yCoord) {
  return sf::Vector2f((xCoord - yCoord) * WindowConfig::SIMULATION_AREA_BLOCK_WIDTH / 2,
					  (xCoord + yCoord) * WindowConfig::SIMULATION_AREA_BLOCK_HEIGHT / 2);
}

static sf::Vector2f isometricToCartesian(float xCoord, float yCoord) {
  return sf::Vector2f(
	  xCoord / WindowConfig::SIMULATION_AREA_BLOCK_WIDTH + yCoord / WindowConfig::SIMULATION_AREA_BLOCK_HEIGHT,
	  yCoord / WindowConfig::SIMULATION_AREA_BLOCK_HEIGHT - xCoord / WindowConfig::SIMULATION_AREA_BLOCK_WIDTH);
}
} // namespace config
