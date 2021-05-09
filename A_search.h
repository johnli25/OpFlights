#pragma once
#include <vector>
#include <queue>
#include "Airports.h"

class A_search{
 public:
  A_search();
  A_search(Graph * airports, int sourceId);
  std::vector<int> runA_seach(int destinationAirportId);
  void setGraph(Graph * airports);
  void setStart(int sourceId);
 private:
  double distance(Airport * sourceAirport, Airport * destinationAirport);
  Graph * graph;
  int sourceAirportId;
};
//comments needed, adjusted to be consistent with dijkstra



  /*A_search(vector<Airports::Airport*> airports, Airports::Airport* source, Airports::Airport* destination);

    A_search(queue<int> weight, queue<Airports::Airport> queue, Airports::Airport current, Airports::Airport end);*/
