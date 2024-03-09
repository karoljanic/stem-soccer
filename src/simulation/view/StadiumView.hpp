#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace simulation {
class StadiumView {
 private:
  std::vector<std::unique_ptr<sf::Sprite>> blocks;

 public:
  StadiumView(const sf::Vector2f &position);
  void update();
  void draw();
};
} // namespace simulation
