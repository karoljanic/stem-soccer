#include "SimulationState.hpp"
#include "../game/GameData.hpp"
#include "model/TeamTacticFactory.hpp"

namespace simulation {
void SimulationState::init() {
  const float originX = static_cast<float>(game::GameData::getInstance()->window.getSize().x) / 2;
  const float originY = static_cast<float>(game::GameData::getInstance()->window.getSize().y) / 2;
  const float originZ = 0;

  matchModel = MatchModel{TeamTacticFactory::createTeamTactic(TeamTacticFactory::FormationType::RANDOM),
						  TeamTacticFactory::createTeamTactic(TeamTacticFactory::FormationType::FORMATION_4_3_3),
						  "kit2", "kit4", {0, 0, 0}};

  matchView.init(&matchModel, sf::Vector3f{originX, originY, originZ});
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
