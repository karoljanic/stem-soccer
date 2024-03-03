#include "Game.hpp"
#include "../config/WindowConfig.hpp"

namespace game {
Game::Game(uint16_t width, uint16_t height, uint16_t fps, const std::string &title) {
  dt = 1.0F / static_cast<float>(fps);
  GameData::getInstance()->window.create(sf::VideoMode(width, height), title);
}

void Game::run() {
  float newTime, frameTime, interpolation;

  float currentTime = GameData::getInstance()->clock.getElapsedTime().asSeconds();
  float accumulator = 0.0F;

  while (GameData::getInstance()->window.isOpen()) {
	GameData::getInstance()->machine.processStateChanges();
	newTime = GameData::getInstance()->clock.getElapsedTime().asSeconds();
	frameTime = newTime - currentTime;

	if (frameTime > config::WindowConfig::MAX_FRAME_TIME) {
	  frameTime = config::WindowConfig::MAX_FRAME_TIME;
	}

	currentTime = newTime;
	accumulator += frameTime;

	while (accumulator >= dt) {
	  GameData::getInstance()->machine.getActiveState()->handleInput();
	  GameData::getInstance()->machine.getActiveState()->update(dt);

	  accumulator -= dt;
	}

	interpolation = accumulator / dt;
	GameData::getInstance()->machine.getActiveState()->draw(interpolation);
  }
}
} // namespace game
