#pragma once
#include <iterator>
#include <queue>
#include "Airports.h"

class AirportTraversal{
  public:
    class Iterator : std::iterator<std::forward_iterator_tag, Airports::Airport*>
    {
      public:
        // Default constructor; used to create end()
        Iterator();
        // Custom constructor
        // @param ap Pointer to graph of airports and routes start Pointer to the airport in the graph to begin BFS 
        Iterator(Airports * ap, AirportTraversal * trav, Airports::Airport * start);
        // Advances the iterator; Should add adjacent airports and go to one of them (only add airports that the current airport has a directed route to
        // Go through the adjacency list (routes vector) and check for routes that have the current airport as the sourceAirportID; the destinationID is
        // is the adjacent airport
        Iterator operator++();
        // Accesses the current airport
        Airports::Airport * operator*();
        // Checks if the current iterator is not at the end
        bool operator != (const Iterator &other);
      private:
        // Pointer to the graph data structure
        Airports * airports;
        // Pointer to the type of traversal; use traversal->pop() to use the functions outside
        AirportTraversal * traversal;
        // Airport to start the traversal at
        Airports::Airport* startingAirport;
        // Airport the traversal is currently at
        Airports::Airport* currentAirport;
    };
    // Custom constructor
    // @param ap Pointer to the graph start Pointer to the airport in the graph to start BFS at
    AirportTraversal(Airports * ap, Airports::Airport * start);
    Iterator begin();
    Iterator end();
    // Adds the airport to the queue
    void add(Airports::Airport * ap);
    // Takes an airport off the queue
    Airports::Airport * pop();
    // Checks what airport is at the front of the queue
    Airports::Airport * peek();
    // Check if the queue is empty
    bool empty() const;
  private:
    // Queue of pointer to airports in the original graph
    std::queue<Airports::Airport*> queue;
    // Pointer to the graph data structure
    Airports * airports;
    // Airport to start the traversal at
    Airports::Airport * startingAirport;
};
