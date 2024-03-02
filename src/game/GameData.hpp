#pragma once

#include "StatesMachine.hpp"

#include <SFML/Graphics.hpp>
#include <memory>



namespace game {
class GameData {
 private:
  static std::shared_ptr<GameData> gameData;
 public:
  GameData();
  static std::shared_ptr<GameData> getInstance();
  virtual ~GameData() = default;

  StatesMachine machine;
  sf::RenderWindow window;
  sf::Clock clock;
};
} // namespace game