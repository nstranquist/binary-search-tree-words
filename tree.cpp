// This will include code for:
// 1. buildTree()
// 2. printInorder()
// 3. printPreorder()
// 4. printPostorder()

#include "tree.h"
#include "node.h"

#include <stdio.h>
#include <fstream>
#include <iostream> // cout, etc.
#include <string>

using namespace std;

static nodeType buildTree(string file) {
  // read file contents
  cout << file << endl;

  nodeType node_type = nodeType();

  // returns a tree?
  return node_type;
}

// process root, process children left to right
static void printPreorder(nodeType *rootP, int level) {
  if (rootP==NULL) return;
  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printf("\n");
  printPreorder(rootP->left,level+1);
  printPreorder(rootP->right,level+1);
}

// process left child, process root, process right child
static void printInorder(nodeType *rootP, int level) {
  if (rootP==NULL) return;
  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printf("\n");
  printPreorder(rootP->left,level+1);
  printPreorder(rootP->right,level+1);
}

// process children left to right, process root
static void printPostorder(nodeType *rootP, int level) {
  if (rootP==NULL) return;
  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printf("\n");
  printPreorder(rootP->left,level+1);
  printPreorder(rootP->right,level+1);
}