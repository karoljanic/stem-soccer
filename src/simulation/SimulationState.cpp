#include "SimulationState.hpp"
#include "../game/GameData.hpp"
#include "model/TeamTacticFactory.hpp"

namespace simulation {
void SimulationState::init() {
  matchModel = MatchModel{TeamTacticFactory::createTeamTactic(TeamTacticFactory::FormationType::RANDOM),
						  TeamTacticFactory::createTeamTactic(TeamTacticFactory::FormationType::FORMATION_4_3_3),
						  "kit2", "kit4", {0, 0, 0}};

  matchView.init(&matchModel);
}

void SimulationState::pause() {}

void SimulationState::resume() {}

void SimulationState::update(float /*dt*/) {
  matchModel.update();
}

void SimulationState::draw() {
  matchView.draw();
}
}  // namespace simulation
