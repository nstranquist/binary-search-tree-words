#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <string>

using namespace std;

struct Node {
  string words; // all of the words, separated by spaces (or other delimiter)
  string key; // the 1-2 characters defining the node
  Node *left;
  Node *right;
};

Node *createNode(string key);
int getCount();
void insertWord(string word);

#endif