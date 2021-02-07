#ifndef TREE_H
#define TREE_H

#include "node.h"

using namespace std;

#include <string>

class Tree {
  public:
    Tree();
    static nodeType buildTree(string file);
    static void printPreorder(nodeType *rootP, int level);
    static void printInorder(nodeType *rootP, int level);
    static void printPostorder(nodeType *rootP, int level);
};

#endif