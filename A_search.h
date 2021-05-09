#pragma once
#include <vector>
#include <queue>
#include "Graph.h"
#include "Heap.h"

class A_search{
 public:
  A_search();
  A_search(Graph * airports, int sourceId);
<<<<<<< HEAD
  std::vector<int> runA_search(int destinationAirportId);
=======
  std::vector<int> runA_seach(int destinationAirportId);
>>>>>>> 4c2a9e5cc2f4a14b0623407fd46ec58d5fae9970
  void setGraph(Graph * airports);
  void setStart(int sourceId);
 private:
  double distance(Graph::Airport * sourceAirport, Graph::Airport * destinationAirport);
  Graph * graph;
  int sourceAirportId;
};
//comments needed, adjusted to be consistent with dijkstra



  /*A_search(vector<Airports::Airport*> airports, Airports::Airport* source, Airports::Airport* destination);

    A_search(queue<int> weight, queue<Airports::Airport> queue, Airports::Airport current, Airports::Airport end);*/
