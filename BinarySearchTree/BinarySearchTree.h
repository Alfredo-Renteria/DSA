/*
Alfredo Renteria
Filename: BinarySearchTree.h
Interface of the Binary Search Tree class
Code Status: Working/Tested
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

/**
* Implementation of a binary search tree
* 
* The binary search tree (BST) is designed to operate with the use of nodes, in the rooted binary tree context.
* Each node possesses a value that is greater than all the values from that node's left subtree.
* Yet this same value is less than all the values from that respective node's right subtree. 
* The BST has 10 functions, 'search', 'insert', 'remove', 'min', 'max, 'predecessor', 'successor', 
* 'inorder', 'preorder', and 'postorder' traversals.
*/

class BinarySearchTree;
class Node;

class BinarySearchTree {
public:
  //Default constructor
  BinarySearchTree();
  //Destructor
  ~BinarySearchTree();
  //Returns true if value is found; false if not found
  bool search(int);
  //Inserts value into the BST
  void insert(int);
  //Returns true if value is deleted; false if not found
  bool remove(int);
  //Returns a pointer to the minimum value in the BST
  int* min();
  //Returns a pointer to the maximum value in the BST
  int* max();
  //Returns a pointer to the predecessor of the node with value
  int* predecessor(int);
  //Returns a pointer to the successor of the node with value
  int* successor(int);
  //Inorder traversal; left, node, right
  void inorder();
  //Preorder traversal; node, left, right
  void preorder();
  //Postorder traversal; left, right, node
  void postorder();

private:
  //Returns a pointer to the node with value; null if not found
  Node* search(Node*, int);
  //Inserts node into the BST
  void insert(Node*);
  //Removes node from the BST
  void remove(Node*);
  //Returns a pointer to the node with the minimum value
  Node* min(Node*);
  //Returns a pointer to the node with the maximum value
  Node* max(Node*);
  //Returns a pointer to the predecessor of node
  Node* predecessor(Node*);
  //Returns a pointer to the successor of node
  Node* successor(Node*);
  //Inorder traversal from node
  void inorder(Node*);
  //Preorder traversal from node
  void preorder(Node*);
  //Postorder traversal from node
  void postorder(Node*);
  //Clear subtree from node
  void clear(Node*);
  //Pointer to root node
  Node* root;
};

class Node {
  friend class BinarySearchTree;
public:
  //Overlaoded constructor
  Node(int v) : left(nullptr), right(nullptr), parent(nullptr), data(v) {}

private:
  //Pointer to left child node
  Node* left;
  //Pointer to right child node
  Node* right;
  //Pointer to parent node
  Node* parent;
  //Data that the node holds
  int data;
};

#endif