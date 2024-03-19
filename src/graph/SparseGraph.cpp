#include "SparseGraph.hpp"
#include <algorithm>

namespace graph {
SparseGraph::SparseGraph(uint32_t verticesNumber, bool isDirected) : Graph{verticesNumber, isDirected},
																	 adjacencyList{verticesNumber} {}

void SparseGraph::addEdge(uint32_t source, uint32_t destination) {
  if (directed) {
	adjacencyList[source].push_back(destination);
  } else {
	adjacencyList[source].push_back(destination);
	adjacencyList[destination].push_back(source);
  }

  edgesNumber++;
}

std::vector<uint32_t> SparseGraph::getNeighbors(uint32_t vertex) const {
  return adjacencyList[vertex];
}

bool SparseGraph::hasEdge(uint32_t source, uint32_t destination) const {
  return std::any_of(adjacencyList[source].begin(), adjacencyList[source].end(), [destination](uint32_t neighbor) {
	return neighbor == destination;
  });
}

uint32_t SparseGraph::getDegree(uint32_t vertex) const {
  return getInDegree(vertex) + getOutDegree(vertex);
}

uint32_t SparseGraph::getInDegree(uint32_t vertex) const {
  uint32_t inDegree = 0;
  for (uint32_t i = 0; i < verticesNumber; i++) {
	if (hasEdge(i, vertex)) {
	  inDegree++;
	}
  }

  return inDegree;
}

uint32_t SparseGraph::getOutDegree(uint32_t vertex) const {
  return adjacencyList[vertex].size();
}
} // namespace graph
