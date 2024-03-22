#pragma once

#include "../game/State.hpp"
#include "model/MatchModel.hpp"
#include "view/MatchView.hpp"
#include <SFML/Graphics.hpp>
#include <memory>

namespace simulation {
class SimulationState : public game::State {
 public:
  SimulationState() = default;
  void init() override;
  void pause() override;
  void resume() override;
  void update(float dt) override;
  void draw() override;

 private:
  MatchModel matchModel;
  MatchView matchView;
};
} // namespace simulation
