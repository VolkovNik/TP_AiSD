#include "SetGraph.hpp"

SetGraph::SetGraph(size_t verticesCount) {
  graph.resize(verticesCount);
}

SetGraph::SetGraph(const IGraph& newGraph) {
  int verticesCount = newGraph.VerticesCount();

  graph.resize(verticesCount);

  for (int i = 0; i < verticesCount; ++i) {
    for (auto vertex : newGraph.GetNextVertices(i)) {
      graph[i].insert(vertex);
    }
  }
}

// Добавление ребра от from к to.
void SetGraph::AddEdge(int from, int to) {
  graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
  return graph.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;

  for(auto child : graph[vertex]) {
    result.push_back(child);
  }

  return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
  std::vector<int> result;

  for (size_t i = 0; i < VerticesCount(); ++i) {
    for (auto child : graph[i]) {
      if (child == vertex) {
        result.push_back(i);
        break;
      }
    }
  }

  return result;
}