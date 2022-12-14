#include <cfloat>
#include "Heap.h"
#include <iostream>

bool Heap::higherPriority(const Graph::Airport & airport1, const Graph::Airport & airport2) const{
  double dist1 = airport1.distance + airport1.heuristic;
  double dist2 = airport2.distance + airport2.heuristic;
  // If both are at infinity (Adding any number to DBL_MAX = DBL_MAX)
  if ((dist1 == DBL_MAX) && (dist2 == DBL_MAX)){
    // Compare heuristic
    if (airport1.heuristic <= airport2.heuristic){
      // If airport1 is closer
      return true;
    }
  }else{
    // One or both of the distance is not at infinity so just compare distances
    if (dist1 <= dist2){
      // If airport1 is closer
      return true;
    }
  }
  // Airport2 is closer
  return false;
}

size_t Heap::root() const{
  return 1;
}

size_t Heap::leftChild(size_t currentIdx) const{
  return 2*currentIdx;
}

size_t Heap::rightChild(size_t currentIdx) const{
  return 2*currentIdx + 1;
}

size_t Heap::parent(size_t currentIdx) const{
  return currentIdx/2;
}

bool Heap::hasAChild(size_t currentIdx) const{
  // Check if it has a left child; if it doesn't, it also means it doesn't have a right child
  // since it is a complete tree
  if (leftChild(currentIdx) > size_){
    return false;
  }
  // Otherwise, it has a left child (and potentially a right child)
  return true;
}

size_t Heap::maxPriorityChild(size_t currentIdx) const{
  // If the left child is smaller than the right child
  if (higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)])){
    // Return the index of the left child
    return leftChild(currentIdx);
  }
  // Otherwise, the right child is smaller than the left child so return the right child
  return rightChild(currentIdx);
}


void Heap::heapifyDown(size_t currentIdx){
  // Checks if the node is not a leaf node
  if (hasAChild(currentIdx)){
    // Check if the node has a right child (don't need to check left since hasAChild ensures it has a left)
    if (rightChild(currentIdx) > size_){
      // If it doesn't have one, only need to check if current node is greater than left child
      if (higherPriority(_elems[leftChild(currentIdx)], _elems[currentIdx])){
        // If the left child is less than current node, swap them
        std::swap(_elems[currentIdx], _elems[leftChild(currentIdx)]);
        // Then recursively heapifyDown until leaf node
        heapifyDown(leftChild(currentIdx));
      }
    }else{
      // If the node has both children, find the smaller child
      size_t priority = maxPriorityChild(currentIdx);
      // Check if the current node is greater than smallest child
      if (higherPriority(_elems[priority], _elems[currentIdx])){
        // If it is, swap them
        std::swap(_elems[currentIdx], _elems[priority]);
        // Recursively heapifyDown until leaf node
        heapifyDown(priority);
      }
    }
  }
}


void Heap::heapifyUp(size_t currentIdx){
  // Stops at root
  if (currentIdx == root())
      return;
  size_t parentIdx = parent(currentIdx);
  // Check if current node is smaller than parent
  if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
    // If it is, swap and continue heapifyUp
      std::swap(_elems[currentIdx], _elems[parentIdx]);
      heapifyUp(parentIdx);
  }
}

Heap::Heap(){
  // Sets the number of elements to 0 since empty
  size_ = 0;
  Graph::Airport filler;
  // Fill 0-th index with an invalid airport
  _elems.push_back(filler);
}

Heap::Heap(const std::vector<Graph::Airport>& airports){
  Graph::Airport filler;
  // Fill 0-th index with an invalid airport
  _elems.push_back(filler);
  size_ = 0;
  for (unsigned i = 0; i < airports.size(); i++){
    // Checks if the airport is valid
    if (airports[i].id != 0){
      // Insert every element into the vector; they will be shifted over by one due to
      // the 0-th index being filled with a default constructed data
      _elems.push_back(airports[i]);
      size_++;
    }
  }
  for (unsigned i = parent(size_); i > 0; i--){
    heapifyDown(i);
  }
}

Graph::Airport Heap::pop(){
  // If the heap is empty, return invalid airport
  if (empty()){
    Graph::Airport filler;
    return filler;
  }
  // Get the smallest value, which is at the 1st index
  Graph::Airport minValue = _elems[1];
  // Swap with the last unremoved element
  _elems[1] = _elems[size_];
  // Remove it by reducing the number of unremoved elements
  size_--;
  // Restore the heap property
  heapifyDown(1);
  // Return the min value
  return minValue;
}


Graph::Airport Heap::peek() const{
  // If the heap is not empty, return the 1st element
  if (!empty()){
    return _elems[1];
  }
  // Else return invalid airport
  Graph::Airport filler;
  return filler;
}


void Heap::push(const Graph::Airport & airport){
  // Add it to the end of the heap
  _elems.push_back(airport);
  // Increase the number of unremoved elements
  size_++;
  // Restore heap property
  heapifyUp(size_);
}

void Heap::updateElem(const Graph::Airport & airport){
  // Find the index of the airport
  int idx = -1;
  for (size_t i = 1; i < size_+1; i++){
    if (_elems[i].id == airport.id){
      idx = i;
      break;
    }
  }
  // If can't find it, done
  if (idx == -1){
    return;
  }
  // Corrects the heap to remain as a valid heap even after update
  size_t currentIdx = idx;
  // Make a copy of the previous element
  Graph::Airport tmp = _elems[currentIdx];
  // Update the distance and heuristic to the new one
  _elems[currentIdx].distance = airport.distance;
  _elems[currentIdx].heuristic = airport.heuristic;
  // If the new element is larger than the previous one, need to heapify down
  if (higherPriority(tmp, airport)){
    heapifyDown(currentIdx);
  }else if (higherPriority(airport, tmp)){
    // If it is smaller than the previous one, need to heapify up
    heapifyUp(currentIdx);
  }
}

bool Heap::empty() const{
  // If there are no unremoved elements, it is empty
  if (size_ == 0){
    return true;
  }
  return false;
}

void Heap::getElems(std::vector<Graph::Airport> & heaped) const{
  for (size_t i = root(); i < _elems.size(); i++) {
      heaped.push_back(_elems[i]);
  }
}

Graph::Airport Heap::exists(const Graph::Airport & airport){
  // Find the index of the airport
  int idx = -1;
  for (size_t i = 1; i < size_+1; i++){
    if (_elems[i].id == airport.id){
      idx = i;
      break;
    }
  }
  Graph::Airport retVal = Graph::Airport();
  // If can't find it, done
  if (idx == -1){
    return retVal;
  }
  retVal = _elems[idx];
  return retVal;
}
