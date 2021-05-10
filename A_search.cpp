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
  // Heap queue = Heap();
  // //technically not a standard queue but functioning as a priority queue
  // Graph::Airport * end = graph->findAirport(destinationAirportId);
  // Graph::Airport * curr = graph->findAirport(sourceAirportId);
  // curr->heuristic = distance(curr, end);
  // curr->distance = 0;
  // bool helper = true;
  // while(helper){
  //   //std::cout << "Curr=" << curr->id << std::endl;
  // //while curr is not destination
  //   for(size_t i = 0; i < curr->routes.size(); i++){ 
  //   //traverse through each route
  //     int next_id = curr->routes[i]->destinationAirportId;
  //     Graph::Airport * nextAirport = graph->findAirport(next_id);
  //     if(curr->id != next_id){
	// //std::cout << next_id << std::endl;
	//       if(!nextAirport->visited){
	//   //if vertex is avaliable
  //         Graph::Airport * temp = nextAirport;
  //         temp->heuristic = distance(nextAirport, end);
  //         temp->distance = curr->distance + curr->routes[i]->distance;
  //         temp->predecessorId = curr->id;
  //         if(queue.exists(*nextAirport).id != 0){
  //           //if vertex already exists in queue
  //           Graph::Airport compare = queue.exists(*nextAirport);
  //           if((compare.distance + compare.heuristic) > (temp->distance + temp->heuristic)){
  //             //if new f value is lower, update 
  //             nextAirport->heuristic = temp->heuristic;
  //             nextAirport->distance = temp->distance;
  //             nextAirport->predecessorId = temp->predecessorId;
  //             queue.updateElem(*nextAirport);
  //           }
  //         } else {
  //           //push since its not in queue
  //           nextAirport->heuristic = temp->heuristic;
  //           nextAirport->distance = temp->distance;
  //           nextAirport->predecessorId = temp->predecessorId;
  //           queue.push(*nextAirport);
  //         }
  //         if(nextAirport->id == destinationAirportId){
  //           //break if weve reached the end of traversal
  //           helper = false;
  //         }
  //       }	    
  //     }
  //   }
  //   curr->visited = true;
  //   if(queue.empty()){
  //     return std::vector<int>();
  //   }
  //   curr = graph->findAirport(queue.peek().id);
  //   queue.pop();
  //   //std::cout << std::endl;
  // }
  // std::vector<int> traversal;
  // if(curr->id != destinationAirportId){
  //   traversal.insert(traversal.begin(), destinationAirportId);
  // }
  // Graph::Airport * traversalHelper = curr;
  // while(traversalHelper->id != sourceAirportId){
  //   traversal.insert(traversal.begin(), traversalHelper->id);
  //   //insert traversal data backwards
  //   traversalHelper = graph->findAirport(traversalHelper->predecessorId);
  // }
  // traversal.insert(traversal.begin(), sourceAirportId);
  // return traversal;
  /*Katrina's runDijkstra*/
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

  //Katrina's findShortestPath
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
















/*
A_search(std::vector<Airport*> airports, Airport* source, Airport* destination){
  queue<int> weight;
  return A_search(weight, airports, start, end);
}


//queue will hold the order
//weight should be pushed and popped at the same time
//and will hold weight/cost of an airport

A_search(queue<int> weight, queue<Airport> queue, Airport* curr, Airport* end){ //recursive
  int cost = 0;//edge length + distance to goal
  for(unsigned long i = 0; i < curr->routes.size(); i++){
    airport* currRoute = findAirport(curr.routes[i].destinationAirportId);
    // Get their coordinates, taken from calculateDistance
    double currLat = currAirport->latitude;
    double currLong = currAirport->longitude;
    double endLat = end->latitude;
    double endLong = end->longitude;
    // Calculate the euclidean distance between the two airports
    int heuristic = distance = std::sqrt(std::pow(currLat-endLat, 2) + std::pow(currLong-endLong, 2));
    cost = start.routes[i].distance + heuristic;
    //not sure how pushing works yet so if...? ...cost >=...
    //then push to airport to queue and push cost to weight
  }
}
*/
