#pragma once
#include <iterator>
#include <queue>
#include "Graph.h"
#include <iostream>

using namespace std;

class AirportTraversal{
  public:
    class Iterator : std::iterator<std::forward_iterator_tag, Graph::Airport*>
    {
      public:
        // Default constructor; 
        Iterator();
        // Custom constructor
        // @param ap Pointer to graph of airports and routes start Pointer to the airport in the graph to begin BFS
        Iterator(Graph * ap, AirportTraversal * trav, Graph::Airport * startId);
        // Advances the iterator; Should add adjacent airports and go to one of them (only add airports that the current airport has a directed route to
        // Go through the adjacency list (routes vector) and check for routes that have the current airport as the sourceAirportID; the destinationID is
        // is the adjacent airport
        Iterator & operator++();
        // Accesses the current airport
        Graph::Airport * operator*();
        // Checks if the current iterator is not at the end
        bool operator != (const Iterator &other);
      private:
        // Pointer to the graph data structure
        Graph * graph;
        // Pointer to the type of traversal; use traversal->pop() to use the functions outside
        AirportTraversal * traversal;
        // Airport to start the traversal at
        Graph::Airport* startingAirport;
        // Airport the traversal is currently at
        Graph::Airport* currentAirport;
        // Used to optimize the iterator so it doesn't start at the beginning everytime there is a disconnect part
        int currentIndex;
        // Number of airports visited
        int numVisited;
    };
    // Custom constructor
    // @param ap Pointer to the graph startId id of airport in the graph to start BFS at
    AirportTraversal(Graph * ap, int startId);
    Iterator begin();
    Iterator end();
    // Adds the airport to the queue
    void add(Graph::Airport * ap);
    // Takes an airport off the queue
    Graph::Airport * pop();
    // Checks what airport is at the front of the queue
    Graph::Airport * peek();
    // Check if the queue is empty
    bool empty() const;
  private:
    // Queue of pointer to airports in the original graph
    std::queue<Graph::Airport*> queue;
    // Pointer to the graph data structure
    Graph * graph;
    // Airport to start the traversal at
    Graph::Airport * startingAirport;
    // Current index in the vertex table; used to iterate through the vertex table to find an unvisited airport when there are disconnected parts
};
