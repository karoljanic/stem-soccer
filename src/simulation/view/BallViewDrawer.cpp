#include "BallViewDrawer.hpp"
#include "../Utils.hpp"
#include "../../game/GameData.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
BallViewDrawer::BallViewDrawer() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::BALL_TEXTURE, "ball");
  ball.setTexture(game::GameData::getInstance()->assets.getTexture("ball"));

  ball.setOrigin(ball.getGlobalBounds().width / 2, ball.getGlobalBounds().height / 2);
  ball.setScale(config::SimulationConfig::BALL_SCALE, config::SimulationConfig::BALL_SCALE);
}

std::pair<sf::Sprite, float> BallViewDrawer::draw(const BallModel &ballModel, const sf::Vector3f &origin) {
  const auto isometricCoordinate = cartesianToIsometric(ballModel.getPosition());
  ball.setPosition(isometricCoordinate.x + origin.x, isometricCoordinate.y + origin.y);
  ball.setRotation(ballModel.getRotation());
  return {ball, ballModel.getPosition().x + ballModel.getPosition().y};
}
} // namespace simulation
