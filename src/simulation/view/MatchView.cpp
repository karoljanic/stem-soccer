#include "MatchView.hpp"
#include "../../game/GameData.hpp"
#include <utility>
#include <vector>
#include <algorithm>

namespace simulation {
void MatchView::init(MatchModel *matchModel) {
  matchModelPtr = matchModel;
}

void MatchView::draw() {
  const float centerX = static_cast<float>(game::GameData::getInstance()->window.getSize().x) / 2;
  const float centerY = static_cast<float>(game::GameData::getInstance()->window.getSize().y) / 2;
  const sf::Vector3f origin = {centerX, centerY, 0};

  game::GameData::getInstance()->window.clear();
  stadiumViewDrawer.draw(origin);

  std::vector<std::pair<sf::Sprite, float>> sprites;
  for (const auto &player : matchModelPtr->getFirstTeamPlayers()) {
	sprites.push_back(playerViewDrawer.draw(player, origin));
  }

  for (const auto &player : matchModelPtr->getSecondTeamPlayers()) {
	sprites.push_back(playerViewDrawer.draw(player, origin));
  }

  sprites.push_back(ballViewDrawer.draw(matchModelPtr->getBall(), origin));

  std::sort(sprites.begin(), sprites.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
  for(const auto& sprite: sprites) {
	game::GameData::getInstance()->window.draw(sprite.first);
  }

  game::GameData::getInstance()->window.display();
}
} // namespace simulation
