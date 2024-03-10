#pragma once

#include "PlayerModel.hpp"
#include "BallModel.hpp"

#include <cstdint>
#include <vector>

namespace simulation {
class MatchModel {
 private:
  std::vector<PlayerModel> firstTeamPlayers;
  std::vector<PlayerModel> secondTeamPlayers;
  BallModel ball;

 public:
  MatchModel() = default;
  void init(float windowCenterX, float windowCenterY);
  void update();
};
}  // namespace simulation
