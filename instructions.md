## Reading airports data to vector
1. The data must be in the format: `ID,"NAME","CITY",_,_,_,LATITUDE,LONGITUDE,_,_,_,_,_,_`
2. The _ fields may be left blank, but there must be the commas
3. The ID of each airport must be unique, non-zero positive integer; they must be in increasing order starting from 1
4. Invalid airports have an ID of 0
5. You may skip ID; however, in the vertex table, note empty fields with ID 0
for example, 1, 2, 4, 5 in the data field would give 0,1,2,0,4,5 in the vertex table
6. The ID of the airport corresponds to the index in the vertex table
7. Use `file_to_Airport("FILENAME.txt")`
8. Returns a vector of Airports: `std::vector<Graph::Airport>`

## Reading routes data to vector
1. The data must be in the format: `_,_,_,SOURCE-AIRPORT-ID,_,DESTINATION-AIRPORT-ID,_,_,_`
2. Use `file_to_Route("FILENAME.txt")`
3. Returns a vector of Routes: `std::vector<Graph::Route>`

## Constructing the graph
1. Use custom constructor `Airports NAME(vector of airports, vector of routes)`

## Finding an airport with a given id
1. Use `Graph.findAirport(ID)`
2. Returns a pointer to the airport in the vertex table: Airports::Airport *

## Accessing the vertex table
1. Use `Graph.airports[ID]` or findAirport(ID) above
2. Make sure to check if the airport is valid (if it has an id of 0), it is invalid
3. findAirport(ID) will return NULL if invalid

## Accessing the adjacency list for a given airport
1. Use `Graph.airports[ID].routes[INDEX]` or `findAirport(ID).routes[INDEX]`

## Accessing the edge list
1. Use `Graph::Route * ROUTE = Graph.allRoutes` to get the head pointer to the edge linked list
2. Use ROUTE->next to get next in list

## Before using any algorithms or BFS, need to reset distance to 0, heuristic to 0, and visited to 0 for each airport in the graph
1. Use `Graph.reset();`
2. When setting the distance to infinity, use `DBL_MAX` from `#include <cfloat>`

## Constructing the priorty queue
1. vector of airports should be from the vertex table of the graph
2. Use `Heap HEAPNAME(vector of airports)` to create a heap from the vector of airports
3. Alternatively, create empty heap using: Heap HEAPNAME and push in each airport: `HEAPNAME.push(AIRPORT)`

## Getting the minimum Airport
1. Use `HEAPNAME.pop()`
2. Returns the Airport with the lowest distance + heuristic

## Updating an airport on the heap with the new distance
1. Use this for Djkstra and A*search after finding a new shortest distance for an airport
2. Get an Airport object and update its distance
3. Then use `HEAPNAME.updateElem(airport with updated distance)`
4. It will find the airport with the same id in the heap and update its distance; then it will
heapifyUp or down to restore the heap
