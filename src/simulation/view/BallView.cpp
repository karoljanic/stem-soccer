#include "BallView.hpp"
#include "../../game/GameData.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
void BallView::init(const sf::Vector3f &position) {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::BALL_TEXTURE, "ball");
  ball.setTexture(game::GameData::getInstance()->assets.getTexture("ball"));
  ball.setPosition(sf::Vector2f(position.x, position.y));

  ball.setOrigin(ball.getGlobalBounds().width / 2, ball.getGlobalBounds().height / 2);
  ball.setScale(config::SimulationConfig::BALL_SCALE, config::SimulationConfig::BALL_SCALE);
}

void BallView::update() {
  ball.rotate(config::SimulationConfig::BALL_ROTATION);
}

void BallView::draw() {
  game::GameData::getInstance()->window.draw(ball);
}
}  // namespace simulation
