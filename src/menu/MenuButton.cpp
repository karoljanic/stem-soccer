#include "MenuButton.hpp"
#include "../game/GameData.hpp"

#include <utility>
#include <iostream>

namespace menu {
MenuButton::MenuButton(sf::Vector2f centerAnchor,
					   const std::string &textToDisplay,
					   unsigned int fontSize,
					   sf::Color fontColor,
					   const std::string &fontName,
					   float backgroundPadding,
					   sf::Color backgroundColor,
					   std::function<void()> onClickFunction) : onClick{std::move(onClickFunction)} {
  text = std::make_unique<sf::Text>();
  text->setFont(game::GameData::getInstance()->assets.getFont(fontName));
  text->setCharacterSize(fontSize);
  text->setFillColor(fontColor);
  text->setString(textToDisplay);
  text->setPosition(
	  centerAnchor - (sf::Vector2f(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2)));

  background = std::make_unique<sf::RectangleShape>(
	  sf::Vector2f(text->getGlobalBounds().width + 2 * backgroundPadding,
				   text->getGlobalBounds().height + 2 * backgroundPadding));
  background->setFillColor(backgroundColor);
  background->setPosition(
	  centerAnchor - sf::Vector2f(text->getGlobalBounds().width / 2 + backgroundPadding, backgroundPadding));
}

void MenuButton::update() {
  const auto textRect = sf::IntRect(static_cast<int>(text->getPosition().x),
									static_cast<int>(text->getPosition().y),
									static_cast<int>(text->getGlobalBounds().width),
									static_cast<int>(text->getGlobalBounds().height));

  if (game::GameData::getInstance()->inputs.isClicked(textRect,
													  sf::Mouse::Button::Left,
													  game::GameData::getInstance()->window)) {
	onClick();
	return;
  }

  const auto backgroundRect = sf::IntRect(static_cast<int>(background->getPosition().x),
										  static_cast<int>(background->getPosition().y),
										  static_cast<int>(background->getGlobalBounds().width),
										  static_cast<int>(background->getGlobalBounds().height));

  if (game::GameData::getInstance()->inputs.isClicked(backgroundRect,
													  sf::Mouse::Button::Left,
													  game::GameData::getInstance()->window)) {
	onClick();
	return;
  }
}

void MenuButton::draw() {
  game::GameData::getInstance()->window.draw(*background);
  game::GameData::getInstance()->window.draw(*text);
}

} // namespace menu
