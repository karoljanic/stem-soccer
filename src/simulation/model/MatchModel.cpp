#include "MatchModel.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
MatchModel::MatchModel(const std::vector<sf::Vector3i> &firstTeamPlayersPositions,
					   const std::vector<sf::Vector3i> &secondTeamPlayersPositions,
					   const std::string &firstTeamKitName, const std::string &secondTeamKitName,
					   const sf::Vector3i &ballPosition) :
	ball{ballPosition},
	firstTeamPlayers{config::SimulationConfig::PLAYERS_PER_TEAM},
	secondTeamPlayers{config::SimulationConfig::PLAYERS_PER_TEAM},
	firstTeamKit{firstTeamKitName},
	secondTeamKit{secondTeamKitName},
	ticker{0},
	generator{std::random_device{}()} {

  if (firstTeamPlayersPositions.size() != config::SimulationConfig::PLAYERS_PER_TEAM ||
	  secondTeamPlayersPositions.size() != config::SimulationConfig::PLAYERS_PER_TEAM) {
	throw std::invalid_argument("Invalid number of players");
  }

  for (size_t i = 0; i < config::SimulationConfig::PLAYERS_PER_TEAM; i++) {
	firstTeamPlayers[i].moveAbsolute(firstTeamPlayersPositions[i]);
	firstTeamPlayers[i].setKit(firstTeamKitName);
	secondTeamPlayers[i].moveAbsolute(secondTeamPlayersPositions[i]);
	secondTeamPlayers[i].setKit(secondTeamKitName);
  }
}

void MatchModel::update() {
  ball.update();

  for (auto &player : firstTeamPlayers) {
	player.update();
  }

  for (auto &player : secondTeamPlayers) {
	player.update();
  }

  ticker++;
  if (ticker == config::SimulationConfig::PLAYER_MOVE_ANIMATION_FRAMES) {
	ticker = 0;
	movePlayers();
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
  for (auto &player : firstTeamPlayers) {
	const float rand = distribution(generator);
	if (rand < 0.1) {
	  player.moveUp();
	} else if (rand < 0.2) {
	  player.moveDown();
	} else if (rand < 0.3) {
	  player.moveLeft();
	} else if (rand < 0.4) {
	  player.moveRight();
	} else if (rand < 0.5) {
	  player.moveUpLeft();
	} else if (rand < 0.6) {
	  player.moveUpRight();
	} else if (rand < 0.7) {
	  player.moveDownLeft();
	} else if (rand < 0.8) {
	  player.moveDownRight();
	} else {
	  player.idle();
	}
  }

  for (auto &player : secondTeamPlayers) {
	const float rand = distribution(generator);
	if (rand < 0.1) {
	  player.moveUp();
	} else if (rand < 0.2) {
	  player.moveDown();
	} else if (rand < 0.3) {
	  player.moveLeft();
	} else if (rand < 0.4) {
	  player.moveRight();
	} else if (rand < 0.5) {
	  player.moveUpLeft();
	} else if (rand < 0.6) {
	  player.moveUpRight();
	} else if (rand < 0.7) {
	  player.moveDownLeft();
	} else if (rand < 0.8) {
	  player.moveDownRight();
	} else {
	  player.idle();
	}
  }
}
} // namespace simulation
