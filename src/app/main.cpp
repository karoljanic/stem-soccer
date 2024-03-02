#include "../config/WindowConfig.hpp"
#include "../football/FootballGame.hpp"

int main() {
  football::FootballGame
	  game{config::WindowConfig::WIDTH, config::WindowConfig::HEIGHT, config::WindowConfig::FPS, "Football Simulation"};
  game.run();

  return 0;
}
