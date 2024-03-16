#include "MatchModel.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
MatchModel::MatchModel(const std::vector<sf::Vector3i> &firstTeamPlayersPositions,
					   const std::vector<sf::Vector3i> &secondTeamPlayersPositions,
					   const sf::Vector3i &ballPosition) :
	ball{ballPosition},
	firstTeamPlayers{config::SimulationConfig::PLAYERS_PER_TEAM},
	secondTeamPlayers{config::SimulationConfig::PLAYERS_PER_TEAM},
	timeAccumulator{0} {

  if (firstTeamPlayersPositions.size() != config::SimulationConfig::PLAYERS_PER_TEAM ||
	  secondTeamPlayersPositions.size() != config::SimulationConfig::PLAYERS_PER_TEAM) {
	throw std::invalid_argument("Invalid number of players");
  }

  for (size_t i = 0; i < config::SimulationConfig::PLAYERS_PER_TEAM; i++) {
	firstTeamPlayers[i].moveAbsolute(firstTeamPlayersPositions[i]);
	secondTeamPlayers[i].moveAbsolute(secondTeamPlayersPositions[i]);
  }
}

void MatchModel::update(float dt) {
  ball.update(dt);

  for (auto &player : firstTeamPlayers) {
	player.update(dt);
  }

  for (auto &player : secondTeamPlayers) {
	player.update(dt);
  }

  timeAccumulator += dt;
  if (timeAccumulator >= config::SimulationConfig::PLAYER_POSITIONS_UPDATE_INTERVAL) {
	movePlayers();
	timeAccumulator -= config::SimulationConfig::PLAYER_POSITIONS_UPDATE_INTERVAL;
  }
}

const std::vector<PlayerModel> &MatchModel::getFirstTeamPlayers() const {
  return firstTeamPlayers;
}

const std::vector<PlayerModel> &MatchModel::getSecondTeamPlayers() const {
  return secondTeamPlayers;
}

const BallModel &MatchModel::getBall() const {
  return ball;
}

void MatchModel::movePlayers() {

}
} // namespace simulation
