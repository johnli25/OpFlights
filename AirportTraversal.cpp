#include <iterator>
#include "AirportTraversal.h"

AirportTraversal::AirportTraversal(Graph * ap, Graph::Airport * start){
  graph = ap;
  startingAirport = start;
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
}

AirportTraversal::Iterator::Iterator(Graph * ap, AirportTraversal * trav, Graph::Airport* start){
  graph = ap;
  traversal = trav;
  startingAirport = start;
  currentAirport = start;
  // Reset the airports' values
  graph->reset();
}

// Work on this
AirportTraversal::Iterator AirportTraversal::Iterator::operator++(){
  return AirportTraversal::Iterator();
}

Graph::Airport * AirportTraversal::Iterator::operator*(){
  return currentAirport;
}

// WOrk on this
bool AirportTraversal::Iterator::operator!=(const Iterator &other){
  return 0;
}
