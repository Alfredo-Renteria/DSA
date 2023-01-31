/*
Alfredo Renteria
Filename: main.cpp
Main function
Code Status: Working/Tested
*/

#include <iostream>
#include "IntMinHeap.h"

int main() {
  IntMinHeap minHeap(2500000);
  int userInput;

  while (std::cin >> userInput) {
    /**
     * INSERT
     * 
     */
    if (userInput > 0 && minHeap.insertKey(userInput)) {
      //std::cout << "insert: " << userInput << std::endl;
    /**
     * PRINT CURRENT STATE
     * 
     */
    } else if (userInput == 0) {
      minHeap.printHeap();
    /**
     * EXTRACT MIN
     * 
     */
    } else if (userInput == -1) {
      std::cout << "extract min: " << minHeap.extractMin() << std::endl;
    /**
     * HEAP SORT + PRINT
     * 
     */
    } else if (userInput == -2) {
      minHeap.heapSort();
      minHeap.printHeap();
    }
  }
  
  return 0;
}