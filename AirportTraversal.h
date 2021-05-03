#pragma once
#include <iterator>
#include <queue>
#include "Airports.h"

class AirportTraversal{
  public:
    class Iterator : std::iterator<std::forward_iterator_tag, Airports::Airport*>
    {
      public:
        // Default constructor
        Iterator();
        // Custom constructor
        Iterator(Airports * ap, AirportTraversal * trav, Airports::Airport * start);
        Iterator operator++();
        Airports::Airport * operator*();
        bool operator != (const Iterator &other);
      private:
        Airports * airports;
        AirportTraversal * traversal;
        // Airport to start the traversal at
        Airports::Airport* startingAirport;
        Airports::Airport* currentAirport;
    };
    AirportTraversal(Airports * ap, Airports::Airport * start);
    Iterator begin();
    Iterator end();
    void add(Airports::Airport * ap);
    Airports::Airport * pop();
    Airports::Airport * peek();
    bool empty() const;
  private:
    // Queue of pointer to airports in the original graph
    std::queue<Airports::Airport*> queue;
    Airports * airports;
    // Airport to start the traversal at
    Airports::Airport * startingAirport;
};
