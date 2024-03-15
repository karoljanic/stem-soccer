#include "MenuState.hpp"
#include "../game/GameData.hpp"
#include "../simulation/SimulationState.hpp"
#include "../config/AssetsConfig.hpp"
#include "../config/WindowConfig.hpp"

namespace menu {
void MenuState::init() {
  game::GameData::getInstance()->assets.loadTexture(config::AssetsConfig::MENU_BACKGROUND_TEXTURE, "menu_background");
  game::GameData::getInstance()->assets.loadFont(config::AssetsConfig::THIN_FONT, "thin_font");

  backgroundTexture = game::GameData::getInstance()->assets.getTexture("menu_background");
  background.setTexture(backgroundTexture);

  const float centerX = static_cast<float>(game::GameData::getInstance()->window.getSize().x) / 2;
  const float centerY = static_cast<float>(game::GameData::getInstance()->window.getSize().y) / 2;

  buttons.push_back(std::make_unique<MenuButton>(sf::Vector2f(centerX, centerY),
												 "Run Simulation",
												 config::WindowConfig::MEDIUM_FONT_SIZE,
												 sf::Color::White,
												 "thin_font",
												 static_cast<float>(config::WindowConfig::MEDIUM_FONT_SIZE) / 2,
												 sf::Color::Black,
												 []() {
												   game::GameData::getInstance()->machine.addState(std::make_unique<
													   simulation::SimulationState>());
												 }));
}

void MenuState::pause() {}

void MenuState::resume() {}

void MenuState::update(float /*dt*/) {
  for (const auto &button : buttons) {
	button->update();
  }
}

void MenuState::draw() {
  game::GameData::getInstance()->window.clear();
  game::GameData::getInstance()->window.draw(background);
  for (const auto &button : buttons) {
	button->draw();
  }
  game::GameData::getInstance()->window.display();
}
} // namespace menu
