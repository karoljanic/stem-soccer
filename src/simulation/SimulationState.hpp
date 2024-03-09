#pragma once

#include "../game/State.hpp"
#include "model/BallModel.hpp"
#include "model/PlayerModel.hpp"
#include "model/MatchModel.hpp"
#include "view/BallView.hpp"
#include "view/PlayerView.hpp"
#include "view/StadiumView.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace simulation {
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
} // namespace simulation
