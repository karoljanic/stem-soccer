#pragma once

#include "Graph.hpp"
#include <cstdint>
#include <vector>
#include <map>

namespace graph {
class SparseGraph : public Graph {
 private:
  std::vector<std::vector<uint32_t>> adjacencyList;

 public:
  SparseGraph() = default;
  SparseGraph(uint32_t verticesNumber, bool isDirected);

  void addEdge(uint32_t source, uint32_t destination) override;
  void removeEdge(uint32_t source, uint32_t destination) override;
  std::vector<uint32_t> getNeighbors(uint32_t vertex) const override;
  bool hasEdge(uint32_t source, uint32_t destination) const override;
  uint32_t getDegree(uint32_t vertex) const override;
  uint32_t getInDegree(uint32_t vertex) const override;
  uint32_t getOutDegree(uint32_t vertex) const override;
};
} // namespace graph
