#pragma once

#include <SFML/Graphics.hpp>

namespace football {
class FootballBall {
 private:
  sf::Sprite ball;

 public:
  FootballBall(const sf::Vector2f& position);
  void update();
  void draw();
};
}  // namespace football