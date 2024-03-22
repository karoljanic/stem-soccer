#pragma once

#include <SFML/Graphics.hpp>
#include <map>

namespace game {
class InputManager {
 public:
  enum InputState { Down, Pressed, Up };

  InputManager() = default;

  sf::Vector2i getMousePosition(sf::RenderWindow &window) const;
  bool isClicked(sf::IntRect rect, sf::Mouse::Button button, sf::RenderWindow & window);

  bool getButtonUp(sf::Mouse::Button btn);
  bool getButton(sf::Mouse::Button btn);
  bool getButtonDown(sf::Mouse::Button btn);

  bool getKeyUp(sf::Keyboard::Key key);
  bool getKey(sf::Keyboard::Key key);
  bool getKeyDown(sf::Keyboard::Key key);

  void addEvent(sf::Keyboard::Key key);
  void removeEvent(sf::Keyboard::Key key);

  void addEvent(sf::Mouse::Button btn);
  void removeEvent(sf::Mouse::Button btn);

  void updateEvents();

 private:
  std::map<sf::Keyboard::Key, InputState> keys;
  std::map<sf::Mouse::Button, InputState> buttons;
};

} // namespace game