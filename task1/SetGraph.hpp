#ifndef TP_AISD_THIRD_MODULE_TASK1_SETGRAPH_HPP_
#define TP_AISD_THIRD_MODULE_TASK1_SETGRAPH_HPP_

#include <iostream>
#include <set>

#include "IGraph.h"

class SetGraph : public IGraph {
 public:

  SetGraph(size_t verticesCount);

  SetGraph(const IGraph&);

  virtual ~SetGraph() {}

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;

  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::multiset<int>> graph;
};

#endif //TP_AISD_THIRD_MODULE_TASK1_SETGRAPH_HPP_
