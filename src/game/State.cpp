#include "State.hpp"
#include "GameData.hpp"

namespace game {
void State::handleInput() {
  sf::Event event;

  while (GameData::getInstance()->window.pollEvent(event)) {
	if (event.type == sf::Event::Closed) {
	  GameData::getInstance()->window.close();
	}
  }
}

void State::init() {

}

void State::pause() {

}

void State::resume() {

}
} // namespace game