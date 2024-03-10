#include "BallModel.hpp"

namespace simulation {
void BallModel::init() {
  cellX = 0;
  cellY = 0;
  cellZ = 0;
}

void BallModel::update() {}

void BallModel::moveAbsolute(uint16_t xPos, uint16_t yPos, uint16_t zPos) {
  cellX = xPos;
  cellY = yPos;
  cellZ = zPos;
}

void BallModel::moveRelative(int16_t xDelta, int16_t yDelta, int16_t zDelta) {
  cellX += xDelta;
  cellY += yDelta;
  cellZ += zDelta;
}
} // namespace simulation
