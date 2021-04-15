#pragma once
#include <string>
#include "Airport.h"
#include "Route.h"

// Determines if the string is a valid airport, meaning it contains
// every entry of data.
// @param str A string containing a line from the airports.dat file
// @return true if it is a valid airport
bool isValidAirport(const std::string str);

// Goes through the string containing a valid airport and intializes the corresponding member variables.
// @param str A string containing data for a valid airport
// @return a pointer to an airport
Airport * processAirport(const std::string str);

// Determines if the string is a valid route, meaning it contains every entry
// of data.
// @param str A string containing a line from the routes.dat file
// @return true if it is a valid route
bool isValidRoute(const std::string str);

// Goes through the string containing a valid route and intializes the corresponding member variables.
// @param str A string containing data for a valid route
// @return a pointer to a route
Route * processRoute(const std::string str);

// Reads an airport file
// @param filename The file to read from
// @return a vector containing airports
std::vector<Airport*> file_to_Airport(const std::string & filename);

// Reads a route file
// @param filename The file to read from
// @return a vector containing routes
std::vector<Route*> file_to_Route(const std::string & filename);
