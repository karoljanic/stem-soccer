#include "FootballPlayer.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../game/GameData.hpp"

namespace football {
FootballPlayer::FootballPlayer(const std::string& textureName, const sf::Vector2f& position) {
  game::GameData::getInstance()->assets.loadTexture(textureName, textureName);
  footballer.setTexture(game::GameData::getInstance()->assets.getTexture(textureName));
  footballer.setPosition(position);
  footballer.setScale(3.5f, 3.5f);
  footballer.scale(-1,1);
}

void FootballPlayer::update() {
  animationFrame++;
  if (animationFrame > 3) {
    animationFrame = 0;
  }
  footballer.setTextureRect(sf::IntRect(0, 0, 15, 19));
  footballer.setTextureRect(sf::IntRect(15 * animationFrame, 0, 15, 19));
}

void FootballPlayer::draw() {
  game::GameData::getInstance()->window.draw(footballer);
}
}  // namespace football