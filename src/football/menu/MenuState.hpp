#pragma once

#include "../../game/State.hpp"
#include "../../game/GameData.hpp"
#include "../../config/AssetsConfig.hpp"
#include "../../config/WindowConfig.hpp"
#include "MenuButton.hpp"

namespace football {
class MenuState : public game::State {
 private:
  sf::Texture backgroundTexture;
  sf::Sprite background;
  std::vector<std::unique_ptr<MenuButton>> buttons;

 public:
  MenuState() = default;
  void init() override;
  void pause() override;
  void resume() override;
  void update(float dt) override;
  void draw(float dt) override;
};
} // namespace football