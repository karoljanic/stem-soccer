#include "Utils.hpp"
#include "../config/SimulationConfig.hpp"

namespace simulation {
static sf::Vector2f cartesianToIsometric(sf::Vector2f cartesianCoord) {
  return sf::Vector2f((cartesianCoord.x - cartesianCoord.y) * config::SimulationConfig::STADIUM_BLOCK_WIDTH / 2,
					  (cartesianCoord.x + cartesianCoord.y) * config::SimulationConfig::STADIUM_BLOCK_HEIGHT / 2);
}

static sf::Vector2f isometricToCartesian(sf::Vector2f isometricCoord) {
  return sf::Vector2f(isometricCoord.x / config::SimulationConfig::STADIUM_BLOCK_WIDTH
						  + isometricCoord.y / config::SimulationConfig::STADIUM_BLOCK_HEIGHT,
					  isometricCoord.y / config::SimulationConfig::STADIUM_BLOCK_HEIGHT
						  - isometricCoord.x / config::SimulationConfig::STADIUM_BLOCK_WIDTH);
}
} // namespace simulation
