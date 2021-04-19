#pragma once
#include <vector>
#include <string>

struct Airports{
	struct Airport{
		int id;
		std::string name;
		std::string city;
		float latitude;
		float longitude;
	};

	struct Route{
		int sourceAirportId;
	  int destinationAirportId;
	  double distance;
	};
	std::vector<Route> routes;
};
