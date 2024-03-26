#pragma once

#include <cstdint>

namespace simulation {
class PlayerStats {
 public:
  PlayerStats() = default;
  explicit PlayerStats(uint8_t pace,
					   uint8_t shooting,
					   uint8_t passing,
					   uint8_t dribbling,
					   uint8_t defending,
					   uint8_t physicality,
					   uint8_t goalkeeping);

  uint8_t getPace() const;
  uint8_t getShooting() const;
  uint8_t getPassing() const;
  uint8_t getDribbling() const;
  uint8_t getDefending() const;
  uint8_t getPhysicality() const;
  uint8_t getGoalkeeping() const;

 private:
  uint8_t pace;
  uint8_t shooting;
  uint8_t passing;
  uint8_t dribbling;
  uint8_t defending;
  uint8_t physicality;
  uint8_t goalkeeping;
};
} // namespace simulation
