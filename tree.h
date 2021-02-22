#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <string>

using namespace std;

class BinarySearchTree {
  public:
    BinarySearchTree();

    Node *root;

    Node *buildTree(string file);

    void printPreorder(Node *rootP, int level);
    void printInorder(Node *rootP, int level);
    void printPostorder(Node *rootP, int level);

    void addNode(string newString);
    void insertNode(Node *root, string word);
    void searchNode(string newString); // should return string maybe?
  private:
    int fakeData;
    // void incrementNode(Node *&nodePtr) {
    //   nodePtr->count += 1;
    // }
};

#endif