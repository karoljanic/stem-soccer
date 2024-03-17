#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <queue>
#include <utility>
#include <string>

namespace simulation {
class PlayerModel {
 public:
  enum class AnimationState : uint8_t {
	IDLE,
	WALKING_UP,
	WALKING_DOWN,
	WALKING_LEFT,
	WALKING_RIGHT,
	WALKING_UP_LEFT,
	WALKING_UP_RIGHT,
	WALKING_DOWN_LEFT,
	WALKING_DOWN_RIGHT
  };

 private:
  sf::Vector3i position;
  std::string kit;
  std::queue<std::pair<AnimationState, sf::Vector3f>> animationsBuffer;
  uint8_t animationFrame{0};

 public:
  PlayerModel() = default;
  explicit PlayerModel(const sf::Vector3i &position, const std::string& kitName);
  void update();
  void moveAbsolute(const sf::Vector3i &newPosition);
  void moveRelative(const sf::Vector3i &displacement);
  void idle();
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();
  void moveUpLeft();
  void moveUpRight();
  void moveDownLeft();
  void moveDownRight();
  void setKit(const std::string& kitName);
  const sf::Vector3i &getPosition() const;
  const std::string& getKit() const;
  std::pair<PlayerModel::AnimationState, sf::Vector3f> getAnimationState() const;
  uint8_t getAnimationFrame() const;
};
}  // namespace simulation
