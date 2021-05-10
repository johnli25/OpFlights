#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cfloat>
#include "Graph.h"
#include "Heap.h"
#include "readFromFile.hpp"
#include "Dijkstra.h"
#include "A_search.h"
using std::cout;
using std::endl;
using std::cin;

// Asks the user to input the data and constructs the graph using it
// @returns a pointer to the graph
Graph * enterData(){
	// Gets the data file for the airports and routes
	cout<<"Enter the path to the airports data"<<endl;
	std::string airportFileName;
	cin>>airportFileName;
	cout<<"Enter the path to the routes data"<<endl;
	std::string routeFileName;
	cin>>routeFileName;
	// Converts data file to vector
	std::vector<Graph::Airport> airports;
	airports = file_to_Airport(airportFileName);
	std::vector<Graph::Route> routes;
	routes = file_to_Route(routeFileName);
	// Constructs the graph using the vectors
	Graph * graph = new Graph(airports, routes);
	return graph;
}

void dijkstra(Graph * graph){
	bool done = 0;
	bool ranDijk = 0;
	while (done != 1){
		std::string startingAirport;
		// Get the name of the airport to start Dijkstra at
		cout<<"Enter the starting airport name: ";
		cin>>std::ws;
		std::getline(std::cin, startingAirport);
		// Find the id corresponding to the starting airport
		int startingAirportId = graph->findAirportID(startingAirport);
		if (startingAirportId == 0){
			// If can't find the airport, ask the user to reenter the airport name
			cout<<"Airport not found"<<endl;
			// Go back to while (done != 1)
			continue;
		}
		// Otherwise, it is valid so run Dijkstra
		Dijkstra dijk = Dijkstra(graph, startingAirportId);
		// If haven't run Dijkstra using the startingAirportID, rerun it
		if (ranDijk == 0){
			dijk.runDijkstra();
			ranDijk = 1;
		}
		cout<<"Enter 0 to re-enter starting airport name"<<endl;
		cout<<"Enter 1 to find the shortest path to an destination airport"<<endl;
		cout<<"Enter 2 to exit Dijkstra"<<endl;
		int choice;
		cin>>choice;
		if (choice == 0){
			// Need to rerun it using the new starting airport
			ranDijk = 0;
			// Goes back to while(done != 1)
			continue;
		}else if (choice == 1){
			int destinationAirportId = 0;
			std::string destinationAirport;
			// Continue until it finds a valid airport
			while (destinationAirportId == 0){
				// Get the destination airport name
				cout<<"Enter the destination airport name or EXIT to go back: ";
				cin>>std::ws;
				std::getline(std::cin, destinationAirport);
				if (destinationAirport == "EXIT"){
					// Exits while (destinationAirportId == 0)
					break;
				}
				// Find the id corresponding to the destination airport
				destinationAirportId = graph->findAirportID(destinationAirport);
				if (destinationAirportId == 0){
					// If can't find the airport, ask the user to reenter the airport name
					cout<<"Airport not found"<<endl;
					// Goes back to while (destinationAirportId == 0)
					continue;
				}
			}
			// User chose EXIT
			if (destinationAirportId == 0){
				// Goes back to while (done != 1)
				continue;
			}
			// Otherwise, find the shortest path to the destination
			std::vector<int> path = dijk.findShortestPath(destinationAirportId);
			std::vector<std::string> shortest;
			// Get their corresponding names
			for (size_t i = 0; i < path.size(); i++){
				shortest.push_back(graph->airports[path[i]].name);
			}
			cout<<"The shortest path from "<<startingAirport<<" to "<<destinationAirport<<" is "<<endl;
			for (size_t i = 0; i < shortest.size(); i++){
				cout<<shortest[i]<<endl;
			}
		}else{
			// Exit Dijkstra
			done = 1;
			// Exits while (done != 1)
			break;
		}
	}
}

