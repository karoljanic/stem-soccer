#include "FootballArena.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../game/GameData.hpp"

namespace football {
FootballArena::FootballArena(const sf::Vector2f& position) {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_TEXTURE, "grass");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_SAND_TEXTURE, "sand");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_SNOW_TEXTURE, "snow");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GROUND_TEXTURE, "ground");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND1_TEXTURE, "gg1");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND2_TEXTURE, "gg2");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND3_TEXTURE, "gg3");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND4_TEXTURE, "gg4");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND5_TEXTURE, "gg5");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND6_TEXTURE, "gg6");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND7_TEXTURE, "gg7");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND8_TEXTURE, "gg8");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND9_TEXTURE, "gg9");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND10_TEXTURE, "gg10");

  for (int i = -config::WindowConfig::SIMULATION_STADIUM_WIDTH; i <= config::WindowConfig::SIMULATION_STADIUM_WIDTH; i++) {
    for (int j = -config::WindowConfig::SIMULATION_STADIUM_HEIGHT; j <= config::WindowConfig::SIMULATION_STADIUM_HEIGHT; j++) {
      if (i == -config::WindowConfig::SIMULATION_AREA_WIDTH && j == -config::WindowConfig::SIMULATION_AREA_HEIGHT) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg6")));
      }
      else if (i == config::WindowConfig::SIMULATION_AREA_WIDTH && j == config::WindowConfig::SIMULATION_AREA_HEIGHT) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg5")));
      }
      else if (i == -config::WindowConfig::SIMULATION_AREA_WIDTH && j == config::WindowConfig::SIMULATION_AREA_HEIGHT) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg4")));
      }
      else if (i == config::WindowConfig::SIMULATION_AREA_WIDTH && j == -config::WindowConfig::SIMULATION_AREA_HEIGHT) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg3")));
      }
      else if (i == -config::WindowConfig::SIMULATION_AREA_WIDTH && abs(j) < config::WindowConfig::SIMULATION_AREA_HEIGHT) {
        if (j == 0) {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg8")));
        }
        else {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
        }
      }
      else if (i == config::WindowConfig::SIMULATION_AREA_WIDTH && abs(j) < config::WindowConfig::SIMULATION_AREA_HEIGHT) {
        if (j == 0) {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg10")));
        }
        else {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
        }
      }
      else if (j == config::WindowConfig::SIMULATION_AREA_HEIGHT && abs(i) <= config::WindowConfig::SIMULATION_AREA_WIDTH) {
        if (abs(i) <= config::WindowConfig::SIMULATION_AREA_GOAL_WIDTH) {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("ground")));
        }
        else if (abs(i) == config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH) {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg9")));
        }
        else {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
        }
      }
      else if (j == -config::WindowConfig::SIMULATION_AREA_HEIGHT && abs(i) <= config::WindowConfig::SIMULATION_AREA_WIDTH) {
        if (abs(i) <= config::WindowConfig::SIMULATION_AREA_GOAL_WIDTH) {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("ground")));
        }
        else if (abs(i) == config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH) {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg7")));
        }
        else {
          blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
        }
      }
      else if (j == 0 && abs(i) <= config::WindowConfig::SIMULATION_AREA_WIDTH) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
      }
      else if (abs(i) == config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH &&
               (j < config::WindowConfig::SIMULATION_AREA_HEIGHT &&
                    j >= (config::WindowConfig::SIMULATION_AREA_HEIGHT -
                          config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT) ||
                j > -config::WindowConfig::SIMULATION_AREA_HEIGHT &&
                    j <= -(config::WindowConfig::SIMULATION_AREA_HEIGHT -
                           config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT))) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
      }
      else if ((i < config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH && i >= 0 ||
                i > -config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH && i <= 0) &&
               (j == (config::WindowConfig::SIMULATION_AREA_HEIGHT -
                      config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT - 1) ||
                j == -(config::WindowConfig::SIMULATION_AREA_HEIGHT -
                       config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT - 1))) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
      }
      else if (i == config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH &&
               j == (config::WindowConfig::SIMULATION_AREA_HEIGHT -
                     config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT - 1)) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg3")));
      }
      else if (i == -config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH &&
               j == (config::WindowConfig::SIMULATION_AREA_HEIGHT -
                     config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT - 1)) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg6")));
      }
      else if (i == config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH &&
               j == -(config::WindowConfig::SIMULATION_AREA_HEIGHT -
                      config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT - 1)) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg5")));
      }
      else if (i == -config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_WIDTH &&
               j == -(config::WindowConfig::SIMULATION_AREA_HEIGHT -
                      config::WindowConfig::SIMULATION_AREA_GOALKEEPER_FIELD_HEIGHT - 1)) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg4")));
      }
      else if (i < config::WindowConfig::SIMULATION_AREA_WIDTH && i > -config::WindowConfig::SIMULATION_AREA_WIDTH &&
               j < config::WindowConfig::SIMULATION_AREA_HEIGHT && j > -config::WindowConfig::SIMULATION_AREA_HEIGHT) {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("grass")));
      }
      else {
        blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("sand")));
      }

      blocks.back()->setPosition(config::cartesianToIsometric(static_cast<float>(i), static_cast<float>(j)) + position);
      blocks.back()->setScale(config::WindowConfig::SIMULATION_AREA_BLOCK_SCALE,
                              config::WindowConfig::SIMULATION_AREA_BLOCK_SCALE);
    }
  }
}

void FootballArena::update() {}

void FootballArena::draw() {
  for (auto& block : blocks) {
    game::GameData::getInstance()->window.draw(*block);
  }
}
}  // namespace football
