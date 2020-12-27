#include <iostream>
#include <vector>
#include <queue>

#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"
#include "ArcGraph.hpp"

void bfs(const IGraph& graph, void (*callback)(int v)) {
  std::vector<bool> visited;
  std::queue<int> queue;
  visited.resize(graph.VerticesCount(), false);

  for (int i = 0; i < graph.VerticesCount(); ++i) {
    if (!visited[i]) {
      queue.push(i);
      visited[i] = true;
      while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        callback(vertex);
        for (auto child : graph.GetNextVertices(vertex)) {
          if (!visited[child]) {
            queue.push(child);
            visited[child] = true;
          }
        }
      }
    }
  }
}

int main() {
  ListGraph listGraph(6);

  listGraph.AddEdge(0, 1);
  listGraph.AddEdge(1, 2);
  listGraph.AddEdge(1, 5);
  listGraph.AddEdge(2, 3);
  listGraph.AddEdge(3, 4);
  listGraph.AddEdge(4, 2);

  bfs(listGraph, [](int v) {
    std::cout << v << std::endl;
  });

  MatrixGraph matrixGraph(listGraph);

  std::cout << "----------------------" << std::endl;

  bfs(matrixGraph, [](int v) {
    std::cout << v << std::endl;
  });

  SetGraph setGraph(matrixGraph);

  std::cout << "----------------------" << std::endl;

  bfs(setGraph, [](int v) {
    std::cout << v << std::endl;
  });

  ArcGraph arcGraph(setGraph);

  std::cout << "----------------------" << std::endl;

  bfs(arcGraph, [](int v) {
    std::cout << v << std::endl;
  });

  ListGraph newListGraph(arcGraph);

  std::cout << "----------------------" << std::endl;

  bfs(newListGraph, [](int v) {
    std::cout << v << std::endl;
  });

  return 0;
}
