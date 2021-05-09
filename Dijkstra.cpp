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
  // line 20 --- to update distance: must get airport first, update distance 1st, pass in to update elem in heap: updateElem(airport)

  //initialize predecessors and distances
  int num_airports = graph->airports.size();
  //foreach (Vertex v: G)
  Graph::Airport * airport;
  for (int i = 0; i < num_airports; i++){
    if (graph->findAirport(i) == NULL){
      continue;
    }
    airport = graph->findAirport(i);
    airport->distance = DBL_MAX;
    airport->predecessorId = 0;
    airport->heuristic = 0;
  }
  graph->findAirport(sourceAirportId)->distance = 0;
  // Build priority queue heap
  Heap queue(graph->airports); // Airports vector makes up vertices
  // Repeat until all vertices have been visited
  for (int i = 0; i < num_airports; i++){
    Graph::Airport airport;
    // Take current min distance airport
    airport = queue.pop();
    // invalid airports have ID of 0!!!
    if (airport.id == 0){
      continue;
    }
    // Examine neighbors: Any edge leaving the airport leads to a neighbor
    for (int j = 0; j < num_airports; j++){
      Graph::Airport * neighbor = graph->findAirport(j);
      if (i == j || neighbor->id == 0){
        continue;
      }
      // A route is inbound if the current airportID is the destinationID
      // A route is outbound if the current airportID is the sourceID
      //for (rt = airport.routes.begin(); rt < airport.routes.end(); rt++){
      for (int k = 0; k < (int)airport.routes.size(); k++){
        Graph::Route* rt = airport.routes[k];
        if (rt->destinationAirportId == j){
          if (airport.distance + rt->distance < neighbor->distance){
            neighbor->distance = airport.distance + rt->distance;
            neighbor->predecessorId = i;
            neighbor->heuristic = 1;
            queue.updateElem(*neighbor);
          }
        }
      }
    }
  }
}

// work on this
std::vector<int> Dijkstra::findShortestPath(int destinationAirportId){
  std::vector<int> path;
  path.push_back(destinationAirportId);
  Graph::Airport * curr_airport = graph->findAirport(destinationAirportId);
  // find path using predecessor
  while (curr_airport != NULL){
    int pred = curr_airport->predecessorId;
    curr_airport = graph->findAirport(pred);
    path.push_back(pred);
  }
  //reverse order of vector
  std::reverse(path.begin(),path.end());
  
  return path;
}

void Dijkstra::setGraph(Graph *airports){
  graph = airports;
}

void Dijkstra::setStart(int sourceId){
  sourceAirportId = sourceId;
}
