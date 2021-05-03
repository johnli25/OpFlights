#include <vector>
#include "Airports.h"
#include "Heap.h"

class Dijkstra{
  public:
    // Default constructor
    Dijkstra();

    // Custom constructor
    // @param pointer to airports data graph, id of airport where you start the search from
    Dijkstra(Airports * airports, int sourceId);

    // Runs Dijkstra's algorithm that modifies the graph to produce a shortest path tree from the starting airport
    void runDijkstra();

    // After running Dijkstra's algorithm, goes through the graph starting at the destination airport
    // and go backwards using the predecessor to produce the shortest path of airports to get
    // from the source airport to the destination airport
    // @param Id of the destination airport
    // @returns a vector of airport ID's representing the shortest path from the source to the destination
    // EX: vector {3,2,5,7,9} means the shortest path from airport 3 to airport 9 is 3->2->5->7->9
    std::vector<int> findShortestPath(int destinationAirportId);

    // Sets the graph that Dijkstra is run on
    // @param graph of airports
    void setGraph(Airports * airports);

    // Sets the starting airport
    // @param id of starting airport
    void setStart(int sourceId);

  private;
    // Pointer to airports graph
    Airports * graph;
    // Starting airportID
    int sourceAirportId;
};
