#pragma once
#include <vector>
#include <string>
#include <cmath>
// The graph data structure containing all the airports and routes in the data file
struct Airports{
	// Edges in the graph
	struct Route{
		// id of the airport that the route starts at
		int sourceAirportId;
		// id of the airport that the route ends at
	  	int destinationAirportId;
		// Euclidean distance between source and destination airports
	 	double distance;
		// Pointers to the next and previous route in the egde list
		Route * prev;
		Route * next;
	};
	// Vertices in the graph
	struct Airport{
		int id;
		std::string name;
		std::string city;
		double latitude;
		double longitude;
		// Vector of pointers to incident routes (inbound and outbound) in the edge list; adjacency list
		// A route is inbound if the current airportID is the destinationID
		// A route is outbound if the current airportID is the sourceID
		std::vector<Route*> routes;
		// Distance from starting airport (used for both algorithm)
		double distance;
		// Heuristic; distance from destination airport (set to 0 in Dijkstra)
		double heuristic;
		// 1 is already visited; 0 if not
		bool visited;
		// id of predecessor airport
		int predecessorId;
		// Default constructs an invalid airport
		Airport();
	};

	// Vector of airports; Vertex table
	// The airport id corresponds to the index in the table
	// Note that there can be empty indices if there is a missing entry in the data
	std::vector<Airport> airports;

	// Head pointer to linked list of all routes on the map; edge list
	Route * allRoutes;

	// Number of valid airports in the graph
	int numAirports;

	// Default constructor; does nothing
	Airports();

	// Custom constructor; intializes the edge list, vertex table, and adjacency list
	// @param vector of airports, vector of routes
	Airports(std::vector<Airport> ap, std::vector<Route> ro);

	// Copy constructor
	// @param other airports that you want to copy
	Airports(Airports const & other);

	// Destructor; deletes the edge list
	~Airports();

	// Creates a new pointer to a route and inserts it to the front of the linked edge list
	// @param route that is to be inserted (it must have all its variables set beside the pointers)
	void insertFront(Route ro);

	// Sets up the edge list and adjacency list
	// @param Vector of routes
	// @return nothing
	void setRoutes(std::vector<Airports::Route> ro);

	// Returns a pointer to the airport with the id in the vertex table
	// @param id of the airport
	// @return pointer to the airport if found; else NULL
	Airport* findAirport(int id);

	// Resets the distance, heuristic, visited, and predecessorId of every valid airport in the graph
	void reset();
/*
	// Helper function that uses binary search to find the airport with id
	// Can use binary search since the airport data is sorted by increasing id
	// @param left edge of subarray, right edge of subarray, id of airport
	// @return pointer to airport if found; else NULL
	Airport* _findAirport(int l, int r, int id);
*/
};
