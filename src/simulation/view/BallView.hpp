#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
class BallView {
 private:
  sf::Sprite ball;

 public:
  explicit BallView(const sf::Vector2f &position);
  void update();
  void draw();
};
} // namespace simulation
