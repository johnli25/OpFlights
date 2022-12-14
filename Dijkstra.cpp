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

void Dijkstra::runDijkstra(){
  // Initiliaze distance, heuristic, predecessorID, and visited to 0 for each airport in the graph
  
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
    airport->visited = false;
  }
  graph->findAirport(sourceAirportId)->distance = 0;
  // Build priority queue heap
  Heap queue(graph->airports); // Airports vector makes up vertices
  // Repeat until all vertices have been visited
  while (!queue.empty()){
    Graph::Airport * airport;
    Graph::Airport temp;
    // Take current min distance airport
    temp = queue.pop();
    airport = graph->findAirport(temp.id);
    airport->visited = true;
    // A route is inbound if the current airportID is the destinationID
    // A route is outbound if the current airportID is the sourceID
    for (int k = 0; k < (int)airport->routes.size(); k++){
      Graph::Route* rt = airport->routes[k];
      if (rt->sourceAirportId == airport->id){
        Graph::Airport * neighbor = graph->findAirport(rt->destinationAirportId);
        if (airport->distance + rt->distance < neighbor->distance && !neighbor->visited){
          neighbor->distance = airport->distance + rt->distance;
          neighbor->predecessorId = airport->id;
          // neighbor->heuristic = 1;
          queue.updateElem(*neighbor);
        }
      }
    }

  }

}

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
  
  // Get rid of the 0
  path.pop_back();
  // Reverse order of vector
  reverse(path.begin(),path.end());

  return path;
}

void Dijkstra::setGraph(Graph *airports){
  graph = airports;
}

void Dijkstra::setStart(int sourceId){
  sourceAirportId = sourceId;
}

Graph * Dijkstra::getGraph(){
  Graph * ptr = graph;
  return ptr;
}
