#include "Game.hpp"
#include "../config/WindowConfig.hpp"

namespace game {
Game::Game(const uint16_t width, const uint16_t height, uint16_t fps, const std::string &title) {
  dt = 1.0f / static_cast<float>(fps);
  GameData::getInstance()->window.create(sf::VideoMode(width, height), title);
}

void Game::run() {
  float newTime, frameTime;

  float currentTime = GameData::getInstance()->clock.getElapsedTime().asSeconds();
  float accumulator = 0.0f;

  while (GameData::getInstance()->window.isOpen()) {
	newTime = GameData::getInstance()->clock.getElapsedTime().asSeconds();
	frameTime = newTime - currentTime;

	if (frameTime > config::WindowConfig::MAX_FRAME_TIME) {
	  frameTime = config::WindowConfig::MAX_FRAME_TIME;
	}

	currentTime = newTime;
	accumulator += frameTime;

	while (accumulator >= dt) {
	  accumulator -= dt;
	}

  }
}
} // namespace game
