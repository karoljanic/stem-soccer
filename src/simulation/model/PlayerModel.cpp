#include "PlayerModel.hpp"

namespace simulation {
PlayerModel::PlayerModel(const sf::Vector3i &initialPosition) :
	position{initialPosition} {}

void PlayerModel::update(float dt) {}

void PlayerModel::moveAbsolute(const sf::Vector3i &newPosition) {
  position = newPosition;
}

void PlayerModel::moveRelative(const sf::Vector3i &displacement) {
  position += displacement;
}

const sf::Vector3i &PlayerModel::getPosition() const {
  return position;
}

PlayerModel::AnimationState PlayerModel::getAnimationFrame() const {
  return animationFrame;
}
} // namespace simulation
