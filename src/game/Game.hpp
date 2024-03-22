#pragma once

#include "GameData.hpp"

namespace game {
class Game {
 public:
  Game(uint16_t width, uint16_t height, uint16_t fps, const std::string& title);
  void run();
  virtual ~Game() = default;

 private:
  float dt;
};
} // namespace game
