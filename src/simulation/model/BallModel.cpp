#include "BallModel.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
BallModel::BallModel(const sf::Vector3i &initialPosition) :
	position{initialPosition} {}

void BallModel::update(float dt) {
  rotation += dt * config::SimulationConfig::BALL_ROTATION;
}

void BallModel::moveAbsolute(const sf::Vector3i &newPosition) {
  position = newPosition;
}

void BallModel::moveRelative(const sf::Vector3i &displacement) {
  position += displacement;
}

const sf::Vector3i &BallModel::getPosition() const {
  return position;
}

float BallModel::getRotation() const {
  return rotation;
}
} // namespace simulation
