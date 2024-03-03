#include "StatesMachine.hpp"

namespace game {
StatesMachine::StatesMachine() : addStateFlag{false}, removeStateFlag{false}, replaceStateFlag{false} {}

void StatesMachine::addState(std::unique_ptr<State> state) {
  addStateFlag = true;
  newState = std::move(state);
}

void StatesMachine::removeState() {
  removeStateFlag = true;
}

void StatesMachine::replaceState(std::unique_ptr<State> state) {
  replaceStateFlag = true;
  newState = std::move(state);
}

void StatesMachine::processStateChanges() {
  if (removeStateFlag || replaceStateFlag) {
	if (!states.empty()) {
	  states.pop();
	}

	if (!states.empty()) {
	  states.top()->resume();
	}

	removeStateFlag = false;
  }

  if (addStateFlag || replaceStateFlag) {
	if (!states.empty()) {
	  states.top()->pause();
	}
	states.push(std::move(newState));
	states.top()->init();
	addStateFlag = false;
  }
}

const std::unique_ptr<State> &StatesMachine::getActiveState() { return states.top(); }

} // namespace game
