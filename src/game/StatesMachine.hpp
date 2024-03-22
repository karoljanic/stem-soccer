#pragma once

#include "State.hpp"

#include <stack>
#include <memory>

namespace game {
class StatesMachine {
 public:
  StatesMachine();
  ~StatesMachine() = default;

  void addState(std::unique_ptr<State> state);
  void removeState();
  void replaceState(std::unique_ptr<State> state);
  void processStateChanges();
  const std::unique_ptr<State> &getActiveState();

 private:
  std::stack<std::unique_ptr<State>> states;
  std::unique_ptr<State> newState;
  bool addStateFlag;
  bool removeStateFlag;
  bool replaceStateFlag;
};
} // namespace game
