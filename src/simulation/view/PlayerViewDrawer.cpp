#include "PlayerViewDrawer.hpp"
#include "../Utils.hpp"
#include "../../game/GameData.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
PlayerViewDrawer::PlayerViewDrawer() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_BACK_TEXTURE, "kit1-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_DEATH_TEXTURE, "kit1-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FRONT_TEXTURE, "kit1-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_FROZEN_TEXTURE, "kit1-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_IDLE_TEXTURE, "kit1-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER1_WALK_TEXTURE, "kit1-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER2_BACK_TEXTURE, "kit2-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER2_DEATH_TEXTURE, "kit2-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER2_FRONT_TEXTURE, "kit2-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER2_FROZEN_TEXTURE, "kit2-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER2_IDLE_TEXTURE, "kit2-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER2_WALK_TEXTURE, "kit2-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER3_BACK_TEXTURE, "kit3-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER3_DEATH_TEXTURE, "kit3-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER3_FRONT_TEXTURE, "kit3-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER3_FROZEN_TEXTURE, "kit3-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER3_IDLE_TEXTURE, "kit3-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER3_WALK_TEXTURE, "kit3-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER4_BACK_TEXTURE, "kit4-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER4_DEATH_TEXTURE, "kit4-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER4_FRONT_TEXTURE, "kit4-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER4_FROZEN_TEXTURE, "kit4-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER4_IDLE_TEXTURE, "kit4-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER4_WALK_TEXTURE, "kit4-walk");

  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER5_BACK_TEXTURE, "kit5-back");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER5_DEATH_TEXTURE, "kit5-death");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER5_FRONT_TEXTURE, "kit5-front");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER5_FROZEN_TEXTURE, "kit5-frozen");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER5_IDLE_TEXTURE, "kit5-idle");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::PLAYER5_WALK_TEXTURE, "kit5-walk");

  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
}

void PlayerViewDrawer::draw(const PlayerModel &playerModel, const sf::Vector3f &origin) {
  const std::pair<PlayerModel::AnimationState, sf::Vector3f> animationState = playerModel.getAnimationState();

  switch (animationState.first) {
	case PlayerModel::AnimationState::IDLE:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_NO_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-idle"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
		  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_UP:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-walk"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
		  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_DOWN:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-walk"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * (playerModel.getAnimationFrame() + 1), 0,
		  -currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_LEFT:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_NO_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-back"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
		  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_RIGHT:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_NO_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-front"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
		  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_UP_LEFT:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_NO_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-back"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
		  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_UP_RIGHT:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-walk"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
		  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_DOWN_LEFT:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-walk"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * (playerModel.getAnimationFrame() + 1), 0,
		  -currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
	case PlayerModel::AnimationState::WALKING_DOWN_RIGHT:
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_NO_WALK_WIDTH;
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(playerModel.getKit() + "-front"));
	  footballer.setTextureRect(sf::IntRect(
		  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
		  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));
	  break;
  }

  footballer.setOrigin(footballer.getGlobalBounds().width * 0.4F, footballer.getGlobalBounds().height * 0.25F);

  const auto isometricCoordinate = cartesianToIsometric(
	  -sf::Vector3f{static_cast<float>(playerModel.getPosition().x),
					static_cast<float>(playerModel.getPosition().y + 1),
					static_cast<float>(playerModel.getPosition().z)} + animationState.second);
  footballer.setPosition(isometricCoordinate.x + origin.x, isometricCoordinate.y + origin.y);

  game::GameData::getInstance()->window.draw(footballer);
}
} // namespace simulation
