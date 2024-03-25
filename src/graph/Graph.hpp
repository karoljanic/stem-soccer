#pragma once

#include <vector>
#include <cstdint>

namespace graph {
class Graph {
 public:
  Graph() = default;
  Graph(uint32_t vertices, bool isDirected);
  virtual ~Graph() = default;

  inline uint32_t getVerticesNumber() const { return verticesNumber; }
  inline uint32_t getEdgesNumber() const { return edgesNumber; }

  virtual void addEdge(uint32_t source, uint32_t destination) = 0;
  virtual void removeEdge(uint32_t source, uint32_t destination) = 0;
  virtual std::vector<uint32_t> getNeighbors(uint32_t vertex) const = 0;
  virtual bool hasEdge(uint32_t source, uint32_t destination) const = 0;
  virtual uint32_t getDegree(uint32_t vertex) const = 0;
  virtual uint32_t getInDegree(uint32_t vertex) const = 0;
  virtual uint32_t getOutDegree(uint32_t vertex) const = 0;

 protected:
  uint32_t verticesNumber;
  uint32_t edgesNumber;
  bool directed;
};
} // namespace graph
