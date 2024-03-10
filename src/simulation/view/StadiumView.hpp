#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace simulation {
class StadiumView {
 private:
  sf::Texture backgroundTexture;
  sf::Sprite background;
  std::vector<std::unique_ptr<sf::Sprite>> blocks;

 public:
  StadiumView() = default;
  void init(const sf::Vector3f &position);
  void update();
  void draw();
};
} // namespace simulation
