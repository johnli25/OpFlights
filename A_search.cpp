#include "A_search.h"

//https://www.youtube.com/watch?v=ySN5Wnu88nE - this ones really good
//https://www.youtube.com/watch?v=6TsL96NAZCo

A_seach::A_search(){
  graph = NULL;
  sourceAirportId = 0;
}

A_search::A_search(Graph * airports, int sourceId){
  graph = airports;
  sourceAirportId = sourceId;
  graph->reset();
}

std::vector<int> A_search::runA_search(int destinationAirportId){
  Heap queue = Heap();
  //technically not a standard queue but functioning as a priority queue
  Airport * end = findAirport(destinationAirportId);
  Airport * curr = findAirport(SourceId);
  curr->heuristic = distance(curr, end);
  curr->distance = 0;
  while(curr->id != destinationAirportId){
    for(size_t i = 0; i < curr->routes.size(); i++){
      int next_id = curr->routes[i]->destinationAirportId;
      Graph::Airport * nextAirport = graph->findAirport(next_id);
      if(!nextAirport->visited){
	Graph::Airport * temp = nextAirport;
        temp->heuristic = distance(nextAirport, end);
        temp->distance = curr->distance + curr->routes[i].distance
	temp->predecessorId = curr->id;
	if(queue.exists(nextAirport)){
	  Graph::Airport compare = queue.exists(nextAirport);
	  if(compare.distance + compare.heuristic > temp->distance + temp->heurisitc){
	    nextAirport = temp;
	    queue.updateElem(nextAirport);
	  }
	}
	else{
	  nextAirport = temp;
	  queue.push(nextAirport);
	}	    
      }
    }
    curr->visited = true;
    curr = queue.pop();
  }
  vector<int> traversal;
  Airport * traversalHelper = curr;
  while(traversalHelper->id != sourceId){
    traversal.insert(traversal.begin(), traversalHelper->id);
    //insert traversal data backwards
    traversalHelper = findAirport(traversalHelper->predecessorId);
  }
  traversal.insert(traversal.begin(), sourceId);
  return traversal;
}

double A_search::distance(Airport * sourceAirport, Airport * destinationAirport){
  if ((sourceAirport != NULL) && (destinationAirport != NULL)){
    // Get their coordinates
    double sourceLat = sourceAirport->latitude;
    double sourceLong = sourceAirport->longitude;
    double destinationLat = destinationAirport->latitude;
    double destinationLong = destinationAirport->longitude;
    //return distance
    return std::sqrt(std::pow(sourceLat-destinationLat, 2) + std::pow(sourceLong-destinationLong, 2));
  }
  //shouldn't ever be called
  else return Airport();
}


void A_seach::setGraph(Graph * airports){
  graph = airports;
}

void A_search::setStart(int sourceId){
  sourceAirportId = sourceID;
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
