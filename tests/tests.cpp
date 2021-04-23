#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"

// Helper function to test if two vectors of airports are the same
bool compareAirports(std::vector<Airports::Airport*> airport1, std::vector<Airports::Airport*> airport2){
	// Make sure they have the same number of airports
	if (airport1.size() == airport2.size()){
		for (int i = 0; i < 1; i++){
			REQUIRE(airport1[i]->id == airport2[i]->id);
			REQUIRE(airport1[i]->name == airport2[i]->name);
			REQUIRE(airport1[i]->city == airport2[i]->city);
			REQUIRE(airport1[i]->latitude == airport2[i]->latitude);
			REQUIRE(airport1[i]->longitude == airport2[i]->longitude);
		}
	}else{
		return false;
	}
	return true;
}

TEST_CASE("Verify that file_to_Airport works on a small example") {
	std::vector<Airports::Airport*> airports = file_to_Airport("tests/airports.dat.txt");
	// always check "expected" == "actual" --> be consistent
	std::vector<Airports::Airport*> expected;
	Airports::Airport airport1;
	airport1.id = 1;
	airport1.name = "Goroka Airport";
	airport1.city = "Goroka";
	airport1.latitude = -6.081689834590001;
	airport1.longitude = 145.391998291;
	expected.push_back(&airport1);
	Airports::Airport airport2;
	airport2.id = 2;
	airport2.name = "Madang Airport";
	airport2.city = "Madang";
	airport2.latitude = -5.20707988739;
	airport2.longitude = 145.789001465;
	expected.push_back(&airport2);
	REQUIRE(compareAirports(expected,airports));
}

TEST_CASE("Verify that file_to_Route works on a small example") {
	std::vector<Airports::Route*> routes = file_to_Route("tests/routes.dat.txt");
	REQUIRE(2965 == routes[0]->sourceAirportId);
	REQUIRE(2990 == routes[0]->destinationAirportId);
	REQUIRE(2966 == routes[1]->sourceAirportId);
	REQUIRE(2990 == routes[1]->destinationAirportId);
	REQUIRE(2966 == routes[2]->sourceAirportId);
	REQUIRE(2962 == routes[2]->destinationAirportId);
	REQUIRE(2968 == routes[3]->sourceAirportId);
	REQUIRE(2990 == routes[3]->destinationAirportId);
	REQUIRE(2968 == routes[4]->sourceAirportId);
	REQUIRE(4078 == routes[4]->destinationAirportId);
	REQUIRE(4029 == routes[5]->sourceAirportId);
	REQUIRE(2990 == routes[5]->destinationAirportId);
}
