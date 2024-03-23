#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

namespace simulation {
class TeamTactic {
 public:
  TeamTactic() = default;
  explicit TeamTactic(const std::vector<sf::Vector2i>& playerPositions);

  const std::vector<sf::Vector2i>& getInitialPlayerPositions() const;

 private:
  std::vector<sf::Vector2i> initialPlayerPositions;
};
} // namespace simulation
