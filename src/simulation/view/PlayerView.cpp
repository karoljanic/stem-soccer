#include "PlayerView.hpp"
#include "../../game/GameData.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
PlayerView::PlayerView(const std::string &textureName, const sf::Vector2f &position) {
  game::GameData::getInstance()->assets.loadTexture(textureName, textureName);
  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(textureName));
  footballer.setPosition(position);
  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
//  footballer.scale(-1, 1);
}

void PlayerView::update() {
  animationFrame++;
  if (animationFrame > 3) {
	animationFrame = 0;
  }
  footballer.setTextureRect(
	  sf::IntRect(0, 0, config::SimulationConfig::PLAYER_WIDTH, config::SimulationConfig::PLAYER_HEIGHT));
  footballer.setTextureRect(sf::IntRect(config::SimulationConfig::PLAYER_WIDTH * animationFrame, 0,
										config::SimulationConfig::PLAYER_WIDTH,
										config::SimulationConfig::PLAYER_HEIGHT));
}

void PlayerView::draw() {
  game::GameData::getInstance()->window.draw(footballer);
}
} // namespace simulation
