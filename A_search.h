#pragma once
#include <vector>
#include <queue>
#include "Graph.h"
#include "Heap.h"

class A_search{
 public:
  // Default constructor
  A_search();

  // Custom constructor
  // @param pointer to airports data graph, id of airport where you start the search from
  A_search(Graph * airports, int sourceId);

  // Runs the A*search algorithm taking the id of the destination airport as 
  // a parameter and outputting the full path from source to destination in a 
  // vector, only the destination is printed if no path exists
  // @param id of airport to end the search
  std::vector<int> runA_search(int destinationAirportId);

  // Sets the graph that Dijkstra is run on
  // @param graph of airports
  void setGraph(Graph * airports);

  // Sets the starting airport
  // @param id of starting airport
  void setStart(int sourceId);

  // Returns a pointer to the input graph
  // @param Dijkstra object
  Graph * getGraph();

 private:
  //  Private helper function used to calculate heuristic values
  //  @param pointer to source and destination airport
  double distance(Graph::Airport * sourceAirport, Graph::Airport * destinationAirport);

  // Pointer to airports graph
  Graph * graph;
  // Starting airportID
  int sourceAirportId;
};
