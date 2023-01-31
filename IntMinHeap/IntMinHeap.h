/*
Alfredo Renteria
Filename: IntMinHeap.h
Interface of the Int Min Heap class
Code Status: Working/Tested
*/

#ifndef INTMINHEAP_H
#define INTMINHEAP_H

#include <string>

/**
* Implementation of an int minimum heap with priority queue
* 
* The created heap is zero-based, where A[0] is the root and minimum value.
* 
*/

class IntMinHeap{
public:
  //Constructor
  IntMinHeap(int);
  //Destructor
  ~IntMinHeap();
  //Sorts the heap
  void heapSort();
  //Returns true if value is inserted into the heap; false if the heap is full
  bool insertKey(int);
  //Returns the minimum value of the heap
  int getMin();
  //Returns the removed minimum value of the heap
  int extractMin();
  //Decreases the value of the input key at the input index
  void decreasekey(int, int);
  //Returns true if the heap is empty; false if not empty
  bool empty();
  //Prints the heap values to STDOUT
  void printHeap();

private:
  //Returns the index of the minimum element amongst the elements of the 3 input indices
  int minOf3(int, int, int);
  //Returns the left child index of the input index
  int left(int);
  //Returns the right child index of the input index
  int right(int);
  //Returns the parent index of the input index
  int parent(int);
  //Converts array to a heap
  void buildHeap();
  //Heapify at position of the input index
  void heapify(int);
  //Pointer to array of integers in the heap
  int* A;
  //Max size of the heap
  int capacity;
  //Size of data in the heap
  int heapSize;
};

#endif