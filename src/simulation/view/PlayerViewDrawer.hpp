#pragma once

#include "../model/PlayerModel.hpp"
#include <SFML/Graphics.hpp>

namespace simulation {
class PlayerViewDrawer {
 private:
  sf::Sprite footballer;

 public:
  PlayerViewDrawer();
  void draw(const PlayerModel &playerModel, const sf::Vector3f &origin);
};
} // namespace simulation
