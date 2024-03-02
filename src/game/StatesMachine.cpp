#include "StatesMachine.hpp"

namespace game {
StatesMachine::StatesMachine() : states() {}
void StatesMachine::addState() {}
void StatesMachine::removeState() {}
void StatesMachine::processStateChanges() {}
const std::unique_ptr<State> &StatesMachine::getActiveState() { return states.top(); }

} // namespace game
