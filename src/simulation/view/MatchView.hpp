#pragma once

#include "../model/MatchModel.hpp"
#include "StadiumViewDrawer.hpp"
#include "PlayerViewDrawer.hpp"
#include "BallViewDrawer.hpp"
#include <memory>

namespace simulation {
class MatchView {
 private:
  MatchModel* matchModelPtr;
  sf::Vector3f worldOrigin;
  StadiumViewDrawer stadiumViewDrawer;
  PlayerViewDrawer playerViewDrawer;
  BallViewDrawer ballViewDrawer;

 public:
  MatchView() = default;
  void init(MatchModel* matchModel, const sf::Vector3f &origin);
  void draw();
};
} // namespace simulation
