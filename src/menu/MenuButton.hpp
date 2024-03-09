#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <functional>

namespace menu {
class MenuButton {
 private:
  std::unique_ptr<sf::RectangleShape> background;
  std::unique_ptr<sf::Text> text;
  std::function<void()> onClick;

 public:
  MenuButton(sf::Vector2f centerAnchor,
			 const std::string &textToDisplay,
			 unsigned int fontSize,
			 sf::Color fontColor,
			 const std::string &fontName,
			 float backgroundPadding,
			 sf::Color backgroundColor,
			 std::function<void()> onClickFunction);

  void update();
  void draw();
};
} // namespace menu
