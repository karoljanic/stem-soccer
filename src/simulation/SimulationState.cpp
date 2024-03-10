#include "SimulationState.hpp"
#include "../game/GameData.hpp"

namespace simulation {
void SimulationState::init() {
  const float centerX = static_cast<float>(game::GameData::getInstance()->window.getSize().x) / 2;
  const float centerY = static_cast<float>(game::GameData::getInstance()->window.getSize().y) / 2;

  matchModel.init(centerX, centerY);
  matchView.init(matchModel);
}

void SimulationState::pause() {}

void SimulationState::resume() {}

void SimulationState::update(float dt) {
  matchModel.update();
}

void SimulationState::draw(float dt) {
  matchView.draw();
}
}  // namespace simulation
