#include "../simulation/FootballGame.hpp"

int main() {
  std::unique_ptr<game::Game> game = std::make_unique<simulation::FootballGame>();
  game->run();

  return 0;
}
