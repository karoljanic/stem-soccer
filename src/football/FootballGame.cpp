#include "FootballGame.hpp"

namespace football {
FootballGame::FootballGame(const uint16_t width, const uint16_t height, const uint16_t fps, const std::string &title)
	: game::Game(width, height, fps, title) {}
}