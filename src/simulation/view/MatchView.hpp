#pragma once

#include "../model/MatchModel.hpp"
#include "StadiumViewDrawer.hpp"
#include "PlayerViewDrawer.hpp"
#include "BallViewDrawer.hpp"
#include <memory>

namespace simulation {
class MatchView {
 public:
  MatchView() = default;
  void init(MatchModel* matchModel);
  void draw();

 private:
  MatchModel* matchModelPtr;
  StadiumViewDrawer stadiumViewDrawer;
  PlayerViewDrawer playerViewDrawer;
  BallViewDrawer ballViewDrawer;
};
} // namespace simulation
