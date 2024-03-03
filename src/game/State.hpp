#pragma once

namespace game {
class State {
 public:
  void handleInput();
  void init();
  void pause();
  void resume();
  virtual void update(float dt) = 0;
  virtual void draw(float dt) = 0;
  virtual ~State() = default;
};
} // namespace game
