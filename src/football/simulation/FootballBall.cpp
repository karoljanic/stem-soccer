#include "FootballBall.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../game/GameData.hpp"

namespace football {
FootballBall::FootballBall(const sf::Vector2f& position) {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::BALL_TEXTURE, "ball");
  ball.setTexture(game::GameData::getInstance()->assets.getTexture("ball"));
  ball.setPosition(position);

  ball.setOrigin(ball.getGlobalBounds().width / 2, ball.getGlobalBounds().height / 2);
  ball.setScale(0.4f, 0.4f);
}

void FootballBall::update() {
  ball.rotate(50);
}

void FootballBall::draw() {
  game::GameData::getInstance()->window.draw(ball);
}
}  // namespace football
