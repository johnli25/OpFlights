#include <iterator>
#include "AirportTraversal.h"
#include <iostream>

using namespace std;

AirportTraversal::AirportTraversal(Graph * ap, int startId){
  graph = ap;
  startingAirport = graph->findAirport(startId);
  add(startingAirport);
}

AirportTraversal::Iterator AirportTraversal::begin(){
  return AirportTraversal::Iterator(graph, this, startingAirport);
}

AirportTraversal::Iterator AirportTraversal::end(){
  return AirportTraversal::Iterator();
}

void AirportTraversal::add(Graph::Airport * ap){
  queue.push(ap);
}

Graph::Airport * AirportTraversal::pop(){
  Graph::Airport * current = queue.front();
  queue.pop();
  return current;
}

Graph::Airport * AirportTraversal::peek(){
  return queue.front();
}

bool AirportTraversal::empty() const{
  return queue.empty();
}

AirportTraversal::Iterator::Iterator(){
  graph = NULL;
  traversal = NULL;
  startingAirport = NULL;
  currentAirport = NULL;
  numVisited = 0;
  currentIndex = 0;
}

AirportTraversal::Iterator::Iterator(Graph * ap, AirportTraversal * trav, Graph::Airport* start){
  graph = ap;
  traversal = trav;
  startingAirport = start;
  currentAirport = start;
  numVisited = 0;
  currentIndex = 0;
  // Reset the airports' values
  graph->reset();
}

AirportTraversal::Iterator & AirportTraversal::Iterator::operator++(){
  if (!traversal->empty()){
    currentAirport = traversal->pop();
    currentAirport->visited = true;
    numVisited++;
    for (size_t i = 0; i < currentAirport->routes.size(); i++){
      int next_id = currentAirport->routes[i]->destinationAirportId;
      Graph::Airport * nextAirport = graph->findAirport(next_id); // will this work? Is the graph empty?
      if (!nextAirport->visited){
        traversal->add(nextAirport);
      }
    }
    if (!traversal->empty()){
      currentAirport = traversal->peek();
    }else if (numVisited != graph->numAirports){
      // If traversal is empty but there are still airports left to visit, iterate through vertex table
      for (size_t i = currentIndex; i < graph->airports.size(); i++){
        currentIndex++;
        Graph::Airport * nextAirport = graph->findAirport(i);
        if (nextAirport != NULL && !nextAirport->visited){
          traversal->add(nextAirport);
          currentAirport = traversal->peek();
          break;
        }
      }
    }
  }
  return * this;
}

Graph::Airport * AirportTraversal::Iterator::operator*(){
  return currentAirport;
}

bool AirportTraversal::Iterator::operator!=(const Iterator &other){
  bool thisEmpty = false;
  bool otherEmpty = false;

  if (traversal == NULL) { thisEmpty = true; }
  if (other.traversal == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = traversal->empty(); }
  if (!otherEmpty) { otherEmpty = other.traversal->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the traversals are equal, return true
  else if ((!thisEmpty)&&(!otherEmpty)) return (traversal != other.traversal); //both not empty then compare the traversals (mostly false)
  else return true; // one is empty while the other is not, return true
}
