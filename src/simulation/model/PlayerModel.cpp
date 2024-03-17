#include "PlayerModel.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
PlayerModel::PlayerModel(const sf::Vector3i &initialPosition, const std::string &kitName) :
	position{initialPosition}, kit{kitName} {

}

void PlayerModel::update() {
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
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::IDLE, {0.0F, 0.0F, 0.0F}});
  }
}

void PlayerModel::moveUp() {
  position.x++;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_UP,
						   {1 + static_cast<float>(-i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F, 0.0F}});
  }
}

void PlayerModel::moveDown() {
  position.x--;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_DOWN,
						   {-1 + static_cast<float>(i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F, 0.0F}});
  }
}

void PlayerModel::moveLeft() {
  position.y--;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_LEFT,
						   {0.0F,
							-1.0F + static_cast<float>(i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F}});
  }
}

void PlayerModel::moveRight() {
  position.y++;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_RIGHT,
						   {0.0F,
							1.0F + static_cast<float>(-i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F}});
  }
}

void PlayerModel::moveUpRight() {
  position.x++;
  position.y++;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_UP_RIGHT,
						   {1.0F + static_cast<float>(-i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							1.0F + static_cast<float>(-i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F}});
  }
}

void PlayerModel::moveUpLeft() {
  position.x++;
  position.y--;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_UP_LEFT,
						   {1 + static_cast<float>(-i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							-1.0F + static_cast<float>(i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F}});
  }
}

void PlayerModel::moveDownLeft() {
  position.x--;
  position.y--;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_DOWN_LEFT,
						   {-1 + static_cast<float>(i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							-1.0F + static_cast<float>(i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F}});
  }
}

void PlayerModel::moveDownRight() {
  position.x--;
  position.y++;
  for (uint8_t i = 0; i < config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES; i++) {
	animationsBuffer.push({AnimationState::WALKING_DOWN_RIGHT,
						   {-1 + static_cast<float>(i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							1.0F + static_cast<float>(-i) * config::SimulationConfig::PLAYER_MOVE_ANIMATION_TRANSLATION,
							0.0F}});
  }
}

void PlayerModel::setKit(const std::string &kitName) {
  kit = kitName;
}

const sf::Vector3i &PlayerModel::getPosition() const {
  return position;
}

const std::string &PlayerModel::getKit() const {
  return kit;
}

std::pair<PlayerModel::AnimationState, sf::Vector3f> PlayerModel::getAnimationState() const {
  if (animationsBuffer.empty()) {
	return {AnimationState::IDLE, {0.0F, 0.0F, 0.0F}};
  }

  return animationsBuffer.front();
}

uint8_t PlayerModel::getAnimationFrame() const {
  return animationFrame;
}
} // namespace simulation
