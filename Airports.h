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

	// Default constructor; does nothing
	Airports();

	// Custom constructor; intializes the airports and allRoutes vector; sets up the routes
	// @param vector of airports, vector of routes
	Airports(std::vector<Airport*> ap, std::vector<Route*> routes);

	// Copy constructor
	// @param other airports that you want to copy
	Airports(Airports const & other);

	// Vector of airports
	std::vector<Airport*> airports;

	// Vector of all routes on the map
	std::vector<Route*> allRoutes;

	// Sets the distance between the source and destination airports of each route
	// Also assigns each route to their airports
	// @param Vector of routes
	// @return nothing
	void processRoutes(std::vector<Airports::Route*> routes);

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
