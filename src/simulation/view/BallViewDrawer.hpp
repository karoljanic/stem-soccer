#pragma once

#include "../model/BallModel.hpp"
#include <SFML/Graphics.hpp>

namespace simulation {
class BallViewDrawer {
 private:
  sf::Sprite ball;

 public:
  BallViewDrawer();
  void draw(const BallModel& ballModel, const sf::Vector3f &origin);
};
} // namespace simulation
