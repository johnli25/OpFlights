#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include "Airport.h"
#include "Route.h"

int main() {
	std::vector<Airport*> airports;
	airports = file_to_Airport("tests/airports.dat.txt");
	std::vector<Route*> routes;
	routes = file_to_Route("tests/routes.dat.txt");
	std::cout<<airports[0]->id<<std::endl;
	std::cout<<airports[0]->name<<std::endl;
	std::cout<<airports[0]->city<<std::endl;
	std::cout<<airports[0]->latitude<<std::endl;
	std::cout<<airports[0]->longitude<<std::endl;
	std::cout<<airports[1]->id<<std::endl;
	std::cout<<airports[1]->name<<std::endl;
	std::cout<<airports[1]->city<<std::endl;
	std::cout<<airports[1]->latitude<<std::endl;
	std::cout<<airports[1]->longitude<<std::endl;
	std::cout<<routes[0]->sourceAirportId<<std::endl;
	std::cout<<routes[0]->destinationAirportId<<std::endl;
	std::cout<<routes[1]->sourceAirportId<<std::endl;
	std::cout<<routes[1]->destinationAirportId<<std::endl;
	return 0;
}
