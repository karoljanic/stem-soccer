#pragma once

#include "../../config/WindowConfig.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>

namespace football {
class FootballArena {
 private:
  std::vector<std::unique_ptr<sf::Sprite>> blocks;

 public:
  FootballArena(const sf::Vector2f &centerAnchor);
  void update();
  void draw();
};
} // namespace football
