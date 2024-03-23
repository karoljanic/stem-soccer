#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace simulation {
class TeamTactic {
 public:
  typedef std::vector<std::vector<sf::Vector2i>> Formation;

  TeamTactic() = default;
  explicit TeamTactic(const Formation& playerPositions);

  const Formation& getInitialPlayerPositions() const;

 private:
  Formation initialPlayerPositions;
};
} // namespace simulation
