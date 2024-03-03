#include "InputManager.hpp"

namespace game {
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window) const {
  return sf::Mouse::getPosition(window);
}

bool InputManager::isClicked(sf::IntRect rect, sf::Mouse::Button button, sf::RenderWindow &window) {
  return getButtonDown(button) && rect.contains(sf::Mouse::getPosition(window));
}

bool InputManager::getButtonUp(sf::Mouse::Button btn) {
  return buttons.find(btn) != buttons.end() && buttons[btn] == InputState::Up;
}

bool InputManager::getButton(sf::Mouse::Button btn) {
  return buttons.find(btn) != buttons.end() && buttons[btn] == InputState::Pressed;
}

bool InputManager::getButtonDown(sf::Mouse::Button btn) {
  return buttons.find(btn) != buttons.end() && buttons[btn] == InputState::Down;
}

bool InputManager::getKeyUp(sf::Keyboard::Key key) {
  return keys.find(key) != keys.end() && keys[key] == InputState::Up;
}

bool InputManager::getKey(sf::Keyboard::Key key) {
  return keys.find(key) != keys.end() && keys[key] == InputState::Pressed;
}

bool InputManager::getKeyDown(sf::Keyboard::Key key) {
  return keys.find(key) != keys.end() && keys[key] == InputState::Down;
}

void InputManager::addEvent(sf::Keyboard::Key key) {
  if (keys.find(key) == keys.end()) {
	keys[key] = InputState::Down;
  }
}

void InputManager::removeEvent(sf::Keyboard::Key key) {
  if (keys.find(key) != keys.end()) {
	keys[key] = InputState::Up;
  }
}

void InputManager::addEvent(sf::Mouse::Button btn) {
  if (buttons.find(btn) == buttons.end()) {
	buttons[btn] = InputState::Down;
  }
}

void InputManager::removeEvent(sf::Mouse::Button btn) {
  if (buttons.find(btn) != buttons.end()) {
	buttons[btn] = InputState::Up;
  }
}

void InputManager::updateEvents() {
  for (auto key = keys.begin(); key != keys.end();)
	if (key->second == InputState::Down) {
	  key->second = InputState::Pressed;
	  ++key;
	} else if (key->second == InputState::Up) {
	  keys.erase(key++);
	} else {
	  ++key;
	}

  for (auto btn = buttons.begin(); btn != buttons.end();)
	if (btn->second == InputState::Down) {
	  btn->second = InputState::Pressed;
	  ++btn;
	} else if (btn->second == InputState::Up) {
	  buttons.erase(btn++);
	} else {
	  ++btn;
	}
}
} // namespace game