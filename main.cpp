#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include "Airports.h"
#include "Heap.h"
#include <cfloat>

int main() {
	std::vector<Airports::Airport> airports;
	airports = file_to_Airport("tests/airportsALL.dat.txt");
	std::vector<Airports::Route> routes;
	routes = file_to_Route("tests/routesALL.dat.txt");
	/*
	std::vector<Airports::Airport> airports;
	airports = file_to_Airport("tests/airportsMain.dat.txt");
	std::vector<Airports::Route> routes;
	routes = file_to_Route("tests/routes.dat.txt");
	std::cout<<airports[0].id<<std::endl;
	std::cout<<airports[0].name<<std::endl;
	std::cout<<airports[0].city<<std::endl;
	std::cout<<airports[0].latitude<<std::endl;
	std::cout<<airports[0].longitude<<std::endl;
	std::cout<<airports[1].id<<std::endl;
	std::cout<<airports[1].name<<std::endl;
	std::cout<<airports[1].city<<std::endl;
	std::cout<<airports[1].latitude<<std::endl;
	std::cout<<airports[1].longitude<<std::endl;
	std::cout<<routes[0].sourceAirportId<<std::endl;
	std::cout<<routes[0].destinationAirportId<<std::endl;
	std::cout<<routes[1].sourceAirportId<<std::endl;
	std::cout<<routes[1].destinationAirportId<<std::endl;
	Airports airportss(airports, routes);
	Airports airportss2(airportss);
	Airports::Airport ap11 = airportss.airports[1];
	Airports::Route * ro110 = ap11.routes[0];
	Airports::Route * ro111 = ap11.routes[1];
	Airports::Airport ap12 = airportss.airports[2];
	Airports::Airport ap21 = airportss2.airports[1];
	Airports::Route * ro210 = ap21.routes[0];
	Airports::Route * ro211 = ap21.routes[1];
	Airports::Airport ap22 = airportss2.airports[1];
	std::cout<<airportss.allRoutes->sourceAirportId<<std::endl;
	std::cout<<airportss.allRoutes->destinationAirportId<<std::endl;
	std::cout<<airportss.allRoutes->next->sourceAirportId<<std::endl;
	std::cout<<airportss.allRoutes->next->destinationAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->sourceAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->destinationAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->next->sourceAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->next->destinationAirportId<<std::endl;
	Airports::Airport* air = airportss.findAirport(1);
	std::cout<<air->id<<std::endl;
	air = airportss2.findAirport(1);
	std::cout<<air->id<<std::endl;
	air = airportss.findAirport(2);
	std::cout<<air->id<<std::endl;
	air = airportss2.findAirport(2);
	std::cout<<air->id<<std::endl;
	*/
	/*
	std::vector<Airports::Airport> airports;
	airports = file_to_Airport("tests/airportsMain2.dat.txt");
	std::vector<Airports::Route> routes;
	routes = file_to_Route("tests/routes.dat.txt");
	Airports ap(airports, routes);
	for (int i = 0; i < ap.airports.size(); i++){
		if (ap.airports[i].id != 0){
			ap.airports[i].distance = DBL_MAX;
			ap.airports[i].heuristic = i-2;
		}
	}
	Heap heap(ap.airports);
	Airports::Airport a1;
	a1.id = 5;
	a1.distance = 7;
	a1.heuristic = 3;
	heap.push(a1);
	Airports::Airport a2;
	a2.id = 6;
	a2.distance = 5;
	a2.heuristic = 4;
	heap.push(a2);
	Airports::Airport air = heap.pop();
	air = heap.pop();
	air = heap.pop();
	air = heap.pop();
	air = heap.pop();
	air = heap.pop();
	air = heap.pop();
	air = heap.pop();
	air = heap.pop();
	*/
	return 0;
}
