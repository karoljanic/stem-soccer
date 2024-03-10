#pragma once

#include <cstdint>

namespace simulation {
class PlayerModel {
 private:
  uint16_t cellX;
  uint16_t cellY;
  uint16_t cellZ;

 public:
  PlayerModel() = default;
  void init();
  void update();
  void moveAbsolute(uint16_t xPos, uint16_t yPos, uint16_t zPos);
  void moveRelative(int16_t xDelta, int16_t yDelta, int16_t zDelta);
};
}  // namespace simulation
