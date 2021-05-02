#include "Airports.h"

Airports::Airports(){
  // Nothing
}

Airports::Airports(std::vector<Airports::Airport> ap, std::vector<Airports::Route> ro){
  // Resize the vertex table to the id of the last airport (since the data is in sorted order)
  airports.resize(ap.back().id+1);

  // Puts each airport in the vertex table, with the index corresponding to its id
  for (unsigned i = 0; i < ap.size(); i++){
    airports[ap[i].id] = ap[i];
  }
  // Edge list currently empty
  allRoutes = NULL;
  setRoutes(ro);
}

Airports::Airports(Airports const & other){
  // Get other's airport
  std::vector<Airport> ap = other.airports;
  // Resize the airport vector
  airports.resize(ap.size());
  // Sets the airports
  for (Airport airport : ap){
    // Valid id's start at 1; 0 means uninitialized airport so not valid
    if (airport.id != 0){
      airports[airport.id] = airport;
      // Need to clear the adjacency list
      airports[airport.id].routes.clear();
    }
  }
  // Clear the current edge list since it should be empty
  allRoutes = NULL;
  // Get other's edge list
  Route * ro = other.allRoutes;
  // Convert the edge list to a vector
  std::vector<Airports::Route> route;
  while (ro != NULL){
    route.push_back(*ro);
    ro = ro->next;
  }
  std::reverse(route.begin(), route.end());
  setRoutes(route);
}

Airports::~Airports(){
  // If there are edges in the edge list
  if (allRoutes != NULL){
    // Get the head pointer to the edge list
    Airports::Route * cur = allRoutes;
    // While not at the end of the list
    while (cur != NULL){
      // Get the next node in the list
      Airports::Route * next = cur->next;
      // Delete the current node
      delete cur;
      // Move to the next node
      cur = next;
    }
  }
}

Airports::Airport* Airports::findAirport(int id){
  // Returns a pointer to the airport at the index of the id
  return &airports[id];
  // Calls recursive function
  //return _findAirport(0, airports.size()-1, id);
}

/*
Airports::Airport* Airports::_findAirport(int l, int r, int id){
  if (r >= 0){
    int mid = (l + r)/2;
    // If the airport is at the middle, return pointer to the airport
    if (airports[mid]->id == id){
      return airports[mid];
    }
    // If the id of the middle airport is larger, search left subarray
    if (airports[mid]->id > id){
      return _findAirport(l, mid-1, id);
    }
    // Else the id of the middle airport is smaller, search right subarray
    return _findAirport(mid+1, r, id);
  }
  // The airport is not present
  return NULL;
}
*/

void Airports::insertFront(Route ro){
  // Make a new linked list node corresponding to the route
  Airports::Route * route = new Airports::Route;
  // Initialize its values
  route->sourceAirportId = ro.sourceAirportId;
  route->destinationAirportId = ro.destinationAirportId;
  route->distance = ro.distance;
  route->prev = NULL;
  // If there is a node already
  if (allRoutes != NULL){
    // Get the current head pointer to the edge list
    Airports::Route * temp = allRoutes;
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

void Airports::setRoutes(std::vector<Airports::Route> ro){
  for (unsigned i = 0; i < ro.size(); i++){
    // Get the current route
    Airports::Route cur = ro[i];
    // Find the source and destination airports
    Airports::Airport * sourceAirport = findAirport(cur.sourceAirportId);
    Airports::Airport * destinationAirport = findAirport(cur.destinationAirportId);
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
