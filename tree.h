#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <string>

class BinarySearchTree {
  private:
    // void incrementNode(Node *&nodePtr) {
    //   nodePtr->count += 1;
    // }

  public:
    BinarySearchTree() {
      root = nullptr;
    };

    Node *root;

    Node * getRoot() {
      return root;
    }

    static Node * buildTree(string file);
    static void printPreorder(Node *rootP, int level);
    static void printInorder(Node *rootP, int level);
    static void printPostorder(Node *rootP, int level);

    // void addNode(string newString);
    // void insertNode(Node *root, Node newNode);
    // void searchNode(string newString);
};

#endif