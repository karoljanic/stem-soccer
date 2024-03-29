#pragma once

#include "PlayerModel.hpp"
#include "BallModel.hpp"
#include "TeamTactic.hpp"
#include "../../graph/DenseGraph.hpp"

#include <cstdint>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>
#include <memory>

namespace simulation {
class MatchModel {
 public:
  MatchModel() = default;
  explicit MatchModel(const TeamTactic &firstTeamTactic, const TeamTactic &secondTeamTactic,
					  const std::string& firstTeamKitName, const std::string& secondTeamKitName,
					  const sf::Vector3i &ballPosition);
  void update();
  const std::vector<PlayerModel> &getFirstTeamPlayers() const;
  const std::vector<PlayerModel> &getSecondTeamPlayers() const;
  const BallModel &getBall() const;

 private:
  std::vector<PlayerModel> firstTeamPlayers;
  std::vector<PlayerModel> secondTeamPlayers;
  std::string firstTeamKit;
  std::string secondTeamKit;
  BallModel ball;

  uint8_t ticker;
  std::mt19937 generator;
  std::uniform_real_distribution<float> distribution;
  std::unique_ptr<graph::Graph> graph;

  void movePlayers();
};
}  // namespace simulation
