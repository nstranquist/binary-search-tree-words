#include "tree.h"

#include <fstream>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

BinarySearchTree::BinarySearchTree() {
  root = nullptr;
}

Node* BinarySearchTree::createNode(string key, string word) {
  Node *node = new Node();

  node->key = key;
  node->words = word;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

Node* BinarySearchTree::buildTree(istream *input) {
  string delimiterComma = ",";
  string delimiterSpace = " ";
  string delimiterTab = "\t";
  string line;

  while (getline(*input, line)) {
    if(line == "EOF" || line == "") {
      cout << "end of file" << endl;
      break;
    }

    // Split line into characters, check for delimiters, build tree this way
    if((line.find(delimiterSpace)) != string::npos) {
      splitByDelimiter(delimiterSpace, line);
    }
    else if((line.find(delimiterComma)) != string::npos) {
      splitByDelimiter(delimiterComma, line);
    }
    else if((line.find(delimiterTab)) != string::npos) {
      splitByDelimiter(delimiterTab, line);
    }
    else {
      // treat line as one word, add right to tree
      string key = this->getCharKey(line);

      this->handleNewNode(key, line);
    }
  }

  return this->root;
}

// root -> left -> right
void BinarySearchTree::printPreorder(Node *rootPtr, int level) {
  if (rootPtr==NULL) return;

  cout << std::string((level*2), '-') << rootPtr->key << ": " << rootPtr->words << endl;
  printPreorder(rootPtr->left, level+1);
  printPreorder(rootPtr->right, level+1);
}

// left -> root -> right
void BinarySearchTree::printInorder(Node *rootPtr, int level) {
  if (rootPtr==NULL) return;

  printInorder(rootPtr->left,level+1);
  cout << std::string((level*2), '-') << rootPtr->key << ": " << rootPtr->words << endl;
  printInorder(rootPtr->right,level+1);
}

// left -> right -> root
void BinarySearchTree::printPostorder(Node *rootPtr, int level) {
  if (rootPtr==NULL) return;

  printPostorder(rootPtr->left,level+1);
  printPostorder(rootPtr->right,level+1);
  cout << std::string((level*2), '-') << rootPtr->key << ": " << rootPtr->words << endl;
}

void BinarySearchTree::addWordToNode(Node *temp, string word) {
  temp->words = temp->words + " " + word;
}

Node* BinarySearchTree::searchNode(string searchKey) {
  if(this->root == NULL || root->key == searchKey)
    return this->root;

  queue<Node*> q;
  Node *out = nullptr;

  q.push(this->root);

  while(!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if(temp->key == searchKey)
      out = temp;
    if(temp->left != NULL)
      q.push(temp->left);
    if(temp->right != NULL)
      q.push(temp->right);
  }
  
  return out;
}

void BinarySearchTree::insertNode(string key, string word) {
  // if root is null, need to initialize it
  if(this->root == NULL) {
    this->root = this->createNode(key, word);
    return;
  }

  // if root exists, can safely search node to insert
  Node *nodeToInsert = this->createNode(key, word);

  queue<Node*> q;
  q.push(this->root);

  while(!q.empty()) {
    Node *temp = q.front();

    q.pop();

    if(temp->left == NULL) {
      temp->left = nodeToInsert;
      return;
    }
    else {
      q.push(temp->left);
    }

    if(temp->right == NULL) {
      temp->right = nodeToInsert;
      return;
    }
    else {
      q.push(temp->right);
    }
  }
}

// returns the 1 or 2 letter strings from word
string BinarySearchTree::getCharKey(string word) {
  // get length of word
  int length = word.length();

  if(length > 2) {
    string charKey = word.substr(0, 2);
    return charKey;
  }
  else
    return word;
}

void BinarySearchTree::splitByDelimiter (string delimiter, string line) {
  size_t last = 0;
  size_t next = 0;

  string word;
  string key;
  while((next = line.find(delimiter, last)) != string::npos) {
    word = line.substr(last, (next-last));
    key = this->getCharKey(word);

    this->handleNewNode(key, word);

    last = next + 1;
  }

  if(last > 0) {
    string lastWord = line.substr(last);
    key = this->getCharKey(lastWord);

    this->handleNewNode(key, lastWord);
  }
}

void BinarySearchTree::handleNewNode (string key, string line) {
  Node *foundNode = this->searchNode(key);
    
  if(foundNode == NULL) {
    this->insertNode(key, line);
  }
  else {
    this->addWordToNode(foundNode, line);
  }
}
