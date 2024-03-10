#include "MatchView.hpp"

namespace simulation {
void MatchView::init(const MatchModel &matchModel) {
  matchModelPtr = std::make_shared<MatchModel>(matchModel);
}
void MatchView::draw() {}
} // namespace simulation
