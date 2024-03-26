#include "PlayerStats.hpp"

namespace simulation {
PlayerStats::PlayerStats(uint8_t pace,
						 uint8_t shooting,
						 uint8_t passing,
						 uint8_t dribbling,
						 uint8_t defending,
						 uint8_t physicality,
						 uint8_t goalkeeping)
	: pace{pace},
	  shooting{shooting},
	  passing{passing},
	  dribbling{dribbling},
	  defending{defending},
	  physicality{physicality},
	  goalkeeping{goalkeeping} {}

uint8_t PlayerStats::getPace() const {
  return pace;
}

uint8_t PlayerStats::getShooting() const {
  return shooting;
}

uint8_t PlayerStats::getPassing() const {
  return passing;
}

uint8_t PlayerStats::getDribbling() const {
  return dribbling;
}

uint8_t PlayerStats::getDefending() const {
  return defending;
}

uint8_t PlayerStats::getPhysicality() const {
  return physicality;
}

uint8_t PlayerStats::getGoalkeeping() const {
  return goalkeeping;
}

} // namespace simulation
