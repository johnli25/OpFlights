#include "Graph.h"

Graph::Graph(){
  allRoutes = NULL;
  airports.clear();
  numAirports = 0;
}

Graph::Graph(std::vector<Graph::Airport> ap, std::vector<Graph::Route> ro){
  // Resize the vertex table to the id of the last airport (since the data is in sorted order)
  airports.resize(ap.back().id+1);
  numAirports = 0;
  // Puts each airport in the vertex table, with the index corresponding to its id
  for (unsigned i = 0; i < ap.size(); i++){
    airports[ap[i].id] = ap[i];
    // Initialize the distance and heuristic to 0
    airports[ap[i].id].distance = 0;
    airports[ap[i].id].heuristic = 0;
    airports[ap[i].id].visited = 0;
    airports[ap[i].id].predecessorId = 0;
    numAirports++;
  }
  // Edge list currently empty
  allRoutes = NULL;
  setRoutes(ro);
}

Graph::Graph(Graph const & other){
  // Get other's airport
  std::vector<Airport> ap = other.airports;
  // Resize the airport vector
  airports.resize(ap.size());
  numAirports = other.numAirports;
  // Sets the airports
  for (Airport airport : ap){
    // Valid id's start at 1; 0 means uninitialized airport so not valid
    if (airport.id != 0){
      airports[airport.id] = airport;
      // Need to clear the adjacency list
      airports[airport.id].routes.clear();
      // Copy the distance and heuristic
      airports[airport.id].distance = airport.distance;
      airports[airport.id].heuristic = airport.heuristic;
      airports[airport.id].visited = airport.visited;
      airports[airport.id].predecessorId = airport.predecessorId;
    }
  }
  // Clear the current edge list since it should be empty
  allRoutes = NULL;
  // Get other's edge list
  Route * ro = other.allRoutes;
  // Convert the edge list to a vector
  std::vector<Graph::Route> route;
  while (ro != NULL){
    route.push_back(*ro);
    ro = ro->next;
  }
  setRoutes(route);
}

Graph::~Graph(){
  // If there are edges in the edge list
  if (allRoutes != NULL){
    // Get the head pointer to the edge list
    Graph::Route * cur = allRoutes;
    // While not at the end of the list
    while (cur != NULL){
      // Get the next node in the list
      Graph::Route * next = cur->next;
      // Delete the current node
      delete cur;
      // Move to the next node
      cur = next;
    }
  }
}

Graph::Airport::Airport(){
  id = 0;
  latitude = 0;
  longitude = 0;
  routes.clear();
  distance = 0;
  heuristic = 0;
  visited = 0;
  predecessorId = 0;
}

Graph::Airport* Graph::findAirport(int id){
  // Returns a pointer to the airport at the index of the id
  return &airports[id];
}

void Graph::insertFront(Route ro){
  // Make a new linked list node corresponding to the route
  Graph::Route * route = new Graph::Route;
  // Initialize its values
  route->sourceAirportId = ro.sourceAirportId;
  route->destinationAirportId = ro.destinationAirportId;
  route->distance = ro.distance;
  route->prev = NULL;
  // If there is a node already
  if (allRoutes != NULL){
    // Get the current head pointer to the edge list
    Graph::Route * temp = allRoutes;
    // Make the current route the new head
    allRoutes = route;
    // Make the new head point to the previous head
    route->next = temp;
    // Make the previous head point back to the new head
    temp->prev = route;
  }else{
    // There is no node in the edge list currently
    // Make the current route the new head
    allRoutes = route;
    // It points to nothing
    route->next = NULL;
  }
}

void Graph::setRoutes(std::vector<Graph::Route> ro){
  // Reverse the order of the routes since it inserts at the front of the edge list
  // Want the edge list to be in the same order as the route data
  std::reverse(ro.begin(), ro.end());
  for (unsigned i = 0; i < ro.size(); i++){
    // Get the current route
    Graph::Route cur = ro[i];
    // Find the source and destination airports
    Graph::Airport * sourceAirport = findAirport(cur.sourceAirportId);
    Graph::Airport * destinationAirport = findAirport(cur.destinationAirportId);
    // Get their coordinates
    double sourceLat = sourceAirport->latitude;
    double sourceLong = sourceAirport->longitude;
    double destinationLat = destinationAirport->latitude;
    double destinationLong = destinationAirport->longitude;
    // Calculate the euclidean distance between the two airports
    cur.distance = std::sqrt(std::pow(sourceLat-destinationLat, 2) + std::pow(sourceLong-destinationLong, 2));
    // Add the route to the front of the edge list
    insertFront(cur);
    // Insert a pointer to the route into both airports (it is the head of the edge list)
    sourceAirport->routes.push_back(allRoutes);
    destinationAirport->routes.push_back(allRoutes);
  }
}

void Graph::reset(){
  for (unsigned i = 0; i < airports.size(); i++){
    // If the airport is valid
    if (airports[i].id != 0){
      // Reset its variables
      airports[i].distance = 0;
      airports[i].heuristic = 0;
      airports[i].visited = 0;
      airports[i].predecessorId = 0;
    }
  }
}
