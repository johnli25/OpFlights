// Reading airports data to vector
The data must be in the format: ID,"NAME","CITY",_,_,_,LATITUDE,LONGITUDE,_,_,_,_,_,_
*The _ fields may be left blank, but there must be the commas
*The ID of each airport must be unique, non-zero positive integer
*Invalid airports have an ID of 0
-You may skip ID; however, in the vertex table, note empty fields with ID 0
for example, 1, 2, 4, 5 in the data field would give 0,1,2,0,4,5 in the vertex table
*The ID of the airport corresponds to the index in the vertex table
Use file_to_Airport("FILENAME.txt")
Returns a vector of Airports: std::vector<Airports::Airport>

// Reading routes data to vector
The data must be in the format: _,_,_,SOURCE-AIRPORT-ID,_,DESTINATION-AIRPORT-ID,_,_,_
Use file_to_Route("FILENAME.txt")
Returns a vector of Routes: std::vector<Airports::Route>

// Constructing the graph
Use custom constructor Airports NAME(vector of airports, vector of routes)

// Finding an airport with a given id
Use Airports.findAirport(ID)
Returns a pointer to the airport in the vertex table: Airports::Airport *

// Accessing the vertex table
Use Airports.airports[ID] or findAirport(ID) above

// Accessing the adjacency list for a given airport
Use Airports.airports[ID].routes[INDEX] or findAirport(ID).routes[INDEX]

// Accessing the edge list
Use Airports::Route * ROUTE = Airports.allRoutes to get the head pointer to the edge linked list
Use ROUTE->next to get next in list

// Before using any algorithms or BFS, need to reset distance, heuristic, and visited for each airport in the graph
Should have a pointer to the Graph object as a member variable in each of the algorithm so for the constructor, pass in the Graph as a reference or pointer
For example, constructor for Djkstra
Djkstra(Airports * GRAPH){
  Airports * graph = GRAPH;
}

// Constructing the priorty queue
vector of airports should be from the vertex table of the graph
Use Heap HEAPNAME(vector of airports) to create a heap from the vector of airports
Alternatively, create empty heap using: Heap HEAPNAME and push in each airport: HEAPNAME.push(AIRPORT)

// Getting the minimum Airport
Use HEAPNAME.pop()
Returns the Airport with the lowest distance + heuristic

// Updating an airport on the heap with the new distance
Use this for Djkstra and A*search after finding a new shortest distance for an airport
Get an Airport object and update its distance
Then use HEAPNAME.updateElem(airport with updated distance)
It will find the airport with the same id in the heap and update its distance; then it will
heapifyUp or down to restore the heap
