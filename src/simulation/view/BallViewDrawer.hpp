#pragma once

#include "../model/BallModel.hpp"
#include <SFML/Graphics.hpp>
#include <utility>

namespace simulation {
class BallViewDrawer {
 private:
  sf::Sprite ball;

 public:
  BallViewDrawer();
  std::pair<sf::Sprite, float> draw(const BallModel& ballModel, const sf::Vector3f &origin);
};
} // namespace simulation
