#include <iterator>
#include "AirportTraversal.h"
#include <iostream>

using namespace std;

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

  visited.resize(graph->airports.size());
  cout << visited.size() << endl;
  for (size_t i = 0; i < visited.size(); i++){
    visited[i] = false;
  }  
}

// Work on this
AirportTraversal::Iterator AirportTraversal::Iterator::operator++(){
  if (!traversal->empty()){
    currentAirport = traversal->pop();
    visited[currentAirport->id] = true;
    //push edges to be traversed
    while (size_t i = 0; i < currentAirport->routes.size(); i++){
      //complicated process of getting route Airports lmao
      if(!visited[currentAirport->routes[i]->destinationAirportId]){
	traversal->push_back(findAirport(currentAirport->routes[i]
					 ->destinationAirportId));
      }
    }
  }
  return AirportTraversal::Iterator();
}

Graph::Airport * AirportTraversal::Iterator::operator*(){
  return currentAirport;
}

// WOrk on this
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
