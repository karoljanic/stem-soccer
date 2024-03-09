#pragma once

#include "PlayerModel.hpp"
#include "BallModel.hpp"

#include <cstdint>
#include <vector>

namespace simulation {
class MatchModel {
 private:
  uint16_t gridWidth;
  uint16_t gridLength;
  uint16_t gridHeight;

  std::vector<PlayerModel> firstTeamPlayers;
  std::vector<PlayerModel> secondTeamPlayers;
  BallModel ball;

  MatchModel(uint16_t width, uint16_t length, uint16_t height);
};
}  // namespace simulation
