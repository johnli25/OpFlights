#include "Airports.h"

Airports::Airport* Airports::findAirport(int id){
  // Calls recursive function
  return _findAirport(0, airports.size(), id);
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

void Airports::setAirports(std::vector<Airports::Airport*>* ap){
  // Goes through every airport and adds it to the class vector
  for (unsigned i = 0; i < ap->size(); i++){
    airports.push_back(ap->at(i));
  }
}

void Airports::calculateDistance(Route* route){
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
  // for (size_t i = 0; i < ; i++){
  //   routes.push_back();
  // }
  sourceAirport->routes.push_back(* route);
  destinationAirport->routes.push_back(* route);
}


