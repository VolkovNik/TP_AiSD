#include "ArcGraph.hpp"

ArcGraph::ArcGraph(size_t verticesCount) {
  size = verticesCount;
}

ArcGraph::ArcGraph(const IGraph& newGraph) {
  int verticesCount = newGraph.VerticesCount();

  size = verticesCount;

  for (int i = 0; i < verticesCount; ++i) {
    for (auto child : newGraph.GetNextVertices(i)) {
      graph.push_back(std::make_pair(i, child));
    }
  }
}

// Добавление ребра от from к to.
void ArcGraph::AddEdge(int from, int to) {
  graph.push_back(std::make_pair(from, to));
}

int ArcGraph::VerticesCount() const {
  return size;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;

  for (auto vertexPair : graph) {
    if (vertexPair.first == vertex) {
      result.push_back(vertexPair.second);
    }
  }

  return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;

  for (auto vertexPair : graph) {
    if (vertexPair.second == vertex) {
      result.push_back(vertexPair.first);
    }
  }

  return result;
}