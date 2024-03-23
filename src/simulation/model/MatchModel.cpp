#include "MatchModel.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
MatchModel::MatchModel(const TeamTactic &firstTeamTactic, const TeamTactic &secondTeamTactic,
					   const std::string& firstTeamKitName, const std::string& secondTeamKitName,
					   const sf::Vector3i &ballPosition) :
	ball{ballPosition},
	firstTeamPlayers{firstTeamTactic.getInitialPlayerPositions().size()},
	secondTeamPlayers{secondTeamTactic.getInitialPlayerPositions().size()},
	firstTeamKit{firstTeamKitName},
	secondTeamKit{secondTeamKitName},
	ticker{0},
	generator{std::random_device{}()},
	graph{std::make_unique<graph::DenseGraph>(
		config::SimulationConfig::PITCH_WIDTH * config::SimulationConfig::PITCH_LENGTH, false)} {

  for (size_t i = 0; i < firstTeamPlayers.size(); i++) {
	firstTeamPlayers[i].moveAbsolute(firstTeamTactic.getInitialPlayerPositions().at(i));
	firstTeamPlayers[i].setKit(firstTeamKitName);
  }

  for (size_t i = 0; i < secondTeamPlayers.size(); i++) {
	secondTeamPlayers[i].moveAbsolute(secondTeamTactic.getInitialPlayerPositions().at(i));
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
