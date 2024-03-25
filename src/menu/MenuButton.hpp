#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <functional>

namespace menu {
class MenuButton {
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

 private:
  sf::Vector2f transition;
  float padding;
  std::unique_ptr<sf::RectangleShape> background;
  std::unique_ptr<sf::Text> text;
  std::function<void()> onClick;
};
} // namespace menu
