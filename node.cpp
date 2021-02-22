#include "node.h"
#include <iostream>

Node *createNode(string key) {
  Node *node;
  
  node->key = key;
  node->words = "";
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

int getCount(Node *node) {
  cout << "Getting count for node" << endl;
  return 1;
}

void insertWord(string word) {
  cout << "Inserting word into node" << endl;
}