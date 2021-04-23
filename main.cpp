#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include "Airports.h"

int main() {
	std::vector<Airports::Airport*> airports;
	airports = file_to_Airport("tests/airports.dat.txt");
	std::vector<Airports::Route*> routes;
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
	Airports airportss;
	airportss.setAirports(&airports);
	Airports::Airport* air = airportss.findAirport(1);
	std::cout<<air->id<<std::endl;
	air = airportss.findAirport(2);
	std::cout<<air->id<<std::endl;
	air = airportss.findAirport(9);
	std::cout<<air->id<<std::endl;
	return 0;
}
