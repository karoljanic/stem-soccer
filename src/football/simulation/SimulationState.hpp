#pragma once

#include "../../game/State.hpp"
#include "FootballArena.hpp"
#include "FootballBall.hpp"
#include "FootballPlayer.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace football {
class SimulationState : public game::State {
 private:
  sf::Texture backgroundTexture;
  sf::Sprite background;
  std::unique_ptr<FootballArena> arena;
  std::unique_ptr<FootballBall> ball;
  std::vector<std::unique_ptr<FootballPlayer>> players;

 public:
  SimulationState() = default;
  void init() override;
  void pause() override;
  void resume() override;
  void update(float dt) override;
  void draw(float dt) override;
};
} // namespace football
