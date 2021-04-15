#include <iostream>
#include <vector>
#include "readFromFile.hpp"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Airport{
	int id;
	string name;
	string city;
	float latitude;
	float longitude;
};

// Function to determine if the line of the airport file contains all the information.
// For it to contain all the information, it must contain 13 commas.
// This function counts the number of commas in the string and returns true if it is a valid
// airport. Else, return false.
bool isValidAirport(string str){
	int count = 0;
	for (unsigned i = 0; i < str.size(); i++){
		if (str[i] == ','){
			count++;
		}
	}
	if (count == 13){
		return true;
	}
	return false;
}

// Reads through the string of airport data and intializes the corresponding member variables.
// Returns a pointer to Airport object.
Airport * processAirport(string str){
	// Creates the stringstream of the string
	stringstream ss(str);
	// Vector containing each entry in the string
	vector<string> v;
	// Goes through the stringstream until it is done
	while (ss.good()){
		string substring;
		// Gets the subtring separated by commas and store it in the vector
		getline(ss, substring, ',');
		v.push_back(substring);
	}
	Airport * airport = new Airport;
	// Convert the 0-th index substring, which is the id of the airport to stringstream
	// in order to convert to an int
	stringstream temp(v[0]);
	temp >> airport->id;
	// The 1st index substring holds the name of the airport
	airport->name = v[1];
	// The 2nd index substring holds the name of the city
	airport->city = v[2];
	// The 6th substring is the latitude which will be converted to a float
	stringstream temp2(v[6]);
	temp2 >> airport->latitude;
	// The 7th substring is the longitude which will be converted to a float
	stringstream temp3(v[7]);
	temp3 >> airport->longitude;
	return airport;
}

int main() {
	vector<Airport *> airports;
	// Create an input stream
	ifstream inFile;
	// Open the data file
	inFile.open("tests/airports.dat.txt");

	// Check For Error
	if (inFile.fail()){
		// Close the file if there is an error
		cerr << "Error opening file" << endl;
		exit(1);
	}

	string temp;
	
	// Read file line by line until end
	while (getline(inFile, temp)){
		// Check if it is a valid airport
		if (isValidAirport(temp)){
			// If it is, process the line and push it into the vector
			airports.push_back(processAirport(temp));
		}
	}
	// Test to check if successfully input
	cout << airports[1]->id << endl;
	cout << airports[1]->name << endl;
	cout << airports[1]->city << endl;
	cout << airports[1]->latitude << endl;
	cout << airports[1]->longitude << endl;
	return 0;
}
