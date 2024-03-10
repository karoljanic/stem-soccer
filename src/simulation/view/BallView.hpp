#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
class BallView {
 private:
  sf::Sprite ball;

 public:
  explicit BallView() = default;
  void init(const sf::Vector3f &position);
  void update();
  void draw();
};
} // namespace simulation
