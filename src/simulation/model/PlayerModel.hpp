#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

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
  AnimationState animationFrame;

 public:
  PlayerModel() = default;
  explicit PlayerModel(const sf::Vector3i &position);
  void update(float dt);
  void moveAbsolute(const sf::Vector3i &newPosition);
  void moveRelative(const sf::Vector3i &displacement);
  const sf::Vector3i &getPosition() const;
  AnimationState getAnimationFrame() const;
};
}  // namespace simulation
