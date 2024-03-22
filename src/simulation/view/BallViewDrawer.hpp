#pragma once

#include "../model/BallModel.hpp"
#include <SFML/Graphics.hpp>
#include <utility>

namespace simulation {
class BallViewDrawer {
 public:
  BallViewDrawer();
  std::pair<sf::Sprite, float> draw(const BallModel& ballModel, const sf::Vector3f &origin);

 private:
  sf::Sprite ball;
};
} // namespace simulation
