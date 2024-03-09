#pragma once

#include <SFML/Graphics.hpp>

namespace simulation {
class PlayerView {
 private:
  sf::Sprite footballer;
  uint8_t animationFrame;

 public:
  PlayerView(const std::string &textureName, const sf::Vector2f &position);
  void update();
  void draw();
};
} // namespace simulation