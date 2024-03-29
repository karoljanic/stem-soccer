#pragma once

#include "StatesMachine.hpp"
#include "managers/InputManager.hpp"
#include "managers/AssetsManager.hpp"

#include <SFML/Graphics.hpp>

namespace game {
class GameData {
 public:
  GameData();
  static const std::unique_ptr<GameData>& getInstance();
  virtual ~GameData() = default;

  StatesMachine machine;
  AssetsManager assets;
  InputManager inputs;
  sf::RenderWindow window;
  sf::Clock clock;

 private:
  static std::unique_ptr<GameData> gameData;
};
} // namespace game