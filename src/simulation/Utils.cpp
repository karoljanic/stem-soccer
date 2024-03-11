#include "Utils.hpp"
#include "../config/SimulationConfig.hpp"

namespace simulation {
sf::Vector2f cartesianToIsometric(sf::Vector3i cartesianCoord) {
  return sf::Vector2f(
	  static_cast<float>(cartesianCoord.x - cartesianCoord.y) * config::SimulationConfig::STADIUM_BLOCK_WIDTH / 2,
	  static_cast<float>(cartesianCoord.x + cartesianCoord.y) * config::SimulationConfig::STADIUM_BLOCK_HEIGHT / 2);
}

sf::Vector3i isometricToCartesian(sf::Vector2f isometricCoord) {
  return sf::Vector3i(static_cast<int>(isometricCoord.x / config::SimulationConfig::STADIUM_BLOCK_WIDTH
						  + isometricCoord.y / config::SimulationConfig::STADIUM_BLOCK_HEIGHT),
					  static_cast<int>(isometricCoord.y / config::SimulationConfig::STADIUM_BLOCK_HEIGHT
						  - isometricCoord.x / config::SimulationConfig::STADIUM_BLOCK_WIDTH), 0);
}
} // namespace simulation
