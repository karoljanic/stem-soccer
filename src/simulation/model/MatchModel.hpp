#pragma once

#include "PlayerModel.hpp"
#include "BallModel.hpp"

#include <cstdint>
#include <vector>
#include <SFML/Graphics.hpp>

namespace simulation {
class MatchModel {
 private:
  std::vector<PlayerModel> firstTeamPlayers;
  std::vector<PlayerModel> secondTeamPlayers;
  BallModel ball;

  float timeAccumulator;

 public:
  MatchModel() = default;
  explicit MatchModel(const std::vector<sf::Vector3i> &firstTeamPlayersPositions,
					  const std::vector<sf::Vector3i> &secondTeamPlayersPositions,
					  const sf::Vector3i &ballPosition);
  void update(float dt);
  const std::vector<PlayerModel> &getFirstTeamPlayers() const;
  const std::vector<PlayerModel> &getSecondTeamPlayers() const;
  const BallModel &getBall() const;

 private:
  void movePlayers();
};
}  // namespace simulation
