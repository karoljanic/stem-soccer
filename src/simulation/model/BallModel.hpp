#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>

namespace simulation {
class BallModel {
 private:
  sf::Vector3i position;
  float rotation;

 public:
  BallModel() = default;
  explicit BallModel(const sf::Vector3i &initialPosition);
  void update(float dt);
  void moveAbsolute(const sf::Vector3i &newPosition);
  void moveRelative(const sf::Vector3i &displacement);
  const sf::Vector3i& getPosition() const;
  float getRotation() const;
};
}  // namespace simulation
