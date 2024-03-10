#pragma once

#include "../game/State.hpp"
#include "model/MatchModel.hpp"
#include "view/MatchView.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace simulation {
class SimulationState : public game::State {
 private:
  MatchModel matchModel;
  MatchView matchView;

 public:
  SimulationState() = default;
  void init() override;
  void pause() override;
  void resume() override;
  void update(float dt) override;
  void draw(float dt) override;
};
} // namespace simulation
