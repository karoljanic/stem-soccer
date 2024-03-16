#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <queue>
#include <utility>

namespace simulation {
class PlayerModel {
 public:
  enum class AnimationState : uint8_t {
	IDLE,
	WALKING_UP,
	WALKING_DOWN,
	WALKING_LEFT,
	WALKING_RIGHT
  };

 private:
  sf::Vector3i position;
  std::queue<std::pair<AnimationState, sf::Vector2f>> animationsBuffer;
  uint8_t animationFrame{0};

 public:
  PlayerModel() = default;
  explicit PlayerModel(const sf::Vector3i &position);
  void update(float dt);
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
  const sf::Vector3i &getPosition() const;
  std::pair<PlayerModel::AnimationState, sf::Vector2f> getAnimationState() const;
  uint8_t getAnimationFrame() const;
};
}  // namespace simulation
