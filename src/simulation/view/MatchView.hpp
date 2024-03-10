#pragma once

#include "../model/MatchModel.hpp"
#include "StadiumView.hpp"
#include "PlayerView.hpp"
#include "BallView.hpp"
#include <memory>

namespace simulation {
class MatchView {
 private:
  std::shared_ptr<MatchModel> matchModelPtr;
  StadiumView stadiumView;
  std::vector<PlayerView> firstTeamPlayersViews;
  std::vector<PlayerView> secondTeamPlayersViews;
  BallView ballView;

 public:
  MatchView() = default;
  void init(const MatchModel &matchModel);
  void draw();
};
} // namespace simulation
