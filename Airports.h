#pragma once
#include <vector>
#include <string>
#include <cmath>

struct Airports{

	struct Route{
		int sourceAirportId;
	  int destinationAirportId;
		// Euclidean distance between source and destination airports
	  double distance;
	};

	struct Airport{
		int id;
		std::string name;
		std::string city;
		float latitude;
		float longitude;
		// Vector of routes that connect to this airport
		std::vector<Route> routes;
	};

	// Vector of airports
	std::vector<Airport*> airports;

	// Sets the airport of the class to the provided airport vector
	// @param pointer to a vector of pointers to airports
	// @return nothing
	void setAirports(std::vector<Airport*> * ap);
	
	// Sets the distance between the source and destination airports of the route
	// @param pointer to the route
	// @return nothing
	void calculateDistance(Route* route);

	// Returns a pointer to the airport with id
	// @param id of the airport
	// @return pointer to the airport if found; else NULL
	Airport* findAirport(int id);

	// Helper function that uses binary search to find the airport with id
	// Can use binary search since the airport data is sorted by increasing id
	// @param left edge of subarray, right edge of subarray, id of airport
	// @return pointer to airport if found; else NULL
	Airport* _findAirport(int l, int r, int id);

};
