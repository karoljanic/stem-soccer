#include "SimulationState.hpp"
#include "../game/GameData.hpp"

namespace simulation {
void SimulationState::init() {
  const float originX = static_cast<float>(game::GameData::getInstance()->window.getSize().x) / 2;
  const float originY = static_cast<float>(game::GameData::getInstance()->window.getSize().y) / 2;
  const float originZ = 0;

  matchModel = MatchModel{{
							  {3, 5, 0},
							  {-6, 6, 0}
						  }, {
							  {-3, -5, 0},
							  {6, -6, 0}
						  }, {0, 0, 0}};

  matchView.init(matchModel, sf::Vector3f{originX, originY, originZ});
}

void SimulationState::pause() {}

void SimulationState::resume() {}

void SimulationState::update(float dt) {
  matchModel.update(dt);
}

void SimulationState::draw(float dt) {
  matchView.draw();
}
}  // namespace simulation
