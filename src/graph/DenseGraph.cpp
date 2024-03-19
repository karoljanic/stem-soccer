#include "DenseGraph.hpp"

namespace graph {
DenseGraph::DenseGraph(uint32_t verticesNumber, bool isDirected) : Graph{verticesNumber, isDirected},
																   adjacencyMatrix{verticesNumber,
																				   std::vector<bool>(verticesNumber,
																									 false)} {}

void DenseGraph::addEdge(uint32_t source, uint32_t destination) {
  if (directed) {
	adjacencyMatrix[source][destination] = true;
  } else {
	adjacencyMatrix[source][destination] = true;
	adjacencyMatrix[destination][source] = true;
  }

  edgesNumber++;
}

std::vector<uint32_t> DenseGraph::getNeighbors(uint32_t vertex) const {
  std::vector<uint32_t> neighbors;
  for (uint32_t i = 0; i < verticesNumber; i++) {
	if (adjacencyMatrix[vertex][i]) {
	  neighbors.push_back(i);
	}
  }

  return neighbors;
}

bool DenseGraph::hasEdge(uint32_t source, uint32_t destination) const {
  return adjacencyMatrix[source][destination];
}

uint32_t DenseGraph::getDegree(uint32_t vertex) const {
  uint32_t degree = 0;
  for (uint32_t i = 0; i < verticesNumber; i++) {
	if (adjacencyMatrix[vertex][i]) {
	  degree++;
	}

	if (adjacencyMatrix[i][vertex]) {
	  degree++;
	}
  }

  return degree;
}

uint32_t DenseGraph::getInDegree(uint32_t vertex) const {
  uint32_t inDegree = 0;
  for (uint32_t i = 0; i < verticesNumber; i++) {
	if (adjacencyMatrix[i][vertex]) {
	  inDegree++;
	}
  }

  return inDegree;
}

uint32_t DenseGraph::getOutDegree(uint32_t vertex) const {
  uint32_t outDegree = 0;
  for (uint32_t i = 0; i < verticesNumber; i++) {
	if (adjacencyMatrix[vertex][i]) {
	  outDegree++;
	}
  }

  return outDegree;
}

} // namespace graph
