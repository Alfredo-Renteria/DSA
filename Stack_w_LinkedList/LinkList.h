/**
* Alfredo Renteria
* Filename: LinkList.h
* Interface of the Link List template class
* Code Status: Working/Tested
*/

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

/**
* Implementation of a generic singly linked list
* 
* The linked list is designed to operate with the use of nodes, in the singly list context.
* The list is managed by head and tail pointers, which oversee the front and end of the list respectively.
* The linked list has six functions, 'empty', 'front', 'insertFront', 'removeFront', 'clear', and 'print'.
* As elements are inserted and extracted only from one end of the container; the front of the list.
*/

template <typename T>
class LinkList {
public:
  //Default constructor
  LinkList();
  //Destructor
  ~LinkList();
  //Returns true if list is empty; false if not empty
  bool empty();
  //Returns reference to data at the front of the list
  T &front();
  //Insert data into the front of the list
  void insertFront(T);
  //Returns removed data from the front of the list
  T removeFront();
  //Clear the list
  void clear();
  //Print the list
  void print();
  
private:
  //Link node structure
  struct LinkNode {
    //Pointer to next node
    LinkNode *next;
    //Data that the node holds
    T data;
  };
  //Pointer to head node
  LinkNode *head;
  //Pointer to tail node
  LinkNode *tail;
  //Size of the list
  int size;
};

//To prevent link error
#include "LinkList.cpp"

#endif