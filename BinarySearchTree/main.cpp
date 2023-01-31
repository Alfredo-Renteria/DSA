/*
Alfredo Renteria
Filename: main.cpp
Main function that utilizes the Binary Search Tree class
Operations are controlled via STDIN, and executions are sent to STDOUT
Code Status: Working/Tested
*/

#include <iostream>
#include <sstream>
#include <string>
#include "BinarySearchTree.h"

int main() {  
  BinarySearchTree BST;  
  std::string input = "";
  std::stringstream ss;

  while (std::getline(std::cin, input)) {
    //Input is not empty
    if (!input.empty()) {
      //Clear stream contents and error states
      ss.str(std::string());
      ss.clear();

      //Input has'#'?
      std::string::size_type hash = input.find("#");
      if (hash != std::string::npos) {
        //Remove '#' from input
        input.erase(0, hash);
      }
      
      //Copy contents from input
      ss.str(input);
      
      //To store the option command from input
      std::string option = "";
      //For search, insert, delete, predecessor, & successor requests
      int value = 0;

      //Extract option from input stream
      ss >> option;

      //Option matches operation, call respective BST function
      /**
       * SEARCH
       * 
       */
      if (option == "search" && ss >> value) {
        if (!BST.search(value)) {
          std::cout << value << " not found." << std::endl;
        } else {
          std::cout << value << " found." << std::endl;
        }
      /**
       * INSERT
       * 
       */
      } else if (option == "insert" && ss >> value) {
        BST.insert(value);
        std::cout << "inserted " << value << "." << std::endl;
      /**
       * DELETE
       * 
       */
      } else if (option == "delete" && ss >> value) {
        if (BST.remove(value)){
          std::cout << "deleted " << value << "." << std::endl;
        } else {
          std::cout << "delete " << value << " - not found." << std::endl;
        }
      /**
       * MIN
       * 
       */
      } else if (option == "min") {
        if (!BST.min()) {
          std::cout << "tree is empty." << std::endl;
        } else {
          std::cout << "min is " << *BST.min() << "." << std::endl;
        }
      /**
       * MAX
       * 
       */
      } else if (option == "max") {
        if (!BST.max()){
          std::cout << "tree is empty." << std::endl;
        } else {
          std::cout << "max is " << *BST.max() << "." << std::endl;
        }   
      /**
       * PREDECESSOR
       * 
       */
      } else if (option == "predecessor" && ss >> value) {
        if (!BST.search(value)) {
          std::cout << value << " not in tree." << std::endl;
        } else {
          if (!BST.predecessor(value)) {
            std::cout << "no predecessor for " << value << "." << std::endl;
          } else {
            std::cout << value << " predecessor is " << *BST.predecessor(value) << "." << std::endl;
          }
        }
      /**
       * SUCCESSOR
       * 
       */
      } else if (option == "successor" && ss >> value) {
        if (!BST.search(value)) {
          std::cout << value << " not in tree." << std::endl;
        } else {
          if (!BST.successor(value)) {
            std::cout << "no successor for " << value << "." << std::endl;
          } else {
            std::cout << value << " successor is " << *BST.successor(value) << "." << std::endl;
          }
        }
      /**
       * INORDER
       * 
       */
      } else if (option == "inorder") {
        std::cout << "inorder traversal:" << std::endl;
        BST.inorder();
        std::cout << std::endl;
      /**
       * PREORDER
       * 
       */
      } else if (option == "preorder") {
        std::cout << "preorder traversal:" << std::endl;
        BST.preorder();
        std::cout << std::endl;
      /**
       * POSTORDER
       * 
       */
      } else if (option == "postorder") {
        std::cout << "postorder traversal:" << std::endl;
        BST.postorder();
        std::cout << std::endl;
      }
    } 
  }

  return 0;
}