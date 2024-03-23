#include "TeamTactic.hpp"

namespace simulation {
TeamTactic::TeamTactic(const std::vector<sf::Vector2i> &playerPositions) : initialPlayerPositions{playerPositions} {}

const std::vector<sf::Vector2i> &TeamTactic::getInitialPlayerPositions() const {
  return initialPlayerPositions;
}
} // namespace simulation
