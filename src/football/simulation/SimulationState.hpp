#pragma once

#include "../../game/State.hpp"
#include "FootballArena.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace football {
class SimulationState : public game::State {
 private:
  sf::Texture backgroundTexture;
  sf::Sprite background;
  std::unique_ptr<FootballArena> arena;

 public:
  SimulationState() = default;
  void init() override;
  void pause() override;
  void resume() override;
  void update(float dt) override;
  void draw(float dt) override;
};
} // namespace football
