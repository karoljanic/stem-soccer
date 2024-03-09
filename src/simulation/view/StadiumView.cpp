#include "StadiumView.hpp"
#include "../../game/GameData.hpp"
#include "../Utils.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
StadiumView::StadiumView(const sf::Vector2f &position) {
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

  for (int i = -config::SimulationConfig::STADIUM_WIDTH; i <= config::SimulationConfig::STADIUM_WIDTH; i++) {
	for (int j = -config::SimulationConfig::STADIUM_LENGTH; j <= config::SimulationConfig::STADIUM_LENGTH; j++) {
	  if (i == -config::SimulationConfig::PITCH_WIDTH && j == -config::SimulationConfig::PITCH_LENGTH) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg6")));
	  } else if (i == config::SimulationConfig::PITCH_WIDTH && j == config::SimulationConfig::PITCH_LENGTH) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg5")));
	  } else if (i == -config::SimulationConfig::PITCH_WIDTH && j == config::SimulationConfig::PITCH_LENGTH) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg4")));
	  } else if (i == config::SimulationConfig::PITCH_WIDTH && j == -config::SimulationConfig::PITCH_LENGTH) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg3")));
	  } else if (i == -config::SimulationConfig::PITCH_WIDTH && abs(j) < config::SimulationConfig::PITCH_LENGTH) {
		if (j == 0) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg8")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
		}
	  } else if (i == config::SimulationConfig::PITCH_WIDTH && abs(j) < config::SimulationConfig::PITCH_LENGTH) {
		if (j == 0) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg10")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
		}
	  } else if (j == config::SimulationConfig::PITCH_LENGTH && abs(i) <= config::SimulationConfig::PITCH_WIDTH) {
		if (abs(i) <= config::SimulationConfig::GOAL_WIDTH) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("ground")));
		} else if (abs(i) == config::SimulationConfig::GOALKEEPER_FIELD_WIDTH) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg9")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
		}
	  } else if (j == -config::SimulationConfig::PITCH_LENGTH && abs(i) <= config::SimulationConfig::PITCH_WIDTH) {
		if (abs(i) <= config::SimulationConfig::GOAL_WIDTH) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("ground")));
		} else if (abs(i) == config::SimulationConfig::GOALKEEPER_FIELD_WIDTH) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg7")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
		}
	  } else if (j == 0 && abs(i) <= config::SimulationConfig::PITCH_WIDTH) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
	  } else if (abs(i) == config::SimulationConfig::GOALKEEPER_FIELD_WIDTH &&
		  (j < config::SimulationConfig::PITCH_LENGTH &&
			  j >= (config::SimulationConfig::PITCH_LENGTH -
				  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH) ||
			  j > -config::SimulationConfig::PITCH_LENGTH &&
				  j <= -(config::SimulationConfig::PITCH_LENGTH -
					  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH))) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
	  } else if ((i < config::SimulationConfig::GOALKEEPER_FIELD_WIDTH && i >= 0 ||
		  i > -config::SimulationConfig::GOALKEEPER_FIELD_WIDTH && i <= 0) &&
		  (j == (config::SimulationConfig::PITCH_LENGTH -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1) ||
			  j == -(config::SimulationConfig::PITCH_LENGTH -
				  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1))) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
	  } else if (i == config::SimulationConfig::GOALKEEPER_FIELD_WIDTH &&
		  j == (config::SimulationConfig::PITCH_LENGTH -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg3")));
	  } else if (i == -config::SimulationConfig::GOALKEEPER_FIELD_WIDTH &&
		  j == (config::SimulationConfig::PITCH_LENGTH -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg6")));
	  } else if (i == config::SimulationConfig::GOALKEEPER_FIELD_WIDTH &&
		  j == -(config::SimulationConfig::PITCH_LENGTH -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg5")));
	  } else if (i == -config::SimulationConfig::GOALKEEPER_FIELD_WIDTH &&
		  j == -(config::SimulationConfig::PITCH_LENGTH -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg4")));
	  } else if (i < config::SimulationConfig::PITCH_WIDTH && i > -config::SimulationConfig::PITCH_WIDTH &&
		  j < config::SimulationConfig::PITCH_LENGTH && j > -config::SimulationConfig::PITCH_LENGTH) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("grass")));
	  } else {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("sand")));
	  }

	  blocks.back()->setPosition(cartesianToIsometric(
		  sf::Vector2f{static_cast<float>(i), static_cast<float>(j)}) + position);
	  blocks.back()->setScale(config::SimulationConfig::STADIUM_BLOCK_SCALE,
							  config::SimulationConfig::STADIUM_BLOCK_SCALE);
	}
  }
}

void StadiumView::update() {}

void StadiumView::draw() {
  for (auto &block : blocks) {
	game::GameData::getInstance()->window.draw(*block);
  }
}
} // namespace simulation
