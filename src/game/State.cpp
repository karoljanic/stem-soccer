#include "State.hpp"
#include "GameData.hpp"

namespace game {
void State::handleInput() {
  game::GameData::getInstance()->inputs.updateEvents();

  sf::Event event;
  while (GameData::getInstance()->window.pollEvent(event)) {
	if (event.type == sf::Event::Closed) {
	  GameData::getInstance()->window.close();
	}

	if (sf::Event::MouseButtonPressed == event.type) {
	  GameData::getInstance()->inputs.addEvent(event.mouseButton.button);
	}

	if (sf::Event::MouseButtonReleased == event.type) {
	  GameData::getInstance()->inputs.removeEvent(event.mouseButton.button);
	}

	if (sf::Event::KeyPressed == event.type) {
	  GameData::getInstance()->inputs.addEvent(event.key.code);
	}

	if (sf::Event::KeyReleased == event.type) {
	  GameData::getInstance()->inputs.removeEvent(event.key.code);
	}
  }
}
} // namespace game