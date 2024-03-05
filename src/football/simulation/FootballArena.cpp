#include "FootballArena.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../game/GameData.hpp"

namespace football {
FootballArena::FootballArena(const sf::Vector2f &position) {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_TEXTURE, "grass");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_SAND_TEXTURE, "sand");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_SNOW_TEXTURE, "snow");
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_GRASS_GROUND1_TEXTURE, "gg1");
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

//  for (int i = -12; i <= 12; i++) {
//	for (int j = -15; j <= 15; j++) {
  for (int i = -6; i <= 6; i++) {
	for (int j = -9; j <= 9; j++) {
	  if (i == -6 && j == -9) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg6")));
	  } else if (i == 6 && j == 9) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg5")));
	  } else if (i == -6 && j == 9) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg4")));
	  } else if (i == 6 && j == -9) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg3")));
	  } else if (i == -6 && j > -9 && j < 9) {
		if (j == 0) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg8")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
		}
	  } else if (i == 6 && j > -9 && j < 9) {
		if (j == 0) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg10")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
		}
	  } else if (j == 9 && i >= -6 && i <= 6) {
		if (i >= -1 && i <= 1) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("ground")));
		} else if (i == -4 || i == 4) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg9")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
		}
	  } else if (j == -9 && i >= -6 && i <= 6) {
		if (i >= -1 && i <= 1) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("ground")));
		} else if (i == -4 || i == 4) {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg7")));
		} else {
		  blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
		}
	  } else if (j == 0 && i >= -6 && i <= 6) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
	  } else if ((i == 4 || i == -4) && (j <= 8 && j >= 7 || j >= -8 && j <= -7)) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg2")));
	  } else if ((i <= 3 && i >= 0 || i >= -3 && i <= 0) && (j == 6 || j == -6)) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg1")));
	  } else if (i == 4 && j == 6) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg3")));
	  } else if (i == -4 && j == 6) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg6")));
	  } else if (i == 4 && j == -6) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg5")));
	  } else if (i == -4 && j == -6) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("gg4")));
	  } else if (i < 6 && i > -6 && j < 9 && j > -9) {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("grass")));
	  } else {
		blocks.emplace_back(std::make_unique<sf::Sprite>(game::GameData::getInstance()->assets.getTexture("sand")));
	  }

	  blocks.back()->setPosition(config::cartesianToIsometric(i - 0.75, j - 0.75) + position);
	}
  }
}

void FootballArena::update() {}

void FootballArena::draw() {
  for (auto &block : blocks) {
	game::GameData::getInstance()->window.draw(*block);
  }
}
} // namespace football
