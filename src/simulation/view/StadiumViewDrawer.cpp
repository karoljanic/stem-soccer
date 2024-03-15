#include "StadiumViewDrawer.hpp"
#include "../../game/GameData.hpp"
#include "../Utils.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/SimulationConfig.hpp"

namespace simulation {
StadiumViewDrawer::StadiumViewDrawer() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::ARENA_BACKGROUND_TEXTURE,
													"simulation_background");
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

  backgroundTexture = game::GameData::getInstance()->assets.getTexture("simulation_background");
  background.setTexture(backgroundTexture);

  for (int i = -(config::SimulationConfig::STADIUM_WIDTH / 2 + 1);
	   i <= (config::SimulationConfig::STADIUM_WIDTH / 2 + 1); i++) {
	for (int j = -(config::SimulationConfig::STADIUM_LENGTH / 2 + 1);
		 j <= (config::SimulationConfig::STADIUM_LENGTH / 2 + 1); j++) {
	  if (i == -(config::SimulationConfig::PITCH_WIDTH / 2 + 1)
		  && j == -(config::SimulationConfig::PITCH_LENGTH / 2 + 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg6")));
	  } else if (i == (config::SimulationConfig::PITCH_WIDTH / 2 + 1)
		  && j == (config::SimulationConfig::PITCH_LENGTH / 2 + 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg5")));
	  } else if (i == -(config::SimulationConfig::PITCH_WIDTH / 2 + 1)
		  && j == (config::SimulationConfig::PITCH_LENGTH / 2 + 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg4")));
	  } else if (i == (config::SimulationConfig::PITCH_WIDTH / 2 + 1)
		  && j == -(config::SimulationConfig::PITCH_LENGTH / 2 + 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg3")));
	  } else if (i == -(config::SimulationConfig::PITCH_WIDTH / 2 + 1)
		  && abs(j) < (config::SimulationConfig::PITCH_LENGTH / 2 + 1)) {
		if (j == 0) {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg8")));
		} else {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg2")));
		}
	  } else if (i == (config::SimulationConfig::PITCH_WIDTH / 2 + 1)
		  && abs(j) < (config::SimulationConfig::PITCH_LENGTH / 2 + 1)) {
		if (j == 0) {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg10")));
		} else {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg2")));
		}
	  } else if (j == (config::SimulationConfig::PITCH_LENGTH / 2 + 1)
		  && abs(i) <= (config::SimulationConfig::PITCH_WIDTH / 2 + 1)) {
		if (abs(i) <= (config::SimulationConfig::GOAL_WIDTH / 2)) {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("ground")));
		} else if (abs(i) == (config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1)) {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg9")));
		} else {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg1")));
		}
	  } else if (j == -(config::SimulationConfig::PITCH_LENGTH / 2 + 1)
		  && abs(i) <= (config::SimulationConfig::PITCH_WIDTH / 2 + 1)) {
		if (abs(i) <= (config::SimulationConfig::GOAL_WIDTH / 2)) {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("ground")));
		} else if (abs(i) == (config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1)) {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg7")));
		} else {
		  blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg1")));
		}
	  } else if (j == 0 && abs(i) <= (config::SimulationConfig::PITCH_WIDTH / 2 + 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg1")));
	  } else if (abs(i) == (config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1) &&
		  (j < (config::SimulationConfig::PITCH_LENGTH / 2 + 1) &&
			  j >= ((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
				  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH) ||
			  j > -(config::SimulationConfig::PITCH_LENGTH / 2 + 1) &&
				  j <= -((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
					  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH))) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg2")));
	  } else if ((i < (config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1) && i >= 0 ||
		  i > -(config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1) && i <= 0) &&
		  (j == ((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1) ||
			  j == -((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
				  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1))) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg1")));
	  } else if (i == (config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1) &&
		  j == ((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg3")));
	  } else if (i == -(config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1) &&
		  j == ((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg6")));
	  } else if (i == (config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1) &&
		  j == -((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg5")));
	  } else if (i == -(config::SimulationConfig::GOALKEEPER_FIELD_WIDTH / 2 + 1) &&
		  j == -((config::SimulationConfig::PITCH_LENGTH / 2 + 1) -
			  config::SimulationConfig::GOALKEEPER_FIELD_LENGTH - 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("gg4")));
	  } else if (i < (config::SimulationConfig::PITCH_WIDTH / 2 + 1)
		  && i > -(config::SimulationConfig::PITCH_WIDTH / 2 + 1) &&
		  j < (config::SimulationConfig::PITCH_LENGTH / 2 + 1)
		  && j > -(config::SimulationConfig::PITCH_LENGTH / 2 + 1)) {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("grass")));
	  } else {
		blocks.emplace_back(sf::Sprite(game::GameData::getInstance()->assets.getTexture("sand")));
	  }

	  const auto isometricCoordinate = cartesianToIsometric(sf::Vector3i{i - 1, j, 0});
	  blocks.back().setPosition(isometricCoordinate);
	  blocks.back().setScale(config::SimulationConfig::STADIUM_BLOCK_SCALE,
							 config::SimulationConfig::STADIUM_BLOCK_SCALE);
	}
  }
}

void StadiumViewDrawer::draw(const sf::Vector3f &origin) {
  game::GameData::getInstance()->window.draw(background);

  for (auto &block : blocks) {
	sf::Sprite currentBlock = block;
	currentBlock.setPosition(currentBlock.getPosition() + sf::Vector2f{origin.x, origin.y});
	game::GameData::getInstance()->window.draw(currentBlock);
  }
}
} // namespace simulation
