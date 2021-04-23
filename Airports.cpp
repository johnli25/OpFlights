#include "Airports.h"

Airports::Airports(){
  // Nothing
}

Airports::Airports(std::vector<Airports::Airport*> ap, std::vector<Airports::Route*> ro){
  // Sets the airports
  for (unsigned i = 0; i < ap.size(); i++){
    airports.push_back(ap[i]);
  }
  processRoutes(ro);
}

Airports::Airports(Airports const & other){
  // Get other's airport
  std::vector<Airport*> ap = other.airports;
  // Sets the airports
  for (unsigned i = 0; i < ap.size(); i++){
    airports.push_back(ap[i]);
  }
  // Get other's all route vector
  std::vector<Route*> ro = other.allRoutes;
  processRoutes(ro);
}

Airports::Airport* Airports::findAirport(int id){
  // Calls recursive function
  return _findAirport(0, airports.size()-1, id);
}

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

void Airports::processRoutes(std::vector<Airports::Route*> routes){
  for (unsigned i = 0; i < routes.size(); ++i){
    // Get the current route
    Airports::Route * route = routes[i];
    // Add the route to the all routes vector
    allRoutes.push_back(route);
    // Find the source and destination airports
    Airports::Airport * sourceAirport = findAirport(route->sourceAirportId);
    Airports::Airport * destinationAirport = findAirport(route->destinationAirportId);
    // Get their coordinates
    double sourceLat = sourceAirport->latitude;
    double sourceLong = sourceAirport->longitude;
    double destinationLat = destinationAirport->latitude;
    double destinationLong = destinationAirport->longitude;
    // Calculate the euclidean distance between the two airports
    route->distance = std::sqrt(std::pow(sourceLat-destinationLat, 2) + std::pow(sourceLong-destinationLong, 2));
    // Insert the route into both airports
    sourceAirport->routes.push_back(*route);
    destinationAirport->routes.push_back(*route);
  }
}
