#include "A_search.h"

//https://www.youtube.com/watch?v=ySN5Wnu88nE - this ones really good
//https://www.youtube.com/watch?v=6TsL96NAZCo


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
