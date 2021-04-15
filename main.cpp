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
	stringstream ss(str);
	vector<string> v;
	while (ss.good()){
		string substring;
		getline(ss, substring, ',');
		v.push_back(substring);
	}
	Airport * airport = new Airport;
	stringstream temp(v[0]);
	temp >> airport->id;
	airport->name = v[1];
	airport->city = v[2];
	stringstream temp2(v[6]);
	temp2 >> airport->latitude;
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
		if (isValidAirport(temp)){
			airports.push_back(processAirport(temp));
		}
	}
	cout << airports[1]->id << endl;
	cout << airports[1]->name << endl;
	cout << airports[1]->city << endl;
	cout << airports[1]->latitude << endl;
	cout << airports[1]->longitude << endl;
	return 0;
}
