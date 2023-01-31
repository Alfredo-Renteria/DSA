/*
Alfredo Renteria
Filename: IntMinHeap.cpp
Implementation of the Int Min Heap class
Code Status: Working/Tested
*/

#include <algorithm>
#include <iostream>
#include <string>
#include "IntMinHeap.h"

/**
 * Constructor
 * 
 * Constructs a new Int Min Heap object with input capacity
 * 
 * @param cap int value that is the max. possible heap size
 */
IntMinHeap::IntMinHeap(int cap) {
  heapSize = 0;
  capacity = cap;
  A = new int[capacity];
}

/**
 * Destructor
 * 
 * Destroys the Int Min Heap object
 */
IntMinHeap::~IntMinHeap() {
  delete[] A;
}

/**
 * Heap sort
 * 
 * Sorts the heap represented by A
 */
void IntMinHeap::heapSort() {
  //Build min heap
  buildHeap();

  //Make copy of size of data in the heap
  int heapSizeTemp = heapSize;
  
  //Sort from leaves to root
  for (int i = heapSize-1; i > 0; i--) {
    //Swap first elem. with curr. index elem.
    std::swap(A[0], A[i]);
    //Reduce temp size
    heapSize--;
    //Heapify on root
    heapify(0);
  }

  //Return to original size of data in the heap
  heapSize = heapSizeTemp;
}

/**
 * Insert input key value
 * 
 * Returns whether insertion of input key value into the heap was successful
 * 
 * @param key int that is the value to be inserted into the heap
 * @return true -- key value was inserted successfully
 * @return false -- insertion of key value was unsuccessful; heap is full
 */
bool IntMinHeap::insertKey(int key) {
  //Heap is at full capacity -- return false
  if (heapSize == capacity) {
    return false;
  }
  //At current heap size position insert value of incremented key 
  A[heapSize] = key + 1;
  //Increment size of data in the heap
  heapSize++;
  //Decrease key on inserted key value
  decreasekey(heapSize-1, key);

  //Succesfful insert -- return true
  return true;
}

/**
 * Minimum value
 * 
 * Returns the minimum value of the heap
 * 
 * @return int that is the min. value of the heap; 0 on empty heap
 */
int IntMinHeap::getMin() {
  //Heap is empty -- return 0
  if (empty()) {
    return 0;
  }
  //Return A[root]
  return A[0];
}

/**
 * Extract minimum value
 * 
 * Returns the removed minimum value of the heap
 * 
 * @return int that is the min. value of the heap; 0 on empty heap
 */
int IntMinHeap::extractMin() {
  //Heap is empty -- return 0
  if (empty()) {
    return 0;
  }
  
  //Get the min. value
  int min = A[0];
  //Replace min. value
  A[0] = A[heapSize-1];
  //Decrement size of data in the heap
  heapSize--;
  //Heapify at root
  heapify(0);
  
  //Return extracted min.
  return min;
}

/**
 * Decrease input key value
 * 
 * If the decreased key value is less than the parent value, the minimum heap property has been violated
 * In order to fix the violation, we have to traverse up
 * This function helps preserves the minimum heap property on key value insertions
 * 
 * @param i int that is the index position of the input key value in A
 * @param key int that is the value to be inserted into the heap
 */
void IntMinHeap::decreasekey(int i, int key) {
  //Ensures index is in bounds and key was previously incremented
  if (i >= heapSize || A[i] <= key) {
    return;
  }
  
  //Decrease key
  A[i] = key;
  
  //Preserve heap property; parent value is > current index value
  while (i > 0 && A[parent(i)] > A[i]) {
    //Swap values
    std::swap(A[i], A[parent(i)]);
    //Update index
    i = parent(i);
  }
}

/**
 * Empty
 * 
 * Checks if the heap is empty
 * 
 * @return true -- the heap is empty
 * @return false -- the heap is not empty
 */
bool IntMinHeap::empty() {
  return heapSize == 0;
}

/**
 * Print the heap
 * 
 * Prints the contents of the heap from A[heapsize-1] to A[root]
 */
void IntMinHeap::printHeap() {
  for (int i = heapSize-1; i >= 1; i--) {
    std::cout << A[i] << std::endl;
  }

  std::cout << A[0] << std::endl;
}

/**
 * Minimum of 3 values
 * 
 * Returns the index of the minimum value between A[i], A[l], and A[r]
 * 
 * @param i int that is an index position in A
 * @param left int that is an index position in A
 * @param right int that is an index position in A
 * @return int that is the index position of the min. elem. amongst elems at input indices
 */
int IntMinHeap::minOf3(int i, int left, int right) {
  //Initialize min index with input index
  int minIndex = i;

  //Left is smaller
  if (left < heapSize && A[left] < A[minIndex]){
    minIndex = left;
  }
  //Right is smaller
  if (right < heapSize && A[right] < A[minIndex]){
    minIndex = right;
  }

  return minIndex;
}

/**
 * Left child index
 * 
 * Returns the left child index of the input index
 * 
 * @param i int that is an index position in A
 * @return int that is the left child index of the input index
 */
int IntMinHeap::left(int i) {
  return i * 2 + 1;
}

/**
 * Right child index
 * 
 * Returns the right child index of the input index
 * 
 * @param i int that is an index position in A
 * @return int that is the right child index of the input index
 */
int IntMinHeap::right(int i) {
  return i * 2 + 2;
}

/**
 * Parent index
 * 
 * Returns the parent index of the input index
 * 
 * @param i int that is an index position in A
 * @return int that is the parent index of the input index
 */
int IntMinHeap::parent(int i) {
  return (i - 1) / 2;
}

/**
 * Build the heap
 * 
 * Builds a minimum heap from A
 */
void IntMinHeap::buildHeap() {
  //Perform reverse level order traversal from last non-leaf key value to root
  //And heapify each key value
  for (int i = (heapSize-2)/2; i >= 0; i--) {
    heapify(i);
  }
}

/**
 * Heapify
 * 
 * Heapify subtree recursively with the root at the given index
 * This method assumes that the subtress are already heapified
 * 
 * @param i int that is an index position in A
 */
void IntMinHeap::heapify(int i) { 
  //Get the index of the min. elem.
  int minIndex = minOf3(i, left(i), right(i));
  
  //If the min. index is not the input index
  if (minIndex != i) {
    //Swap the elements
    std::swap(A[i], A[minIndex]);
    //Heapify rescursively on the min. index
    heapify(minIndex);
  }
}