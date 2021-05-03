#include "Dijkstra.h"

Dijkstra::Dijkstra(){
  graph = NULL;
  sourceAirportId = 0;
}

Dijkstra::Dijkstra(Airports * airports, int sourceId){
  graph = airports;
  sourceAirportId = sourceId;
}

void Dijkstra::runDijkstra(){
  // reset distance, heuristic, predecessorID, and visited to 0 for each airport in the graph first
}

std::vector<int> findShortestPath(int destinationAirportId){
  std::vector<int> path;
  return path;
}

void Dijkstra::setGraph(Airports * airports){
  graph = airports;
}

void Dijkstra::setStart(int sourceId){
  sourceAirportId = sourceId;
}
