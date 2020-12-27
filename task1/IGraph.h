#ifndef TP_AISD_THIRD_MODULE_TASK1_IGRAPH_H_
#define TP_AISD_THIRD_MODULE_TASK1_IGRAPH_H_

#include <iostream>
#include <vector>

struct IGraph {
  virtual ~IGraph() {}

  // Добавление ребра от from к to.
  virtual void AddEdge(int from, int to) = 0;

  virtual int VerticesCount() const  = 0;

  virtual std::vector<int> GetNextVertices(int vertex) const = 0;
  virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif //TP_AISD_THIRD_MODULE_TASK1_IGRAPH_H_
