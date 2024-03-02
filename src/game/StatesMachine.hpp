#pragma once

#include "State.hpp"

#include <stack>
#include <memory>

namespace game {
class StatesMachine {
 private:
  std::stack<std::unique_ptr<State>> states;
  std::unique_ptr<State> newState;

 public:
  StatesMachine();
  ~StatesMachine() = default;

  void addState();
  void removeState();
  void processStateChanges();
  const std::unique_ptr<State>& getActiveState();
};
} // namespace game
