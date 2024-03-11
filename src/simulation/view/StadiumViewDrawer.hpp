#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
class StadiumViewDrawer {
 private:
  sf::Texture backgroundTexture;
  sf::Sprite background;
  std::vector<sf::Sprite> blocks;

 public:
  StadiumViewDrawer();
  void draw(const sf::Vector3f &origin);
};
} // namespace simulation
