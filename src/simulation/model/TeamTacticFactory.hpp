#pragma once

#include "TeamTactic.hpp"

namespace simulation {
class TeamTacticFactory {
 public:
  enum class FormationType {
	FORMATION_4_4_2,
	FORMATION_4_3_3,
	RANDOM
  };

  TeamTacticFactory() = delete;
  static TeamTactic createTeamTactic(FormationType formationType);
};
} // namespace simulation
