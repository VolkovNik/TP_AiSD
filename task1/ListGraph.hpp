#ifndef TP_AISD_THIRD_MODULE_TASK1_LISTGRAPH_HPP_
#define TP_AISD_THIRD_MODULE_TASK1_LISTGRAPH_HPP_

#include <iostream>
#include <vector>

#include "IGraph.h"

class ListGraph : public IGraph {
 public:

  ListGraph(size_t verticesCount);

  ListGraph(const IGraph&);

  virtual ~ListGraph() {}

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;

  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::vector<int>> graph;
};

#endif //TP_AISD_THIRD_MODULE_TASK1_LISTGRAPH_HPP_
