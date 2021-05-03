#include <iterator>
#include "AirportTraversal.h"

AirportTraversal::AirportTraversal(Airports * ap, Airports::Airport * start){
  airports = ap;
  startingAirport = start;
  add(startingAirport);
}

AirportTraversal::Iterator AirportTraversal::begin(){
  return AirportTraversal::Iterator(airports, this, startingAirport);
}

AirportTraversal::Iterator AirportTraversal::end(){
  return AirportTraversal::Iterator();
}

void AirportTraversal::add(Airports::Airport * ap){
  queue.push(ap);
}

Airports::Airport * AirportTraversal::pop(){
  Airports::Airport * current = queue.front();
  queue.pop();
  return current;
}

Airports::Airport * AirportTraversal::peek(){
  return queue.front();
}

bool AirportTraversal::empty() const{
  return queue.empty();
}

AirportTraversal::Iterator::Iterator(){
  airports = NULL;
  traversal = NULL;
  startingAirport = NULL;
  currentAirport = NULL;
}

AirportTraversal::Iterator::Iterator(Airports * ap, AirportTraversal * trav, Airports::Airport* start){
  airports = ap;
  traversal = trav;
  startingAirport = start;
  currentAirport = start;
}

AirportTraversal::Iterator AirportTraversal::Iterator::operator++(){
  return AirportTraversal::Iterator();
}

Airports::Airport * AirportTraversal::Iterator::operator*(){
  return currentAirport;
}

bool AirportTraversal::Iterator::operator!=(const Iterator &other){
  return 0;
}
