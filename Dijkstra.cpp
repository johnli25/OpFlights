#include "Dijkstra.h"

Dijkstra::Dijkstra(){
  graph = NULL;
  sourceAirportId = 0;
}

Dijkstra::Dijkstra(Graph * airports, int sourceId){
  graph = airports;
  sourceAirportId = sourceId;
  // Resets the graph
  graph->reset();
}

// work on this
void Dijkstra::runDijkstra(){
  // reset distance, heuristic, predecessorID, and visited to 0 for each airport in the graph first
}

// work on this
std::vector<int> findShortestPath(int destinationAirportId){
  std::vector<int> path;
  return path;
}

void Dijkstra::setGraph(Graph *airports){
  graph = airports;
}

void Dijkstra::setStart(int sourceId){
  sourceAirportId = sourceId;
}
