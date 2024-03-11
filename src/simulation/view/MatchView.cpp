#include "MatchView.hpp"
#include "../../game/GameData.hpp"

namespace simulation {
void MatchView::init(const MatchModel &matchModel, const sf::Vector3f &origin) {
  matchModelPtr = std::make_shared<MatchModel>(matchModel);
  worldOrigin = origin;
}

void MatchView::draw() {
  game::GameData::getInstance()->window.clear();
  stadiumViewDrawer.draw(worldOrigin);

  for (const auto &player : matchModelPtr->getFirstTeamPlayers()) {
	playerViewDrawer.draw(player, worldOrigin);
  }

  for (const auto &player : matchModelPtr->getSecondTeamPlayers()) {
	playerViewDrawer.draw(player, worldOrigin);
  }

  ballViewDrawer.draw(matchModelPtr->getBall(), worldOrigin);

  game::GameData::getInstance()->window.display();
}
} // namespace simulation
