#pragma once

#include <cstdint>

namespace football {
class PlayerModel {
 private:
  uint16_t cellX;
  uint16_t cellY;
  uint16_t cellZ;

 public:
  PlayerModel();
};
}  // namespace football
