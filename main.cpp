#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include "Airport.h"

int main() {
	std::vector<Airport*> airports;
	airports = file_to_Airport("tests/airports.dat.txt");
	std::cout<<airports[0]->id<<std::endl;
	std::cout<<airports[0]->name<<std::endl;
	std::cout<<airports[0]->city<<std::endl;
	std::cout<<airports[0]->latitude<<std::endl;
	std::cout<<airports[0]->longitude<<std::endl;
	return 0;
}
