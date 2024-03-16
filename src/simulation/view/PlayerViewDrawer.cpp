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

  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
}

void PlayerViewDrawer::draw(const PlayerModel &playerModel, const sf::Vector3f &origin) {
  const std::pair<PlayerModel::AnimationState, sf::Vector2f> animationState = playerModel.getAnimationState();

  switch (animationState.first) {
	case PlayerModel::AnimationState::IDLE:
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture("kit1-idle"));
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_NO_WALK_WIDTH;
	  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
	  break;
	case PlayerModel::AnimationState::WALKING_UP:
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture("kit1-walk"));
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
	  break;
	case PlayerModel::AnimationState::WALKING_DOWN:
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture("kit1-walk"));
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
	  break;
	case PlayerModel::AnimationState::WALKING_LEFT:
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture("kit1-walk"));
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setScale(-config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
	  break;
	case PlayerModel::AnimationState::WALKING_RIGHT:
	  footballer.setTexture(game::GameData::getInstance()->assets.getTexture("kit1-walk"));
	  currentAnimationFrameWidth = config::SimulationConfig::PLAYER_WALK_WIDTH;
	  footballer.setScale(config::SimulationConfig::PLAYER_SCALE, config::SimulationConfig::PLAYER_SCALE);
	  break;
  }

  footballer.setTextureRect(sf::IntRect(
	  currentAnimationFrameWidth * playerModel.getAnimationFrame(), 0,
	  currentAnimationFrameWidth, config::SimulationConfig::PLAYER_HEIGHT));

  footballer.setOrigin(footballer.getGlobalBounds().width / 2, footballer.getGlobalBounds().height / 2);

  const auto isometricCoordinate = cartesianToIsometric(playerModel.getPosition() + sf::Vector3i{1, 0, 0});
  footballer.setPosition(isometricCoordinate.x + origin.x, isometricCoordinate.y + origin.y);

  game::GameData::getInstance()->window.draw(footballer);
}
} // namespace simulation
