#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../readFromFile.hpp"

// Helper function to test if two vectors of airports are the same
bool compareAirports(std::vector<Airports::Airport> airport1, std::vector<Airports::Airport> airport2){
	// Make sure they have the same number of airports
	if (airport1.size() == airport2.size()){
		for (int i = 0; i < airport1.size(); i++){
			REQUIRE(airport1[i].id == airport2[i].id);
			REQUIRE(airport1[i].name == airport2[i].name);
			REQUIRE(airport1[i].city == airport2[i].city);
			REQUIRE(airport1[i].latitude == airport2[i].latitude);
			REQUIRE(airport1[i].longitude == airport2[i].longitude);
		}
	}else{
		return false;
	}
	return true;
}

TEST_CASE("Verify that file_to_Airport works on a small example") {
	std::vector<Airports::Airport> airports = file_to_Airport("tests/airportsSmall.dat.txt");
	// always check "expected" == "actual" -. be consistent
	std::vector<Airports::Airport> expected;
	Airports::Airport airport1;
	airport1.id = 1;
	airport1.name = "Goroka Airport";
	airport1.city = "Goroka";
	airport1.latitude = -6.081689834590001;
	airport1.longitude = 145.391998291;
	expected.push_back(airport1);
	Airports::Airport airport2;
	airport2.id = 2;
	airport2.name = "Madang Airport";
	airport2.city = "Madang";
	airport2.latitude = -5.20707988739;
	airport2.longitude = 145.789001465;
	expected.push_back(airport2);
	Airports::Airport airport3;
	airport3.id = 3;
	airport3.name = "Mount Airport";
	airport3.city = "Mount";
	airport3.latitude = -5.826789855957031;
	airport3.longitude = 144.29600524902344;
	expected.push_back(airport3);
	Airports::Airport airport4;
	airport4.id = 4;
	airport4.name = "Nadzab Airport";
	airport4.city = "Nadzab";
	airport4.latitude = -6.569803;
	airport4.longitude = 146.725977;
	expected.push_back(airport4);
	REQUIRE(compareAirports(expected,airports));
}

TEST_CASE("Verify that file_to_Route works on a medium example") {
	std::vector<Airports::Route> routes = file_to_Route("tests/routesSmall.dat.txt");
	REQUIRE(1 == routes[0].sourceAirportId);
	REQUIRE(2 == routes[0].destinationAirportId);
	REQUIRE(2 == routes[1].sourceAirportId);
	REQUIRE(1 == routes[1].destinationAirportId);
	REQUIRE(1 == routes[2].sourceAirportId);
	REQUIRE(3 == routes[2].destinationAirportId);
	REQUIRE(3 == routes[3].sourceAirportId);
	REQUIRE(1 == routes[3].destinationAirportId);
	REQUIRE(2 == routes[4].sourceAirportId);
	REQUIRE(3 == routes[4].destinationAirportId);
	REQUIRE(3 == routes[5].sourceAirportId);
	REQUIRE(4 == routes[5].destinationAirportId);
}

TEST_CASE("Verify that custom constructor work"){
	std::vector<Airports::Airport> airports = file_to_Airport("tests/airportsSmall.dat.txt");
	std::vector<Airports::Route> routes = file_to_Route("tests/routesSmall.dat.txt");
	Airports airports1(airports, routes);
	for (int i = 0; i < airports.size(); i++){
		// Get the id of the airport
		int id = airports[i].id;
		REQUIRE(airports1.airports[id].id == id);
		REQUIRE(airports1.airports[id].name == airports[i].name);
		REQUIRE(airports1.airports[id].city == airports[i].city);
		REQUIRE(airports1.airports[id].latitude == airports[i].latitude);
		REQUIRE(airports1.airports[id].longitude == airports[i].longitude);
	}
	// Get the pointer to the edge list
	Airports::Route * cur = airports1.allRoutes;
	int index = 0;
	while (cur != NULL){
		REQUIRE(cur->sourceAirportId == routes[index].sourceAirportId);
		REQUIRE(cur->destinationAirportId == routes[index].destinationAirportId);
		index++;
		cur = cur->next;
	}
}

TEST_CASE("Verify that copy constructor work"){
	std::vector<Airports::Airport> airports = file_to_Airport("tests/airportsSmall.dat.txt");
	std::vector<Airports::Route> routes = file_to_Route("tests/routesSmall.dat.txt");
	Airports airports1(airports, routes);
	Airports airports2(airports1);
	for (int i = 0; i < airports1.airports.size(); i++){
		// If it is a valid airport, check if both graphs have the same airport
		if (airports1.airports[i].id != 0){
			REQUIRE(airports1.airports[i].id == airports2.airports[i].id);
			REQUIRE(airports1.airports[i].name == airports2.airports[i].name);
			REQUIRE(airports1.airports[i].city == airports2.airports[i].city);
			REQUIRE(airports1.airports[i].latitude == airports2.airports[i].latitude);
			REQUIRE(airports1.airports[i].longitude == airports2.airports[i].longitude);
			// Check their adjacency lists
			std::vector<Airports::Route*> cur1 = airports1.airports[i].routes;
			std::vector<Airports::Route*> cur2 = airports2.airports[i].routes;
			for (int index = 0; index < cur1.size(); index++){
				REQUIRE(cur1[index]->sourceAirportId == cur2[index]->sourceAirportId);
				REQUIRE(cur1[index]->destinationAirportId == cur2[index]->destinationAirportId);
				REQUIRE(cur1[index]->distance == cur2[index]->distance);
			}
		}
	}
	// Check their edge lists
	Airports::Route * cur1 = airports1.allRoutes;
	Airports::Route * cur2 = airports2.allRoutes;
	while (cur1 != NULL){
		REQUIRE(cur1->sourceAirportId == cur2->sourceAirportId);
		REQUIRE(cur1->destinationAirportId == cur2->destinationAirportId);
		REQUIRE(cur1->distance == cur2->distance);
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
}
