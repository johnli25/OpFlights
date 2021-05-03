#pragma once
#include <vector>
#include "Airports.h"

class Heap
{
  public:
    // Constructs an empty heap
    Heap();

    // Constructs a heap of airports that are sorted based on the distance from starting airport
    // Copies the airports from vector of airports into the heap's storage and then running the buildHeap
    // algorithm.
    // Note, it will ignore any empty slots in the vector table (any airports with id 0)
    // @param airports The airports that should be placed in the heap.
    Heap(const std::vector<Airports::Airport>& airports);

    // Removes the airport with highest priority
    // @return The airport with highest priority (lowest distance from starting airport) in the heap.
    Airports::Airport pop();

    // Returns, but does not remove, the airport with highest priority.
    // @return The highest priority airport in the entire heap.
    Airports::Airport peek() const;

    // Inserts the given airport into the heap, restoring the heap
    // property after the insert as appropriate.
    // It will ignore any invalid airports (any airports with id 0)
    // @param airport The airport to be inserted.
    void push(const Airports::Airport & airport);

    // Updates the element at the provided index of the heap array.
    // The update is done in such a way that the array will be
    // corrected, so it will remain as a valid heap.
    // @param idx The index of the element to be updated
    // (This is root()-indexed, so will work if
    // using either zero or one-indexed heaps)
    // @param airport The airport to be updated with.
    void updateElem(const size_t & idx, const Airports::Airport & airport);

    // Determines if the given heap is empty.
    // @return Whether or not there are airports in the heap.
    bool empty() const;

    // Gets the vector of airports
    void getElems(std::vector<Airports::Airport> & heaped) const;

    // Helper function that returns the root index of this heap.
    // @return The index of the root node of the heap.
    size_t root() const;

  private:
    // Holds the number of unremoved airports
    size_t size_;

    // The internal storage for this heap
    std::vector<Airports::Airport> _elems;

    // Determines which airport has the least distance from starting airport
    // In the case of ties, the first argument has the least distance
    // Returns true if the first argument has less or equal distance than the second argument
    // Returns false if the first argument has greater distance than the second argument
    // @param two airports that you want to compare
    // @return true if airport1 has higher priority than airport2
    bool higherPriority(const Airports::Airport & airport1, const Airports::Airport & airport2) const;

    // Helper function that returns the index of the left child of a
    // node in the heap.
    // @param currentIdx The index of the current node.
    // @return The index of the left child of the current node.
    size_t leftChild(size_t currentIdx) const;

    // Helper function that returns the index of the right child of a
    // node in the heap.
    // @param currentIdx The index of the current node.
    // @return The index of the right child of the current node.
    size_t rightChild(size_t currentIdx) const;

    // Helper function that returns the index of the parent of a node
    // in the heap.
    // @param currentIdx The index of the current node.
    // @return The index of the parent of the current node.
    size_t parent(size_t currentIdx) const;

    // Helper function that determines whether a given node has a
    // child.
    // @param currentIdx The index of the current node.
    // @return A boolean indicating whether the current node has a
    //  child or not.
    bool hasAChild(size_t currentIdx) const;

    // Helper function that returns the index of the child with the
    // highest priority
    // @param currentIdx The index of the current node.
    // @return The index of the highest priority child of this node.
    size_t maxPriorityChild(size_t currentIdx) const;

    // Helper function that restores the heap property by sinking a
    // node down the tree as necessary.
    // @param currentIdx The index of the current node that is being
    //  sunk down the tree.
    void heapifyDown(size_t currentIdx);

    // Helper function that restores the heap property by bubbling a
    // node up the tree as necessary.
    // @param currentIdx The index of the current node that is being
    //  bubbled up the tree.
    void heapifyUp(size_t currentIdx);
};
