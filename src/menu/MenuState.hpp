#pragma once

#include "../game/State.hpp"
#include "MenuButton.hpp"

namespace menu {
class MenuState : public game::State {
 public:
  MenuState() = default;
  void init() override;
  void pause() override;
  void resume() override;
  void update(float dt) override;
  void draw() override;

 private:
  sf::Texture backgroundTexture;
  sf::Sprite background;
  std::vector<std::unique_ptr<MenuButton>> buttons;
};
} // namespace menu