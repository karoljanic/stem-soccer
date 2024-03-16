#include "PlayerModel.hpp"
#include "../../config/SimulationConfig.hpp"

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

void PlayerModel::idle() {
  animationsBuffer.push({AnimationState::IDLE, {0.0F, 0.0F}});
}

void PlayerModel::moveUp() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_UP, {0.0F, static_cast<float>(i) * 0.2F}});
  }
}

void PlayerModel::moveDown() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_DOWN, {0.0F, static_cast<float>(-i) * 0.2F}});
  }
}

void PlayerModel::moveLeft() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_LEFT, {static_cast<float>(-i) * 0.2F, 0.0F}});
  }
}

void PlayerModel::moveRight() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_RIGHT, {static_cast<float>(i) * 0.2F, 0.0F}});
  }
}

void PlayerModel::moveUpLeft() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_UP,
						   {static_cast<float>(-i) * 0.2F, static_cast<float>(i) * 0.2F}});
  }
}

void PlayerModel::moveUpRight() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_UP,
						   {static_cast<float>(i) * 0.2F, static_cast<float>(i) * 0.2F}});
  }
}

void PlayerModel::moveDownLeft() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_DOWN,
						   {static_cast<float>(-i) * 0.2F, static_cast<float>(-i) * 0.2F}});
  }
}

void PlayerModel::moveDownRight() {
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_DOWN,
						   {static_cast<float>(i) * 0.2F, static_cast<float>(-i) * 0.2F}});
  }
}

const sf::Vector3i &PlayerModel::getPosition() const {
  return position;
}

std::pair<PlayerModel::AnimationState, sf::Vector2f> PlayerModel::getAnimationState() const {
  if (animationsBuffer.empty()) {
	return {AnimationState::IDLE, {0.0F, 0.0F}};
  }

  return animationsBuffer.front();
}

uint8_t PlayerModel::getAnimationFrame() const {
  return animationFrame;
}
} // namespace simulation
