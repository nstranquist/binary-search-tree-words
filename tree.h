#ifndef TREE_H
#define TREE_H

#include "node.h"

using namespace std;

class BinarySearchTree {
  public:
    BinarySearchTree();

    Node *buildTree(istream *input);
    Node *buildTreeV1(string file);

    void printPreorder(Node *rootPtr, int level);
    void printInorder(Node *rootP, int level);
    void printPostorder(Node *rootP, int level);

  private:
    Node *root;

    Node *createNode(string key, string word);
    Node *searchNode(string word); // should return string maybe?
    void insertNode(string key, string word);

    void addWordToNode(Node *temp, string word);
    void splitByDelimiter(string delimiter, string line);
    void handleNewNode (string key, string line);
    string getCharKey(string word);
};

#endif