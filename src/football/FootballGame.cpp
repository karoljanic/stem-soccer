#include "FootballGame.hpp"

namespace football {
FootballGame::FootballGame()
	: game::Game(config::WindowConfig::WIDTH, config::WindowConfig::HEIGHT, config::WindowConfig::FPS,
				 "Football Simulation") {

}
} // namespace football
