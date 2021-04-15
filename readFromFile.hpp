#include <string>
#include "Airport.h"

// Function that determine if the string is a valid airport, meaning it contains
// every entry of data.
// @param str A string containing a line from the airport.dat file
// @return true if it is a valid airport
bool isValidAirport(const std::string str);

// Goes through the string containing a valid airport and intializes the corresponding member variables.
// @param str A string containing data for a valid airport
// @return a pointer to a airport
Airport * processAirport(const std::string str);

// Reads a airport file
// @param filename The file to read from
// @return a string containing filename's contents

std::vector<Airport*> file_to_Airport(const std::string & filename);
