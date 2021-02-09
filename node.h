#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <string>

using namespace std;

struct Node {
  string words;
  int count;
  Node *left;
  Node *right;
};

#endif