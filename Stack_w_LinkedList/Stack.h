/**
* Alfredo Renteria
* Filename: Stack.h
* Interface of the Stack class
* Code Status: Working/Tested
*/

#ifndef STACK_H
#define STACK_H

#include <string>
#include "LinkList.h"

/**
* Implementation of a stack using a singly linked list
* 
* The stack is designed to operate in the LIFO(Last In First Out) context.
* The underlying container for the stack, is a singly linked list class called 'LinkList'.
* The stack has three functions, 'empty', 'push', and 'pop'.
* As elements are inserted and extracted only from one end of the container; the top of the stack.
*/

class Stack{
public:
  //Returns true if stack is empty; false if not empty
  bool empty();
  //Pushes string to the top of the stack
  void push(std::string);
  //Returns popped string from the top of the stack 
  std::string pop();

private:
  //Underlying container for stack, a singly linked list
  LinkList<std::string> List;
};

#endif