#pragma once

#include "../model/PlayerModel.hpp"
#include <SFML/Graphics.hpp>
#include <utility>

namespace simulation {
class PlayerViewDrawer {
 public:
  PlayerViewDrawer();
  std::pair<sf::Sprite, float> draw(const PlayerModel &playerModel, const sf::Vector3f &origin);

 private:
  sf::Sprite footballer;
  uint16_t currentAnimationFrameWidth;
};
} // namespace simulation
