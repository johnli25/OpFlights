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
#include "AirportTraversal.h"
using std::cout;
using std::endl;
using std::cin;

// Asks the user to input the data and constructs the graph using it
// @returns a pointer to the graph
Graph * enterData(){
	cout<<endl;
	cout<<"ENTERING DATA"<<endl;
	// Gets the data file for the airports and routes
	cout<<"Enter the path to the airports data: ";
	std::string airportFileName;
	std::getline(std::cin, airportFileName);
	cout<<"Enter the path to the routes data: ";
	std::string routeFileName;
	std::getline(std::cin, routeFileName);
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
	cout<<endl;
	cout<<"DIJKSTRA"<<endl;
	bool done = 0;
	bool ranDijk = 0;
	std::string startingAirport;
	int startingAirportId;
	Dijkstra dijk;
	while (done != 1){
		if (startingAirport == ""){
			// Get the name of the airport to start Dijkstra at
			cout<<"Enter the starting airport name or EXIT to go back: ";
			std::getline(std::cin, startingAirport);
			if (startingAirport == "EXIT"){
				// Exits while (done != 1)
				break;
			}
			// Find the id corresponding to the starting airport
			startingAirportId = graph->findAirportID(startingAirport);
		}
		// Check for valid airport
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
		// If haven't run Dijkstra using the startingAirportID, rerun it
		if (ranDijk == 0){
			dijk = Dijkstra(graph, startingAirportId);
			dijk.runDijkstra();
			ranDijk = 1;
		}
		cout<<endl;
		cout<<"Enter 0 to re-enter starting airport name"<<endl;
		cout<<"Enter 1 to find the shortest path to an destination airport"<<endl;
		cout<<"Enter 2 to exit Dijkstra"<<endl;
		cout<<"Enter choice: ";
		std::string choice;
		std::getline(std::cin, choice);
		if (choice == "0"){
			// Need to rerun it using the new starting airport
			ranDijk = 0;
			// Reset the starting airport
			startingAirport = "";
			// Goes back to while(done != 1)
			continue;
		}else if (choice == "1"){
			int destinationAirportId = 0;
			std::string destinationAirport;
			// Continue until it finds a valid airport
			while (destinationAirportId == 0){
				// Get the destination airport name
				cout<<"Enter the destination airport name or EXIT to go back: ";
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
			if (destinationAirportId == startingAirportId){
				cout<<"You are already at "<<startingAirport<<endl;
			}else if (path.size() == 1){
				// Vector of size 1 means only the destination airport Id is in it, meaning no path to it
				cout<<"There is no path from "<<startingAirport<<" to "<<destinationAirport<<endl;
			}else{
				std::vector<std::string> shortest;
				// Get their corresponding names
				for (size_t i = 0; i < path.size(); i++){
					shortest.push_back(graph->airports[path[i]].name);
				}
				cout<<"The shortest path from "<<startingAirport<<" to "<<destinationAirport<<" is:"<<endl;
				for (size_t i = 0; i < shortest.size(); i++){
					cout<<shortest[i]<<endl;
				}
			}
		}else{
			// Exit Dijkstra
			done = 1;
			// Exits while (done != 1)
			break;
		}
	}
}

void a_search(Graph * graph){
	cout<<endl;
	cout<<"A*SEARCH"<<endl;
	bool done = 0;
	bool ranA = 0;
	std::string startingAirport;
	int startingAirportId;
	A_search asearch;
	while (done != 1){
		if (startingAirport == ""){
			// Get the name of the airport to start A Search at
			cout<<"Enter the starting airport name or EXIT to go back: ";
			std::getline(std::cin, startingAirport);
			if (startingAirport == "EXIT"){
				// Exits while (done != 1)
				break;
			}
			// Find the id corresponding to the starting airport
			startingAirportId = graph->findAirportID(startingAirport);
		}
		if (startingAirportId == 0){
			// If can't find the airport, ask the user to reenter the airport name
			cout<<"Airport not found"<<endl;
			// Need to rerun it using the new starting airport
			ranA = 0;
			// Reset the starting airport
			startingAirport = "";
			// Go back to while (done != 1)
			continue;
		}
		// Otherwise, it is valid so run A*search
		// If haven't run A Search using the startingAirportID, rerun it
		if (ranA == 0){
			asearch = A_search(graph, startingAirportId);
			ranA = 1;
		}
		cout<<endl;
		cout<<"Enter 0 to re-enter starting airport name"<<endl;
		cout<<"Enter 1 to find the shortest path to an destination airport"<<endl;
		cout<<"Enter 2 to exit A* Search"<<endl;
		cout<<"Enter choice: ";
		std::string choice;
		std::getline(std::cin, choice);
		if (choice == "0"){
			// Need to rerun it using the new starting airport
			ranA = 0;
			// Reset the starting airport
			startingAirport = "";
			// Goes back to while(done != 1)
			continue;
		}else if (choice == "1"){
			int destinationAirportId = 0;
			std::string destinationAirport;
			// Continue until it finds a valid airport
			while (destinationAirportId == 0){
				// Get the destination airport name
				cout<<"Enter the destination airport name or EXIT to go back: ";
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
			std::vector<int> path = asearch.runA_search(destinationAirportId);
			if (destinationAirportId == startingAirportId){
				cout<<"You are already at "<<startingAirport<<endl;
			}else if (path.size() == 1){
				// Vector of size 1 means only the destination airport Id is in it, meaning no path to it
				cout<<"There is no path from "<<startingAirport<<" to "<<destinationAirport<<endl;
			}else{
				std::vector<std::string> shortest;
				// Get their corresponding names
				for (size_t i = 0; i < path.size(); i++){
					shortest.push_back(graph->airports[path[i]].name);
				}
				cout<<"The shortest path from "<<startingAirport<<" to "<<destinationAirport<<" is:"<<endl;
				for (size_t i = 0; i < shortest.size(); i++){
					cout<<shortest[i]<<endl;
				}
			}
		}else{
			// Exit A Search
			done = 1;
			// Exits while (done != 1)
			break;
		}
	}
}

void bfs(Graph * graph){
	cout<<endl;
	cout<<"BFS ITERATOR"<<endl;
	bool done = 0;
	std::string startingAirport = "";
	int startingAirportId;
	while (done != 1){
		if (startingAirport == ""){
			// Get the name of the airport to start the iterator at
			cout<<"Enter the starting airport name or EXIT to go back: ";
			std::getline(std::cin, startingAirport);
			if (startingAirport == "EXIT"){
				// Exits while (done != 1)
				break;
			}
			// Find the id corresponding to the starting airport
			startingAirportId = graph->findAirportID(startingAirport);
		}
		if (startingAirportId == 0){
			// If can't find the airport, ask the user to reenter the airport name
			cout<<"Airport not found"<<endl;
			// Reset the starting airport
			startingAirport = "";
			// Go back to while (done != 1)
			continue;
		}
		cout<<endl;
		cout<<"Enter 0 to re-enter starting airport name"<<endl;
		cout<<"Enter 1 to start BFS iterator"<<endl;
		cout<<"Enter 2 to exit BFS iterator"<<endl;
		cout<<"Enter choice: ";
		std::string choice;
		std::getline(std::cin, choice);
		if (choice == "0"){
			// Reset the starting airport
			startingAirport = "";
			// Goes back to while(done != 1)
			continue;
		}else if (choice == "1"){
			bool exit = 0;
			// Create the traversal
			AirportTraversal ap = AirportTraversal(graph, startingAirportId);
			// Get iterator to start
			auto cur = ap.begin();
			while (exit != 1){
				cout<<endl;
				cout<<"Enter 0 to see where you are currently at"<<endl;
				cout<<"Enter 1 to move to the next airport"<<endl;
				cout<<"Enter 2 to restart at the beginning"<<endl;
				cout<<"Enter 3 to go back"<<endl;
				cout<<"Enter choice: ";
				std::string choice1;
				std::getline(std::cin, choice1);
				if (choice1 == "0"){
					// If not at the end
					if (cur != ap.end()){
						cout<<"You are currently at "<<(*cur)->name<<endl;
					}else{
						cout<<"You have reached the end"<<endl;
					}
				}else if (choice1 == "1"){
					if (cur != ap.end()){
						++cur;
						if (cur != ap.end()){
							cout<<"You are currently at "<<(*cur)->name<<endl;
						}else{
							cout<<"You have reached the end"<<endl;
						}
					}else{
						cout<<"You have reached the end"<<endl;
					}
				}else if (choice1 == "2"){
					ap = AirportTraversal(graph, startingAirportId);
					cur = ap.begin();
					cout<<"You are back at "<<startingAirport<<endl;
				}else{
					// Exits while (exit != 1)
					exit = 1;
					break;
				}
			}
		}else{
			// Exit BFS
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
		cout<<endl;
		cout<<"Enter 0 to re-enter data"<<endl;
		cout<<"Enter 1 for BFS iterator"<<endl;
		cout<<"Enter 2 for Dijkstra"<<endl;
		cout<<"Enter 3 for A*search"<<endl;
		cout<<"Enter 4 to exit program"<<endl;
		cout<<"Enter choice: ";
		std::string choice;
		std::getline(std::cin, choice);
		if (choice == "0"){
			if (graph != NULL){
				delete graph;
			}
			graph = NULL;
			// Goes back to while (done != 1)
			continue;
		}else if (choice == "1"){
			bfs(graph);
		}else if (choice == "2"){
			dijkstra(graph);
		}else if (choice == "3"){
			a_search(graph);
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