int main() {
	bool done = 0;
	Graph * graph = NULL;
	while (done != 1){
		// If no graph has been created yet (first time run or when want to reenter data)
		if (graph == NULL){
			graph = enterData();
		}
		cout<<"Enter 0 to re-enter data"<<endl;
		cout<<"Enter 1 for BFS iterator"<<endl;
		cout<<"Enter 2 for Dijkstra"<<endl;
		cout<<"Enter 3 for A*search"<<endl;
		cout<<"Enter 4 to exit program"<<endl;
		int choice;
		cin>>choice;
		if (choice == 0){
			if (graph != NULL){
				delete graph;
			}
			graph = NULL;
			// Goes back to while (done != 1)
			continue;
		}else if (choice == 1){

		}else if (choice == 2){
			dijkstra(graph);
		}else if (choice == 3){

		}else{
			done = 1;
			// Exits while (done != 1)
			break;
		}
	}
	if (graph != NULL){
		delete graph;
	}
/*
	std::vector<Graph::Airport> airports;
	airports = file_to_Airport("tests/airportsExample.dat.txt");
	std::vector<Graph::Route> routes;
	routes = file_to_Route("tests/routesExample.dat.txt");
	Graph airportss(airports, routes);
	//Dijkstra(&airportss, 1);

	//testing A_search

        A_search aStar = A_search(&airportss, 1);
	std::vector<int> traversal = aStar.runA_search(4029);
	for(size_t i=0; i < traversal.size(); i++){
	  std::cout << traversal.at(i) << ' ';
        }
				*/
	/*
	std::vector<Graph::Airport> airports;
	airports = file_to_Airport("tests/airportsMain.dat.txt");
	std::vector<Graph::Route> routes;
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
	Graph airportss(airports, routes);
	Graph airportss2(airportss);
	Graph::Airport ap11 = airportss.airports[1];
	Graph::Route * ro110 = ap11.routes[0];
	Graph::Route * ro111 = ap11.routes[1];
	Graph::Airport ap12 = airportss.airports[2];
	Graph::Airport ap21 = airportss2.airports[1];
	Graph::Route * ro210 = ap21.routes[0];
	Graph::Route * ro211 = ap21.routes[1];
	Graph::Airport ap22 = airportss2.airports[1];
	std::cout<<airportss.allRoutes->sourceAirportId<<std::endl;
	std::cout<<airportss.allRoutes->destinationAirportId<<std::endl;
	std::cout<<airportss.allRoutes->next->sourceAirportId<<std::endl;
	std::cout<<airportss.allRoutes->next->destinationAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->sourceAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->destinationAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->next->sourceAirportId<<std::endl;
	std::cout<<airportss2.allRoutes->next->destinationAirportId<<std::endl;
	Graph::Airport* air = airportss.findAirport(1);
	std::cout<<air->id<<std::endl;
	air = airportss2.findAirport(1);
	std::cout<<air->id<<std::endl;
	air = airportss.findAirport(2);
	std::cout<<air->id<<std::endl;
	air = airportss2.findAirport(2);
	std::cout<<air->id<<std::endl;
	*/


	// Testing heap
	/*
	std::vector<Graph::Airport> airports;
	airports = file_to_Airport("tests/airportsMain2.dat.txt");
	std::vector<Graph::Route> routes;
	routes = file_to_Route("tests/routes.dat.txt");
	Graph ap(airports, routes);
	for (int i = 0; i < ap.airports.size(); i++){
		if (ap.airports[i].id != 0){
			ap.airports[i].distance = DBL_MAX;
			ap.airports[i].heuristic = i-2;
		}
	}
	Heap heap(ap.airports);
	Graph::Airport a1;
	a1.id = 5;
	a1.distance = 7;
	a1.heuristic = 3;
	heap.push(a1);
	Graph::Airport a2;
	a2.id = 6;
	a2.distance = 5;
	a2.heuristic = 4;
	heap.push(a2);
	Graph::Airport air = heap.pop();
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
