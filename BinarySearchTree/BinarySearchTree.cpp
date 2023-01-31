/*
Alfredo Renteria
Filename: BinarySearchTree.cpp
Implementation of the Binary Search Tree class
Code Status: Working/Tested
*/

#include <iostream>
#include "BinarySearchTree.h"

/**
 * Default constructor
 * 
 * Constructs a new BinarySearchTree object
 */
BinarySearchTree::BinarySearchTree() {
  root = nullptr;
}

/**
 * Destructor
 * 
 * Destroys the BinarySearchTree object
 */
BinarySearchTree::~BinarySearchTree() {
  clear(root);
}

/**
 * Search for a value
 * 
 * Returns whether the search operation of the input value in the binary search tree was successful
 * 
 * @param value int value to search for in the BST
 * @return true - node is found
 * @return false - node is not found
 */
bool BinarySearchTree::search(int value) {
  Node* found = search(root, value);
  
  //found != nullptr;
  return found;
}

/**
 * Insert a value
 * 
 * Adds node with input value into the binary search tree
 * 
 * @param value int value to be inserted in the BST
 */
void BinarySearchTree::insert(int value) {
  Node* newNode = new Node(value);
  
  insert(newNode);
}

/**
 * Remove a value
 * 
 * Returns whether the deletion operation of the input value from the binary search tree was successful
 * 
 * @param value int value to be deleted from the BST
 * @return true - value was deleted
 * @return false - value was not found
 * 
 */
bool BinarySearchTree::remove(int value) {
  Node* found = search(root, value);
  
  if (!found) {
    return false;
  }
  
  remove(found);
  
  return true;
} 

/**
 * Minimum value
 * 
 * Returns pointer to the minimum value in the binary search tree
 * 
 * @return int* that points to the min. value
 */
int* BinarySearchTree::min() {
  Node* minNode = min(root);
  
  if (!minNode) {
    return nullptr;
  }

  return &(minNode->data);
}

/**
 * Maximum value
 * 
 * Returns pointer to the maximum value in the binary search tree
 * 
 * @return int* that points to the max. value
 */
int* BinarySearchTree::max() {
  Node* maxNode = max(root);
  
  if (!maxNode) {
    return nullptr;
  }

  return &(maxNode->data);
}

/**
 * Predecessor's value
 * 
 * Returns pointer to the predecessor's value of the input value
 * 
 * @param value int value to find the predecessor of 
 * @return int* that points to the predecessor's value
 */
int* BinarySearchTree::predecessor(int value) {
  //To find predecessor of value, 1st we search for value in the BST
  Node* found = search(root, value);
  //Search was a failure
  if (!found) {
    return nullptr;
  }

  //Call predecessor to return node
  found = predecessor(found);
  
  //Value is root case
  if (!found) {
    return nullptr;
  }

  //Return predecessor value
  return &(found->data);
}

/**
 * Successor's value
 * 
 * Returns pointer to the successor's value of the input value
 * 
 * @param value int value to find the successor of 
 * @return int* that points to the successor's value
 */
int* BinarySearchTree::successor(int value) {
  Node* found = search(root, value);
  
  if (!found) { 
    return nullptr;
  }

  found = successor(found);
  
  if (!found) {
    return nullptr;
  }
  
  return &(found->data);
}

/**
 * Inorder traversal from root
 * 
 * Traverses the BST inorder: left, node, right
 */
void BinarySearchTree::inorder() {
  inorder(root);
}

/**
 * Preorder traversal from root
 * 
 * Traverses the BST preorder: node, left, right
 */
void BinarySearchTree::preorder() {
  preorder(root);
}

/**
 * Postorder traversal from root
 * 
 * Traverses the BST postorder: left, right, node
 */
void BinarySearchTree::postorder() {
  postorder(root);
}

/**
 * Search for a value from a node
 * 
 * Searches the binary search tree for the node with input value in the subtree of the input node
 * When used with root node, all nodes in the BST are searched
 * 
 * @param node Node* that points at the node from where the search will commence
 * @param value int value to search for in the BST
 * @return Node* that points at the searched node if found, nullptr if not found
 */
Node* BinarySearchTree::search(Node* node, int value) {
  if (!node) {
    return nullptr;
  //Value was found in the BST
  } else if (value == node->data) {
    return node;
  }

  //Value is smaller than curr. node's value
  if (value < node->data) {
    //Inspect the left side
    return search(node->left, value);
  } else {
    //Else, the right side
    return search(node->right, value);
  }
}

/**
 * Insert a node
 * 
 * Adds a new node into the binary search tree
 * 
 * @param newNode Node* that points at the new node to be inserted in the BST
 */
