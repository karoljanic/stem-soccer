#include "GameData.hpp"

namespace game {
std::unique_ptr<GameData> GameData::gameData = nullptr;

GameData::GameData() {}

const std::unique_ptr<GameData>& GameData::getInstance() {
  if (GameData::gameData == nullptr) {
	GameData::gameData = std::make_unique<GameData>();
  }
  return GameData::gameData;
}
} // namespace game
