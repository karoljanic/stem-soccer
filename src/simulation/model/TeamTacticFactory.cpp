#include "../../config/SimulationConfig.hpp"
#include "TeamTacticFactory.hpp"
#include <random>

namespace simulation {
TeamTactic TeamTacticFactory::createTeamTactic(FormationType formationType) {
  TeamTactic::Formation initialPlayerPositions;

  switch (formationType) {
	case FormationType::FORMATION_4_4_2: {
	  const int playersDistance = 3;
	  const int defendersLineDistance = static_cast<int>(config::SimulationConfig::PITCH_LENGTH / 2) - 5;
	  const int midfieldersLineDistance = static_cast<int>(config::SimulationConfig::PITCH_LENGTH / 2) - 10;
	  const int forwardsLineDistance = static_cast<int>(config::SimulationConfig::PITCH_LENGTH / 2) - 15;

	  initialPlayerPositions = {
		  {{0, config::SimulationConfig::PITCH_LENGTH / 2}},
		  {{-3 * playersDistance, defendersLineDistance}, {-playersDistance, defendersLineDistance},
		   {playersDistance, defendersLineDistance}, {3 * playersDistance, defendersLineDistance}},
		  {{-3 * playersDistance, midfieldersLineDistance}, {-playersDistance, midfieldersLineDistance},
		   {playersDistance, midfieldersLineDistance}, {3 * playersDistance, midfieldersLineDistance}},
		  {{-playersDistance, forwardsLineDistance}, {playersDistance, forwardsLineDistance}}
	  };
	  break;
	}
	case FormationType::FORMATION_4_3_3: {
	  const int playersDistance = 3;
	  const int defendersLineDistance = static_cast<int>(config::SimulationConfig::PITCH_LENGTH / 2) - 5;
	  const int midfieldersLineDistance = static_cast<int>(config::SimulationConfig::PITCH_LENGTH / 2) - 10;
	  const int forwardsLineDistance = static_cast<int>(config::SimulationConfig::PITCH_LENGTH / 2) - 15;

	  initialPlayerPositions = {
		  {{0, config::SimulationConfig::PITCH_LENGTH / 2}},
		  {{-3 * playersDistance, defendersLineDistance}, {-playersDistance, defendersLineDistance},
		   {playersDistance, defendersLineDistance}, {3 * playersDistance, defendersLineDistance}},
		  {{-2 * playersDistance, midfieldersLineDistance}, {0, midfieldersLineDistance},
		   {2 * playersDistance, midfieldersLineDistance}},
		  {{-2 * playersDistance, forwardsLineDistance}, {0, forwardsLineDistance},
		   {2 * playersDistance, forwardsLineDistance}}
	  };
	  break;
	}
	case FormationType::RANDOM:
	default: {
	  std::mt19937 gen(std::random_device{}());
	  std::uniform_int_distribution<int> xCoord(0, static_cast<int>(config::SimulationConfig::PITCH_WIDTH / 2));
	  std::uniform_int_distribution<int> yCoord(0, static_cast<int>(config::SimulationConfig::PITCH_LENGTH / 2));
	  while (initialPlayerPositions.size() < 11) {
		const int x = xCoord(gen);
		const int y = yCoord(gen);
		bool isUnique = true;
		for (const auto &player : initialPlayerPositions) {
		  if (player[0].x == x && player[0].y == y) {
			isUnique = false;
		  }
		}
		if (isUnique) {
		  initialPlayerPositions.push_back({{x, y}});
		}
	  }
	}
  }

  return TeamTactic{
	  initialPlayerPositions
  };
}
} // namespace simulation
