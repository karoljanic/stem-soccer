#include "TeamTacticFactory.hpp"

namespace simulation {
TeamTactic TeamTacticFactory::createTeamTactic(FormationType formationType) {
  std::vector<sf::Vector2i> initialPlayerPositions;

  switch (formationType) {
	case FormationType::FORMATION_4_4_2: {

	}
	case FormationType::FORMATION_4_3_3: {

	}
	case FormationType::RANDOM:
	default: {

	}
  }

  return TeamTactic{initialPlayerPositions};
}
} // namespace simulation
