#include "PlayerViewDrawer.hpp"
#include "../Utils.hpp"
#include "../../game/GameData.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
PlayerViewDrawer::PlayerViewDrawer() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_TEXTURE, "kit1");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER2_TEXTURE, "kit2");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER3_TEXTURE, "kit3");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER4_TEXTURE, "kit4");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER5_TEXTURE, "kit5");
  footballer.setTexture(game::GameData::getInstance()->assets.getTexture("kit1"));
  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
}

void PlayerViewDrawer::draw(const PlayerModel &playerModel, const sf::Vector3f &origin) {
  const auto isometricCoordinate = cartesianToIsometric(playerModel.getPosition());
  footballer.setPosition(isometricCoordinate.x + origin.x, isometricCoordinate.y + origin.y);
//  footballer.scale(-1, 1);

  footballer.setTextureRect(
	  sf::IntRect(0, 0, config::SimulationConfig::PLAYER_WIDTH, config::SimulationConfig::PLAYER_HEIGHT));
  footballer.setTextureRect(sf::IntRect(
	  config::SimulationConfig::PLAYER_WIDTH * static_cast<uint8_t>(playerModel.getAnimationFrame()), 0,
	  config::SimulationConfig::PLAYER_WIDTH,
	  config::SimulationConfig::PLAYER_HEIGHT));

  game::GameData::getInstance()->window.draw(footballer);
}
} // namespace simulation
