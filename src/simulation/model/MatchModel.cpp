#include "MatchModel.hpp"
#include "../../config/SimulationConfig.hpp"
#include <numeric>

namespace simulation {
MatchModel::MatchModel(const TeamTactic &firstTeamTactic, const TeamTactic &secondTeamTactic,
					   const std::string &firstTeamKitName, const std::string &secondTeamKitName,
					   const sf::Vector3i &ballPosition) :
	ball{ballPosition},
	firstTeamPlayers{std::accumulate(firstTeamTactic.getInitialPlayerPositions().begin(),
									 firstTeamTactic.getInitialPlayerPositions().end(), 0U,
									 [](size_t sum, const std::vector<sf::Vector2i> &vec) {
									   return sum + vec.size();
									 })},
	secondTeamPlayers{std::accumulate(secondTeamTactic.getInitialPlayerPositions().begin(),
									  secondTeamTactic.getInitialPlayerPositions().end(), 0U,
									  [](size_t sum, const std::vector<sf::Vector2i> &vec) {
										return sum + vec.size();
									  })},
	firstTeamKit{firstTeamKitName},
	secondTeamKit{secondTeamKitName},
	ticker{0},
	generator{std::random_device{}()},
	graph{std::make_unique<graph::DenseGraph>(
		config::SimulationConfig::PITCH_WIDTH * config::SimulationConfig::PITCH_LENGTH, false)} {

  size_t playerIndex = 0;
  for (size_t i = 0; i < firstTeamTactic.getInitialPlayerPositions().size(); i++) {
	for (size_t j = 0; j < firstTeamTactic.getInitialPlayerPositions().at(i).size(); j++) {
	  firstTeamPlayers[playerIndex].moveAbsolute(firstTeamTactic.getInitialPlayerPositions().at(i).at(j));
	  firstTeamPlayers[playerIndex].setKit(firstTeamKitName);
	  playerIndex++;
	}
  }

  playerIndex = 0;
  for (size_t i = 0; i < secondTeamTactic.getInitialPlayerPositions().size(); i++) {
	for (size_t j = 0; j < secondTeamTactic.getInitialPlayerPositions().at(i).size(); j++) {
	  secondTeamPlayers[playerIndex].moveAbsolute(-secondTeamTactic.getInitialPlayerPositions().at(i).at(j));
	  secondTeamPlayers[playerIndex].setKit(secondTeamKitName);
	  playerIndex++;
	}
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
//	movePlayers();
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
