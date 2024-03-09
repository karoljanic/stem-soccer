#pragma once

#include <cstdint>

namespace simulation {
class BallModel {
 private:
  uint16_t cellX;
  uint16_t cellY;
  uint16_t cellZ;

 public:
  BallModel();
};
}  // namespace simulation
