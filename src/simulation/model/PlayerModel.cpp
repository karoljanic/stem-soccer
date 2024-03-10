#include "PlayerModel.hpp"

namespace simulation {
void PlayerModel::init() {
  cellX = 0;
  cellY = 0;
  cellZ = 0;
}

void PlayerModel::update() {}

void PlayerModel::moveAbsolute(uint16_t xPos, uint16_t yPos, uint16_t zPos) {
  cellX = xPos;
  cellY = yPos;
  cellZ = zPos;
}

void PlayerModel::moveRelative(int16_t xDelta, int16_t yDelta, int16_t zDelta) {
  cellX += xDelta;
  cellY += yDelta;
  cellZ += zDelta;
}
} // namespace simulation
