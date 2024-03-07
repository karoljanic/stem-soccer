#include "FootballPlayer.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/WindowConfig.hpp"
#include "../../game/GameData.hpp"

namespace football {
FootballPlayer::FootballPlayer(const std::string& textureName, const sf::Vector2f& position) {
  game::GameData::getInstance()->assets.loadTexture(textureName, textureName);
  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(textureName));
  footballer.setPosition(position);
  footballer.setScale(config::WindowConfig::SIMULATION_PLAYER_SCALE, config::WindowConfig::SIMULATION_PLAYER_SCALE);
//  footballer.scale(-1, 1);
}

void FootballPlayer::update() {
  animationFrame++;
  if (animationFrame > 3) {
    animationFrame = 0;
  }
  footballer.setTextureRect(
      sf::IntRect(0, 0, config::WindowConfig::SIMULATION_PLAYER_WIDTH, config::WindowConfig::SIMULATION_PLAYER_HEIGHT));
  footballer.setTextureRect(sf::IntRect(config::WindowConfig::SIMULATION_PLAYER_WIDTH * animationFrame, 0,
                                        config::WindowConfig::SIMULATION_PLAYER_WIDTH,
                                        config::WindowConfig::SIMULATION_PLAYER_HEIGHT));
}

void FootballPlayer::draw() {
  game::GameData::getInstance()->window.draw(footballer);
}
}  // namespace football