#include "FootballGame.hpp"

namespace football {
FootballGame::FootballGame()
	: game::Game(config::WindowConfig::WIDTH, config::WindowConfig::HEIGHT, config::WindowConfig::FPS,
				 "Football Simulation") {
  	game::GameData::getInstance()->machine.addState(std::make_unique<MenuState>());
}
} // namespace football
