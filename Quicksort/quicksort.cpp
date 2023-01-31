/*
Alfredo Renteria
Filename: quicksort.cpp
Main function and implementation of Quicksort
Using Lomuto & Hoare partition schemes with median of 3 technique
Also employs std::sort() for comparison purposes
Code Status: Working/Tested
*/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

const int MEDIANTRIGGER = 1000;

//Quicksort for lomuto technique
void quicksort(std::vector<int> &, int, int);
//Quicksort for hoare technique
void hoareQuicksort(std::vector<int> &, int, int);
//Lomuto partition scheme
inline int partition(std::vector<int> &, int, int);
//Hoare partition scheme
inline int hoarePartition(std::vector<int> &, int, int);
//Median of 3 values
inline int medianOf3(std::vector<int> &, int, int);

int main(int argc, char *argv[]) {
  //Flag for whether Hoare partition scheme is selected
  bool hoareMode = false;
  bool stlMode = false;

  //Invalid arguments --Error
  if (argc > 2) {
    std::cerr << "Quicksort: For Lomuto partition scheme no argument is needed." << std::endl;
    std::cerr << "Quicksort: Try '-h' for Hoare partition scheme." << std::endl;
    std::cerr << "Quicksort: Try '-s' for Standard Template Library sort()." << std::endl;

    exit(EXIT_FAILURE);

  //Argument count may be for Hoare / STL selection
  } else if (argc == 2) {
    //Store argument in string
    std::string cmd = argv[1];
    
    //Check if command is valid for Hoare partition scheme
    if (cmd == "-h") {
      std::cout << "Hoare partition scheme:" << std::endl;
      hoareMode = true;

    //for Standard Template Library sort
    } else if (cmd == "-s") {
      std::cout << "STL sort:" << std::endl;
      stlMode = true;
    
    //Command is invalid --Error
    } else {
      std::cerr << "Quicksort: Did you mean '-h' for Hoare partition scheme?" << std::endl;
      std::cerr << "Quicksort: Did you mean '-s' for Standard Template Library sort?" << std::endl;
      exit(EXIT_FAILURE);
    }

  //Else, run Lomuto
  } else {
    std::cout << "Lomuto partition scheme:" << std::endl;
  }

  //For storing input values
  std::vector<int> inputVals;
  //To assist with storing input values
  int userInput;
  
  while (std::cin >> userInput) {
    inputVals.push_back(userInput);
  }
  
  //Size of input
  int n = inputVals.size();
  
  //Run the requested quicksort technique
  if (hoareMode) {
    hoareQuicksort(inputVals, 0, n - 1);
  } else if (stlMode) {
    std::sort(inputVals.begin(), inputVals.end());
  } else {
    quicksort(inputVals, 0, n - 1);
  }

  //Print sorted values to STDOUT
  for (const auto& n : inputVals) {
    std::cout << std::setfill('0') << std::setw(9) << n << std::endl;
  }

  exit(EXIT_SUCCESS);
}

/**
 * Quicksort function for lomuto technique
 * 
 * Divide and conquer algorithm.
 * Calls partition() to get pivot index then sub-vectors are sorted recursively
 * 
 * @param A std::vector<int>& that needs to be sorted
 * @param lo int value that represents an index in A
 * @param hi int value that represents an index in A
 */
void quicksort(std::vector<int>& A, int lo, int hi) {
  if (lo >= hi || lo < 0) {
    return;
  }
  //Partition vector & get the pivot index
  int pivot = partition(A, lo, hi);
  //Left side of pivot
  quicksort(A, lo, pivot - 1);
  //Right side of pivot
  quicksort(A, pivot + 1, hi);
}

/**
 * Quicksort function for hoare technique
 * 
 * @param A std::vector<int>& that needs to be sorted
 * @param lo int value that represents an index in A
 * @param hi int value that represents an index in A
 */
void hoareQuicksort(std::vector<int>& A, int lo, int hi) {
  if (lo >= hi || lo < 0) {
    return;
  }
  //if (lo < hi) {
  int splitr = hoarePartition(A, lo, hi);
    
  hoareQuicksort(A, lo, splitr);
    
  hoareQuicksort(A, splitr + 1, hi);
  //}
}

/**
 * Lomuto partition scheme
 * 
 * Returns pivot element from the input vector
 * 
 * @param A std::vector<int>& that needs to be partitioned for sorting
 * @param lo int value that represents an index in A
 * @param hi int value that represents an index in A
 * @return int that is the partition point of the input vector
 */
int partition(std::vector<int>& A, int lo, int hi) {
  const int n = A.size();
  
  if (n > MEDIANTRIGGER) {
    int medOfThree = medianOf3(A, lo, hi);
    //Swap median of 3 pivot elem. & last elem.
    std::swap(A[medOfThree], A[hi]);
  }

  //The pivot is the last element in the vector
  int pivot = A[hi];

  //Return variable for new pivot index
  int i = lo - 1;
  //For looping vector to find new pivot
  int j = lo;

  while (j < hi) {
    //Curr. elem. is <= to the pivot
    if (A[j] <= pivot) {
      //Move new pivot up
      i++;
      //Swap the pivot elem. & curr. elem.
      std::swap(A[i], A[j]);
    }
    j++;
  }
  //Move new pivot index up
  i++;
  //Swap the pivot elem. & last elem.
  std::swap(A[i], A[hi]);
  
  //Return pivot index
  return i;
}

/**
 * Hoare partition scheme
 * 
 * @param A std::vector<int>& that needs to be partitioned for sorting
 * @param lo int value that represents an index in A
 * @param hi int value that represents an index in A
 * @return int that is the partition point of the input vector
 */
int hoarePartition(std::vector<int>& A, int lo, int hi) {
  const int n = A.size();
  
  if (n > MEDIANTRIGGER) {
    int medOfThree = medianOf3(A, lo, hi);
    //Swap median of 3 pivot value & A[lo]
    std::swap(A[lo], A[medOfThree]);
  }

  //The pivot is the first element in the vector
  int pivot = A[lo];
  //Left index
  int i = lo - 1;
  //Right index
  int j = hi + 1;
  
  //Loop forever
  while (true) {
    //While left index elem. is < pivot elem.
    //Move left index up
    do {
      i++;
    } while (A[i] < pivot);
    //While right index elem. is > pivot elem.
    //Move right index down
    do {
      j--;
    } while (A[j] > pivot);
 
    //Indices crossed
    if (i >= j) {
      //Return right index
      return j;
    }
    //Swap the left elem. & right elem.
    std::swap(A[i], A[j]);
  }
}

/**
 * Median of 3 values
 * 
 * Returns the middle of the values between input lo, input hi and the derived mid
 * This index serves as a pivot index for the partition function
 * 
 * @param A std::vector<int>& that holds elements that low, mid, and high indices access
 * @param lo int value that represents an index in A
 * @param hi int value that represents an index in A
 * @return int that is the index of the median element
 */
int medianOf3(std::vector<int>& A, int lo, int hi) {
  int mid = lo + (hi - lo) / 2;

  if ((A[lo] < A[hi] && A[hi] < A[mid]) ||
      (A[mid] < A[hi] && A[hi] < A[lo])) {  
        mid = hi;
  } else if ((A[hi] < A[lo] && A[lo] < A[mid]) || 
      (A[mid] < A[lo] && A[lo] < A[hi])) {
        mid = lo;
  }

  //Return pivot 
  return mid;
}