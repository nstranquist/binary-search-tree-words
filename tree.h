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

  private:
    Node *createNode(string key, string word);
    Node *searchNode(string word); // should return string maybe?
    void addNode(string word);
    void insertNode(string word);

    void addWordToNode(Node temp, string word);
    string getCharKey(string word);
};


#endif