#include "State.hpp"

namespace game {
void State::handleInput() {
  sf::Event event;

  while (window.pollEvent(event)) {
	if (event.type == sf::Event::Closed) {
	  window.close();
	}
  }
}
} // namespace game