#include "PlayerViewDrawer.hpp"
#include "../Utils.hpp"
#include "../../game/GameData.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/SimulationConfig.hpp"

#include <iostream>

namespace simulation {
PlayerViewDrawer::PlayerViewDrawer() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_BACK_TEXTURE, "kit1-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_DEATH_TEXTURE, "kit1-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FRONT_TEXTURE, "kit1-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FROZEN_TEXTURE, "kit1-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_IDLE_TEXTURE, "kit1-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_WALK_TEXTURE, "kit1-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_BACK_TEXTURE, "kit2-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_DEATH_TEXTURE, "kit2-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FRONT_TEXTURE, "kit2-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FROZEN_TEXTURE, "kit2-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_IDLE_TEXTURE, "kit2-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_WALK_TEXTURE, "kit2-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_BACK_TEXTURE, "kit3-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_DEATH_TEXTURE, "kit3-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FRONT_TEXTURE, "kit3-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FROZEN_TEXTURE, "kit3-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_IDLE_TEXTURE, "kit3-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_WALK_TEXTURE, "kit3-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_BACK_TEXTURE, "kit4-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_DEATH_TEXTURE, "kit4-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FRONT_TEXTURE, "kit4-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FROZEN_TEXTURE, "kit4-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_IDLE_TEXTURE, "kit4-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_WALK_TEXTURE, "kit4-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_BACK_TEXTURE, "kit5-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_DEATH_TEXTURE, "kit5-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FRONT_TEXTURE, "kit5-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FROZEN_TEXTURE, "kit5-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_IDLE_TEXTURE, "kit5-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_WALK_TEXTURE, "kit5-walk");

  footballer.setTexture(game::GameData::getInstance()->assets.getTexture("kit1-idle"));
  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
}

void PlayerViewDrawer::draw(const PlayerModel &playerModel, const sf::Vector3f &origin) {
  const auto isometricCoordinate = cartesianToIsometric(playerModel.getPosition());
  footballer.setPosition(isometricCoordinate.x + origin.x, isometricCoordinate.y + origin.y);
//  footballer.scale(-1, 1);

  const std::pair<PlayerModel::AnimationState, int> animationState = playerModel.getAnimationState();
  std::cout << "Animation state: " << static_cast<int>(animationState.first) << " " << animationState.second
			<< std::endl;

//  switch (animationState.first) {
//	case PlayerModel::AnimationState::IDLE:break;
//	case PlayerModel::AnimationState::WALKING_UP:break;
//	case PlayerModel::AnimationState::WALKING_DOWN:break;
//	case PlayerModel::AnimationState::WALKING_LEFT:break;
//	case PlayerModel::AnimationState::WALKING_RIGHT:break;
//  }

  footballer.setTextureRect(
	  sf::IntRect(0, 0, config::SimulationConfig::PLAYER_WIDTH, config::SimulationConfig::PLAYER_HEIGHT));
  footballer.setTextureRect(sf::IntRect(
	  config::SimulationConfig::PLAYER_WIDTH * animationState.second, 0,
	  config::SimulationConfig::PLAYER_WIDTH,
	  config::SimulationConfig::PLAYER_HEIGHT));

  game::GameData::getInstance()->window.draw(footballer);
}
} // namespace simulation
