/**
* Alfredo Renteria
* Filename: Stack.cpp
* Implementation of the Stack class
* Code Status: Working/Tested
*/

#include <string>
#include "Stack.h"
#include "LinkList.h"

/**
 * Empty
 * 
 * Checks if the stack is empty
 * 
 * @return true -- stack is empty
 * @return false -- stack is not empty
 */
bool Stack::empty() {
    return List.empty();
}

/**
 * Push
 * 
 * Inserts data to the top the stack
 * 
 * @param data std::string value to be added to the stack
 */
void Stack::push(std::string data) {
    List.insertFront(data);
}

/**
 * Pop
 * 
 * Returns the removed data string from the top of the stack
 * 
 * @return std::string value that is being removed from the stack
 */
std::string Stack::pop() {
    if (empty()) {
        std::cout << "Error: Stack empty(): Cannot pop.\n";
        return std::string();
    }

    return List.removeFront();
}