#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(size_t verticesCount) {
  graph.resize(verticesCount);
  for (int i = 0; i < verticesCount; ++i) {
    graph[i].resize(verticesCount, 0);
  }
}

MatrixGraph::MatrixGraph(const IGraph& newGraph) {
  int verticesCount = newGraph.VerticesCount();

  graph.resize(verticesCount);
  for (int i = 0; i < verticesCount; ++i) {
    graph[i].resize(verticesCount, 0);
  }

  for (int i = 0; i < verticesCount; ++i) {
    for (auto vertex : newGraph.GetNextVertices(i)) {
      graph[i][vertex]++;
    }
  }

}

void MatrixGraph::AddEdge(int from, int to) {
  graph[from][to]++;
}

int MatrixGraph::VerticesCount() const {
  return graph.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;

  for (int i = 0; i < VerticesCount(); ++i) {
    for (int j = 0; j < graph[vertex][i]; ++j) {
      result.push_back(i);
    }
  }

  return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;

  for (int i = 0; i < VerticesCount(); ++i) {
    for (int j = 0; j < graph[i][vertex]; ++j) {
      result.push_back(i);
    }
  }

  return result;
}