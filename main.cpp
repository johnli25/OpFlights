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
	std::string startingAirport;
	while (done != 1){
		if (startingAirport == ""){
			// Get the name of the airport to start Dijkstra at
			cout<<"Enter the starting airport name or EXIT to go back: ";
			cin>>std::ws;
			std::getline(std::cin, startingAirport);
			if (startingAirport == "EXIT"){
				// Exits while (done != 1)
				break;
			}
		}
		// Find the id corresponding to the starting airport
		int startingAirportId = graph->findAirportID(startingAirport);
		if (startingAirportId == 0){
			// If can't find the airport, ask the user to reenter the airport name
			cout<<"Airport not found"<<endl;
			// Need to rerun it using the new starting airport
			ranDijk = 0;
			// Reset the starting airport
			startingAirport = "";
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
			// Reset the starting airport
			startingAirport = "";
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
<<<<<<< HEAD
			std::vector<std::string> shortest;
			// Get their corresponding names
			for (size_t i = 0; i < path.size(); i++){
				shortest.push_back(graph->airports[path[i]].name);
			}
			cout<<"The shortest path from "<<startingAirport<<" to "<<destinationAirport<<" is:";
			for (size_t i = 0; i < shortest.size(); i++){
				cout<<shortest[i]<<endl;
=======
			// Vector of size 1 means only the destination airport Id is in it, meaning no path to it
			if (path.size() == 1){
				cout<<"There is no path from "<<startingAirport<<" to "<<destinationAirport<<endl;
			}else{
				std::vector<std::string> shortest;
				// Get their corresponding names
				for (size_t i = 0; i < path.size(); i++){
					shortest.push_back(graph->airports[path[i]].name);
				}
				cout<<"The shortest path from "<<startingAirport<<" to "<<destinationAirport<<" is:";
				for (size_t i = 0; i < shortest.size(); i++){
					cout<<shortest[i]<<endl;
				}
>>>>>>> f4433894e107584b46e19c8848cdd7e12ad5457e
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
			// DO THIS!!!!!!!!!
			// Runs BFS iterator
			// Make a new function; asks the user to input starting airport
			// then asks if the user wants to see current airport, next airport, etc. using the BFS
			//bfs(graph);
		}else if (choice == 2){
			dijkstra(graph);
		}else if (choice == 3){
			// DO THIS!!!!!!!!
			// Runs A*Search
			// Make a new function; asks the user to input starting airport and destination airport
			// Add other prompts similar to Dijkstra's above
			// a_search(grapj);
		}else{
			done = 1;
			// Exits while (done != 1)
			break;
		}
	}
	// Delete the graph when done
	if (graph != NULL){
		delete graph;
	}
	return 0;
}
