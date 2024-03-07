#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <cstdint>

namespace football {
class FootballPlayer {
    private:
    sf::Sprite footballer;
    uint8_t animationFrame;

 public:
  explicit FootballPlayer(const std::string &textureName, const sf::Vector2f &position);
  void update();
  void draw();
};
} // namespace football
