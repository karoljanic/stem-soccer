#include "MatchView.hpp"
#include "../../game/GameData.hpp"
#include <utility>
#include <vector>
#include <algorithm>

namespace simulation {
void MatchView::init(MatchModel *matchModel, const sf::Vector3f &origin) {
  matchModelPtr = matchModel;
  worldOrigin = origin;
}

void MatchView::draw() {
  game::GameData::getInstance()->window.clear();
  stadiumViewDrawer.draw(worldOrigin);

  std::vector<std::pair<sf::Sprite, float>> sprites;
  for (const auto &player : matchModelPtr->getFirstTeamPlayers()) {
	sprites.push_back(playerViewDrawer.draw(player, worldOrigin));
  }

  for (const auto &player : matchModelPtr->getSecondTeamPlayers()) {
	sprites.push_back(playerViewDrawer.draw(player, worldOrigin));
  }

  sprites.push_back(ballViewDrawer.draw(matchModelPtr->getBall(), worldOrigin));

  std::sort(sprites.begin(), sprites.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
  for(const auto& sprite: sprites) {
	game::GameData::getInstance()->window.draw(sprite.first);
  }

  game::GameData::getInstance()->window.display();
}
} // namespace simulation
