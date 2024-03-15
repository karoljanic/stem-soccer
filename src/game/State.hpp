#pragma once

namespace game {
class State {
 public:
  State() = default;
  void handleInput();
  virtual void init() = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual void update(float dt) = 0;
  virtual void draw() = 0;
  virtual ~State() = default;
};
} // namespace game
