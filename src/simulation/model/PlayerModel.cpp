#include "PlayerModel.hpp"

namespace simulation {
PlayerModel::PlayerModel(const sf::Vector3i &initialPosition) :
	position{initialPosition} {}

void PlayerModel::update(float dt) {
  if (!animationsBuffer.empty()) {
	animationsBuffer.pop();
  }

  animationFrame = (animationFrame + 1) % 4;
}

void PlayerModel::moveAbsolute(const sf::Vector3i &newPosition) {
  position = newPosition;
}

void PlayerModel::moveRelative(const sf::Vector3i &displacement) {
  position += displacement;
}

const sf::Vector3i &PlayerModel::getPosition() const {
  return position;
}

std::pair<PlayerModel::AnimationState, int> PlayerModel::getAnimationState() const {
  if (animationsBuffer.empty()) {
	return {AnimationState::IDLE, animationFrame};
  }

  return {animationsBuffer.front(), animationFrame};
}
} // namespace simulation
