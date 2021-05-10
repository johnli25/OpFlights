#pragma once
#include <vector>
#include <queue>
#include "Airports.h"

class A_search{
 public:
  A_search();
  A_search(Graph * ariports, int sourceId);
  void runA_seach();
  std::vector<int> findShortestPath(int destinationAirportId);
  void setGraph(Graph * airports);
  void setStart(int sourceId);
 private:
  Graph * graph;
  int sourceAirportId;
};
//comments needed, adjusted to be consistent with dijkstra



  /*A_search(vector<Airports::Airport*> airports, Airports::Airport* source, Airports::Airport* destination);

    A_search(queue<int> weight, queue<Airports::Airport> queue, Airports::Airport current, Airports::Airport end);*/
