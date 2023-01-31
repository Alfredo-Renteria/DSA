/**
* Alfredo Renteria
* Filename: LinkList.cpp
* Implementation of the Link List template class
* Code Status: Working/Tested
*/

#include "LinkList.h"

/**
 * Default constructor
 * 
 * Constructs a new LinkList object
 */
template <typename T>
LinkList<T>::LinkList() {
  head = nullptr;
  tail = nullptr;
  size = 0;
}

/**
 * Destructor
 * 
 * Destroys the LinkList object
 */
template <typename T>
LinkList<T>::~LinkList() {
  //Clear the list
  clear();
}

/**
 * Empty 
 * 
 * Checks if the list is empty
 * 
 * @return true - list is empty 
 * @return false - " " not empty
 */
template <typename T>
bool LinkList<T>::empty() {
  //head == nullptr
  return !head;
}

/**
 * Data at the front
 * 
 * Returns reference to data at the front of the list
 * 
 * @return T& value that is the front node's data value
 */
template <typename T>
T& LinkList<T>::front() {
  return head->data;
}

/**
 * Insert at the front
 * 
 * Pushes a new node at the front of the list
 * 
 * @param newData T value to be inserted into the list
 */
template <typename T>
void LinkList<T>::insertFront(T newData) {
  //Create new node
  LinkNode* node = new LinkNode;
  //Insert data into new node
  node->data = newData;
  //First node in an empty list
  if (empty()) {
    head = tail = node;
  //There are other nodes, readjust the front of the list
  } else {
    node->next = head;
    head = node;
  }
  //Increase the size of the list
  size++;
}

/**
 * Remove from the front
 * 
 * Pops node from the front of the list and returns its value
 * 
 * @return T value from node being removed the list
 */
template <typename T>
T LinkList<T>::removeFront() {
  if (empty()) {
    //Print error message
    std::cout << "Error: LinkList empty(): Cannot removeFront().\n";
    //Return empty T value
    return T();
  }
  //Get data value from the front of the list
  T delData = front();
  //Reduce the size of the list
  size--;
  //Only one node in the list
  if (head == tail) {
    //Remove the node
    delete head;
    //Reset list node ptrs.
    head = tail = nullptr;
  //More than one node in the list
  } else {
    //Node to be deleted points at head
    LinkNode* delNode = head;
    //Head moves forward
    head = head->next;  
    //Remove the node
    delete delNode; 
  }
  //Return value of removed node
  return delData;
}

/**
 * Clear the list
 * 
 * Removes all nodes from the list
 */
template <typename T>
void LinkList<T>::clear() {
  if (!empty()) {
    //Use size to remove nodes from the front
    while (size > 0) {
      removeFront();
      size--;
    }
  }
}

/**
 * Print the list
 * 
 * Prints all node values starting from the front of the list
 */
template<typename T>
void LinkList<T>::print() {
  if (empty()) {
    std::cout << "Error: LinkList empty(): Cannot print().\n";
    return;
  } else {
    LinkNode* node = head;
    while (node) {
      std::cout << node->data << " ";
      node = node->next;
    }
    std::cout << std::endl;
  }
}