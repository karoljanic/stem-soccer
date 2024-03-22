#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
class StadiumViewDrawer {
 public:
  StadiumViewDrawer();
  void draw(const sf::Vector3f &origin);

 private:
  sf::Texture backgroundTexture;
  sf::Sprite background;
  std::vector<sf::Sprite> blocks;
};
} // namespace simulation
