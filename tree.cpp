// This will include code for:
// 1. buildTree()
// 2. printInorder()
// 3. printPreorder()
// 4. printPostorder()

#include "tree.h"
#include "node.h"

#include <fstream>
#include <iostream> // cout, etc.
#include <string>
#include <queue>

using namespace std;

BinarySearchTree::BinarySearchTree() {
  root = nullptr;
}

Node* BinarySearchTree::createNode(string key, string word) {
  Node *node;

  node->key = key;
  node->words = word;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

Node* BinarySearchTree::buildTree(string fileName) {
  // read file contents
  fstream fileToRead;
  string totalWords;
  string separator = "\n";
  
  fileToRead.open(fileName, ios::in);

  if(!fileToRead.is_open()) {
    cout << "File could not be opened. Exiting..." << endl;
    return NULL;
  }

  string word;
  while(getline(fileToRead, word)) {
    // Read each word from file
    cout << "word: " << word << "\n";

    // add word as separate entity to input
    string key = this->getCharKey(word);

    cout << "key: " << key << endl;

    // search through current tree
    // - if match is found, add word to the node
    // - if match is not found, insert the node into the tree

    Node *foundNode = this->searchNode(key);
    
    if(foundNode == NULL) {
      cout << "Node was not found. Adding to tree" << endl;
      this->insertNode(word);
    }
    else {
      cout << "Node with key was found. Inserting word into node" << endl;
      this->addWordToNode(*foundNode, word);
    }
  }
  fileToRead.close();

  return this->root;
}

// process root, process children left to right
void BinarySearchTree::printPreorder(Node *rootP, int level) {
  if (rootP==NULL) return;
  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printf("\n");
  // cout << rootP->data << " ";
  printPreorder(rootP->left,level+1);
  printPreorder(rootP->right,level+1);
}

// process left child, process root, process right child
void BinarySearchTree::printInorder(Node *rootP, int level) {
  if (rootP==NULL) return;
  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printf("\n");
  printInorder(rootP->left,level+1);
  // cout << rootP->data << " ";
  printInorder(rootP->right,level+1);
}

// process children left to right, process root
void BinarySearchTree::printPostorder(Node *root, int level) {
  if (root==NULL) return;
  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printf("\n");
  printPostorder(root->left,level+1);
  printPostorder(root->right,level+1);
  // cout << root->data << " ";
}

void BinarySearchTree::addWordToNode(Node temp, string word) {
  cout << "Adding word to node: " << word << endl;


}

Node* BinarySearchTree::searchNode(string searchKey) {
  cout << "Searching node" << endl;

  if(this->root == NULL)
    return this->root;

  cout << "Character key (in searchNode): " << searchKey << endl;

  if(root->key == searchKey)
    return root;

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

void BinarySearchTree::insertNode(string word) {
  cout << "Inserting node" << endl;

  string searchKey = this->getCharKey(word);

  cout << "Character key: " << searchKey << endl;
}

// returns the 1 or 2 letter strings from word
string BinarySearchTree::getCharKey(string word) {
  // get length of word
  int length = word.length();

  if(length > 2) {
    string charKey = word.substr(0, 2);
    cout << "character key: " << charKey << endl;
    return charKey;
  }
  else
    return word;
}

// void addNode(string newString) {
//   bool nodeFound;
  
//   // check if tree already contains the character. Will automatically increment if it does
//   nodeFound = searchNode(newString);

//   if(nodeFound == false) {
//     // If not found, add the node as a new node:
//     Node *newNode = nullptr;

//     // Create new node, initialize its values, store character value
//     newNode = new Node;
//     newNode->character = character;
//     newNode->count = 1;
//     newNode->left = newNode->right = nullptr;

//     // Insert node
//     insertNode(root, newNode);
//   }
// }

// void insertNode(Node *root, Node newNode) {
//   if(nodePtr == nullptr) { // insert node
//     nodePtr = newNode;
//   } else if (newNode->character < nodePtr->character) {  // search left branch
//     insertNode(nodePtr->left, newNode);
//   } else {   // search right branch
//     insertNode(nodePtr->right, newNode);
//   }
// }

// bool searchNode(string newString) {
//   // get first two characters of string
//     // if length of newString < 2, search accordingly (to strLength=1)
//   Node *nodePtr = root;

//   while(nodePtr) {
//     if(nodePtr->character == character) {
//       incrementNode(nodePtr);
//       return true;
//     }
//     else if (character < nodePtr->character)
//       nodePtr = nodePtr->left;
//     else
//       nodePtr = nodePtr->right;
//   }

//   return false;
// }

// void incrementNode(Node *nodePtr) {

// }