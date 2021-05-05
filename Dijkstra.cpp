#include "Dijkstra.h"
#include "Heap.h"
#include <cfloat>

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
  // use graph as input to dijkstras 
  // invalid airports have ID of 0
  // figure out which are incoming vs outgoing
  // When setting the distance to infinity, use `DBL_MAX` from `#include <cfloat>`
  // line 20 --- to update distance: must get airport first, update distance 1st, pass in to update elem in heap: updateElem(airport)
  // A route is inbound if the current airportID is the destinationID
  // A route is outbound if the current airportID is the sourceID
  

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
