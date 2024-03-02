#pragma once

#include "../game/Game.hpp"

namespace football {
class FootballGame : public game::Game {
 public:
  FootballGame(uint16_t width, uint16_t height, uint16_t  fps, const std::string &title);
};
} // namespace football
