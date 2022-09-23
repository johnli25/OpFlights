#include "A_search.h"
#include <iostream>
#include <cfloat>

//https://www.youtube.com/watch?v=ySN5Wnu88nE - this ones really good
//https://www.youtube.com/watch?v=6TsL96NAZCo

A_search::A_search(){
  graph = NULL;
  sourceAirportId = 0;
}

A_search::A_search(Graph * airports, int sourceId){
  graph = airports;
  sourceAirportId = sourceId;
  graph->reset();
}

std::vector<int> A_search::runA_search(int destinationAirportId){
  int num_airports = graph->airports.size();
  //foreach (Vertex v: G)
  Graph::Airport * airport;
//  Graph::Airport * destinationAirportTemp; //internal copy variable
  for (int i = 0; i < num_airports; i++){
    if (graph->findAirport(i) == NULL){
      continue;
    }
    airport = graph->findAirport(i);
    airport->distance = DBL_MAX;
    airport->predecessorId = 0;
    airport->heuristic = distance(airport, graph->findAirport(destinationAirportId));
    airport->visited = false;
  }
  graph->findAirport(sourceAirportId)->distance = 0;
  // Build priority queue heap
  Heap queue(graph->airports); // Airports vector makes up vertices
  // Repeat until all vertices have been visited
  bool helper = true;
  while (!queue.empty() && helper){
    Graph::Airport * airport;
    Graph::Airport temp;
    // Take current min distance airport
    temp = queue.pop();
    airport = graph->findAirport(temp.id);
    airport->visited = true;
    // End it if popped off the destination from the heap
    if (airport->id == destinationAirportId){
      break;
    }
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
  path.pop_back();
  reverse(path.begin(),path.end());
  return path;
}

double A_search::distance(Graph::Airport * sourceAirport, Graph::Airport * destinationAirport){
  if ((sourceAirport->id != 0) && (destinationAirport->id != 0)){
    // Get their coordinates
    double sourceLat = sourceAirport->latitude;
    double sourceLong = sourceAirport->longitude;
    double destinationLat = destinationAirport->latitude;
    double destinationLong = destinationAirport->longitude;
    //return distance
    return std::sqrt(std::pow(sourceLat-destinationLat, 2) + std::pow(sourceLong-destinationLong, 2));
  }
  //shouldn't ever be called
  else return DBL_MAX;
}


void A_search::setGraph(Graph * airports){
  graph = airports;
}

void A_search::setStart(int sourceId){
  sourceAirportId = sourceId;
}

Graph * A_search::getGraph(){
  Graph * ptr = graph;
  return ptr;
}
