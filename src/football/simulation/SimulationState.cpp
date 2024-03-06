#include "SimulationState.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../game/GameData.hpp"

namespace football {
void SimulationState::init() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_BACKGROUND_TEXTURE, "simulation_background");

  backgroundTexture = game::GameData::getInstance()->assets.getTexture("simulation_background");
  background.setTexture(backgroundTexture);

  float centerX = static_cast<float>(game::GameData::getInstance()->window.getSize().x) / 2 -
                  config::WindowConfig::SIMULATION_AREA_BLOCK_WIDTH / 2;
  float centerY = static_cast<float>(game::GameData::getInstance()->window.getSize().y) / 2;

  arena = std::make_unique<FootballArena>(sf::Vector2f{centerX, centerY});
  ball = std::make_unique<FootballBall>(sf::Vector2f{centerX, centerY});

  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER1_TEXTURE, sf::Vector2f{centerX + 50, centerY + 50}));
  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER1_TEXTURE, sf::Vector2f{centerX + 50, centerY - 50}));
  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER1_TEXTURE, sf::Vector2f{centerX - 50, centerY + 50}));
  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER1_TEXTURE, sf::Vector2f{centerX - 50, centerY - 50}));

  centerX += 200;
  centerY -= 200;

  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER2_TEXTURE, sf::Vector2f{centerX + 50, centerY + 50}));
  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER2_TEXTURE, sf::Vector2f{centerX + 50, centerY - 50}));
  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER2_TEXTURE, sf::Vector2f{centerX - 50, centerY + 50}));
  players.push_back(
      std::make_unique<FootballPlayer>(config::AssetsConfig::PLAYER2_TEXTURE, sf::Vector2f{centerX - 50, centerY - 50}));
}

void SimulationState::pause() {}

void SimulationState::resume() {}

void SimulationState::update(float dt) {
  arena->update();
  for (auto& player : players) {
    player->update();
  }
  ball->update();
}

void SimulationState::draw(float dt) {
  game::GameData::getInstance()->window.clear();
  game::GameData::getInstance()->window.draw(background);
  arena->draw();
  for (auto& player : players) {
    player->draw();
  }
  ball->draw();
  game::GameData::getInstance()->window.display();
}
}  // namespace football
