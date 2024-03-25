#include "FootballGame.hpp"
#include "../config/WindowConfig.hpp"
#include "../menu/MenuState.hpp"

namespace simulation {
FootballGame::FootballGame()
	: game::Game(config::WindowConfig::INITIAL_WIDTH, config::WindowConfig::INITIAL_HEIGHT, config::WindowConfig::FPS,
				 "Football Simulation") {
  game::GameData::getInstance()->machine.addState(std::make_unique<menu::MenuState>());
}
} // namespace simulation
