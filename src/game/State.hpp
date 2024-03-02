#pragma once

namespace game {
class State {
 public:
  void handleInput();
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual ~State() = default;
};
} // namespace game
