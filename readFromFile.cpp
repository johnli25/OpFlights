#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Airport.h"

bool isValidAirport(const std::string str){
	// Holds the number of commas in the string
	int numCommas = 0;
	// Goes through the string to count the number of commas
	for (unsigned i = 0; i < str.size(); i++){
		if (str[i] == ','){
			numCommas++;
		}
	}
	// For it to be a valid airport, there must be 13 commas
	if (numCommas == 13){
		return true;
	}
	return false;
}

Airport * processAirport(const std::string str){
	// Creates the stringstream of the string
	std::stringstream ss(str);
	// Vector containing each entry in the string
	std::vector<std::string> v;
	// Goes through the stringstream until it is done
	while (ss.good()){
		std::string substring;
		// Gets the subtring separated by commas and store it in the vector
		getline(ss, substring, ',');
		v.push_back(substring);
	}
	Airport * airport = new Airport;
	// Convert the 0-th index substring, which is the id of the airport to stringstream
	// in order to convert to an int
	std::stringstream temp(v[0]);
	temp >> airport->id;
	// Get rid of the quotation marks
	v[1].erase(v[1].begin());
	v[1].erase(v[1].begin()+v[1].length()-1);
	// The 1st index substring holds the name of the airport
	airport->name = v[1];
	// Get rid of the quotation marks
	v[2].erase(v[2].begin());
	v[2].erase(v[2].begin()+v[2].length()-1);
	// The 2nd index substring holds the name of the city
	airport->city = v[2];
	// The 6th substring is the latitude which will be converted to a float
	std::stringstream temp2(v[6]);
	temp2 >> airport->latitude;
	// The 7th substring is the longitude which will be converted to a float
	std::stringstream temp3(v[7]);
	temp3 >> airport->longitude;
	return airport;
}

std::vector<Airport*> file_to_Airport(const std::string & filename) {
	std::vector<Airport *> airports;
	// Create an input stream
	std::ifstream inFile;
	// Open the data file
	inFile.open(filename);
	// Check For Error
	if (inFile.fail()){
		// Close the file if there is an error
		std::cerr << "Error opening file" << std::endl;
		exit(1);
	}
	std::string temp;
	// Read file line by line until end
	while (getline(inFile, temp)){
		// Check if it is a valid airport
		if (isValidAirport(temp)){
			// If it is, process the line and push it into the vector
			airports.push_back(processAirport(temp));
		}
	}
	return airports;
}
