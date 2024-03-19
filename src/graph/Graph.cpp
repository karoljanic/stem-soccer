#include "Graph.hpp"

namespace graph {
Graph::Graph(uint32_t vertices, bool isDirected) : verticesNumber{vertices}, edgesNumber{0}, directed{isDirected} {}
} // namespace graph
