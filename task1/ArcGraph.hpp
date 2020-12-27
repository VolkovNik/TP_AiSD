#ifndef TP_AISD_THIRD_MODULE_TASK1_ARCGRAPH_HPP_
#define TP_AISD_THIRD_MODULE_TASK1_ARCGRAPH_HPP_

#include <iostream>

#include "IGraph.h"

class ArcGraph : public IGraph {
 public:

  ArcGraph(size_t verticesCount);

  ArcGraph(const IGraph&);

  virtual ~ArcGraph() {}

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;

  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::pair<int, int>> graph;
  int size = 0;
};

#endif //TP_AISD_THIRD_MODULE_TASK1_ARCGRAPH_HPP_