void BinarySearchTree::insert(Node* newNode) {
  //If root is null, this is the first node in the BST
  if (!root) {
    root = newNode;
    return;
  }
  
  //Node pointer used to assist with finding new node's parent
  Node* parFinder = root;
  //Node pointer that will be assigned new node's parent
  Node* parent = nullptr;
  
  while (parFinder) {
    parent = parFinder;
    //If new node value is less than curr. parent's value 
    if (newNode->data < parFinder->data) {
      //Inspect left side
      parFinder = parFinder->left;
    } else {
      parFinder = parFinder->right;
    }
  }

  //Assign parenting role from child's view; new node
  newNode->parent = parent;

  //If new node value is less than parent's value
  if (newNode->data < parent->data) {
    //Assign parenting role from parent's view
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
}

/**
 * Remove a node
 * 
 * Removes input node from the binary search tree
 * 
 * @param node Node* that points at the node to be deleted from the BST
 */
void BinarySearchTree::remove(Node* node) {
  //Node pointer used to manage the target node to be removed
  Node* target = nullptr;

  //Node to be removed has two children
  if (node->left && node->right) {
    //Target points to the successor of the node to be removed
    target = successor(node);
    //The node to be removed now holds successor data
    node->data = target->data;
  //Else, node has no children, or only one, target points to the node to be removed
  } else {
    target = node;
  }

  //Node pointer used to assist with managing target node's children
  Node* trgChild = nullptr;

  //If target has a valid child
  if (target->left) {
    //Target child points to target's left child
    trgChild = target->left;
    //Reroute parenting role from child's view
    trgChild->parent = target->parent;
  } else if (target->right) {
    trgChild = target->right;
    trgChild->parent = target->parent;   
  }

  //Node pointer used to assist with managing target node's parent
  Node* trgPar = target->parent;
  
  //If target node's parent is null, target is currently at root
  if (!trgPar) {
    //Readjust the root node in the BST prior to removal
    root = trgChild;
  //Target is their parent's left child
  } else if (target == trgPar->left) {
    //Reroute parenting role from parent's view
    trgPar->left = trgChild;
  } else if (target == trgPar->right) {
    trgPar->right = trgChild;
  }

  //Remove the node
  delete target;  
}

/**
 * Minimum value node
 * 
 * Returns pointer to the node holding the minimum value from all the nodes in the subtree of the input node
 * When used with root node, min. value of the entire tree
 * 
 * @param node Node* that points at the node whose subtree will be searched for min. value
 * @return Node* that points at the node with the min. value
 */
Node* BinarySearchTree::min(Node* node) {
  if (!node) {
    return nullptr;
  }
  //Traverse from root to left children
  //The node who doesn't have a left child has the min. value
  while (node->left) {    
    node = node->left;
  }
  
  return node; 
}

/**
 * Maximum value node
 * 
 * Returns pointer to the node holding the maximum value from all the nodes in the subtree of the input node
 * When used with root node, max. value of the entire tree
 * 
 * @param node Node* that points at the node whose subtree will be searched for max. value
 * @return Node* that points at the node with max. value
 */
Node* BinarySearchTree::max(Node* node) {
  if (!node) {
    return nullptr;
  }
  //Traverse from root to right children
  //The node who doesn't have a right child has the max. value
  while (node->right) {
    node = node->right;
  }
  
  return node;
}

/**
 * Predecessor of node 
 * 
 * Returns pointer to the node that is the predecessor of the input node
 * 
 * @param node Node* that points at a node whose predecessor is requested
 * @return Node* that points at the node that is the predecessor of the input node
 */
Node* BinarySearchTree::predecessor(Node* node) {
  //Input node has a left child
  //The predecessor will be the max. value node within the left child's subtree
  if (node->left) {
    return max(node->left);
  //Input node doesn't have a left child
  //Check if it's parent is null like root's, root case
  } else if (node->parent == root->parent) {
    return nullptr;
  }
  
  //Set pointer to node's parent
  Node* par = node->parent;
  
  //Move up the tree to find predecessor
  while (par && par->left == node) {
    node = par;
    par = par->parent;  
  }
  
  return par;
}

/**
 * Successor of node
 * 
 * Returns pointer to the node that is the successor of the input node
 * 
 * @param node Node* that points at a node whose successor is requested
 * @return Node* that points at the node that is the successor of the input node 
 */
Node* BinarySearchTree::successor(Node* node) {
  //Input node has a right child
  //The successor will be the min. value node within the right child's subtree
  if (node->right) {
    return min(node->right);
  } else if (node->parent == root->parent) {
    return nullptr;
  }
  
  Node* par = node->parent;
  
  while (par && par->right == node) {
    node = par;
    par = par->parent;
  }   
  
  return par;
}

/**
 * Inorder from node
 * 
 * Given a valid input node, an inorder traversal occurs, printing values to STDOUT
 * 
 * @param node Node* that points to the start node of the traversal
 */
void BinarySearchTree::inorder(Node* node) {
  if (!node) {
    return;
  }
  
  inorder(node->left);
  
  std::cout << node->data << ' ';
  
  inorder(node->right);
}

/**
 * Preorder from node
 * 
 * Given a valid input node, a preorder traversal occurs, printing values to STDOUT
 * 
 * @param node Node* that points to the start node of the traversal
 */
void BinarySearchTree::preorder(Node* node) {
  if (!node) {
    return;
  }
  
  std::cout << node->data << ' ';
  
  preorder(node->left);
  
  preorder(node->right);
}

/**
 * Postorder from node
 * 
 * Given a valid input node, a postorder traversal occurs, printing values to STDOUT
 * 
 * @param node Node* that points to the start node traversal
 */
void BinarySearchTree::postorder(Node* node) {
  if (!node) {
    return;
  }
  
  postorder(node->left);
  
  postorder(node->right);
  
  std::cout << node->data << ' ';
}

/**
 * Clear the BST
 * 
 * Removes all nodes in the subtree of the input node (treated as root)
 * When used with root node, all nodes in the BST are removed
 * 
 * @param node Node* that points at the node whose subtree needs deletion
 */
void BinarySearchTree::clear(Node* node) {
  if (!node) {
    return;
  }
  //Clears recursively postorder: left, right, node
  clear(node->left);
  
  clear(node->right); 
  
  delete node;
}