#include "TeamTactic.hpp"

namespace simulation {
TeamTactic::TeamTactic(const TeamTactic::Formation &playerPositions) : initialPlayerPositions{playerPositions} {}

const TeamTactic::Formation &TeamTactic::getInitialPlayerPositions() const {
  return initialPlayerPositions;
}
} // namespace simulation
