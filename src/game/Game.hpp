#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "GameData.hpp"
#include "Arena.hpp"
#include "Player.hpp"

namespace game {
class Game {
 private:
  float dt;
  std::unique_ptr<Arena> arena;
  std::vector<std::unique_ptr<Player>> players;

 public:
  Game(uint16_t width, uint16_t height, uint16_t fps, const std::string& title);
  void run();
  virtual ~Game() = default;
};
} // namespace game
