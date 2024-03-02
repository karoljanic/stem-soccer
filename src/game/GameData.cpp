#include "GameData.hpp"

namespace game {
GameData::GameData() {}

std::shared_ptr<GameData> GameData::getInstance() {
  if (GameData::gameData == nullptr) {
	GameData::gameData = std::make_unique<GameData>();
  }
  return GameData::gameData;
}
} // namespace game
