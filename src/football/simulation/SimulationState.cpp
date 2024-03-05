#include "SimulationState.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../game/GameData.hpp"

namespace football {
void SimulationState::init() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_BACKGROUND_TEXTURE,
													"simulation_background");
  backgroundTexture = game::GameData::getInstance()->assets.getTexture("simulation_background");
  background.setTexture(backgroundTexture);

  const float centerX = static_cast<float>(game::GameData::getInstance()->window.getSize().x) / 2
	  - config::WindowConfig::SIMULATION_AREA_BLOCK_WIDTH / 2;
  const float centerY = static_cast<float>(game::GameData::getInstance()->window.getSize().y) / 2;

  arena = std::make_unique<FootballArena>(sf::Vector2f{centerX, centerY});
}

void SimulationState::pause() {}

void SimulationState::resume() {}

void SimulationState::update(float dt) {
  arena->update();
}

void SimulationState::draw(float dt) {
  game::GameData::getInstance()->window.clear();
  game::GameData::getInstance()->window.draw(background);
  arena->draw();
  game::GameData::getInstance()->window.display();
}
} // namespace football
