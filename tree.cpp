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

using namespace std;

BinarySearchTree::BinarySearchTree() {
  root = nullptr;
}

Node* BinarySearchTree::buildTree(string fileName) {
  // read file contents
  fstream fileToRead;
  string totalWords;
  string separator = "\n";
  
  BinarySearchTree searchTree;

  fileToRead.open(fileName, ios::in);
  string word;
  while(getline(fileToRead, word)) {
    // search tree, add or append
    
    cout << word;
    totalWords = word + "\n";
    // add word as separate entity to input
    int strSize = word.size();
    cout << "string size: " << to_string(strSize) << endl;
    string firstChars;
    if(strSize == 1) {
      cout << "string size is 1" << endl;
      firstChars = to_string(word[0]);
    }
    else {
      firstChars = to_string(word[0]) + to_string(word[1]);
    }
    cout << "first chars: " << firstChars << endl;

    // search through current tree until match is found
    // if(firstChars == )
  }
  fileToRead.close();

  cout << "Total words: " << totalWords << endl;

  // returns a tree?
  // Node *rootNode = searchTree.getRoot();

  return searchTree.root;
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

void BinarySearchTree::addNode(string newString) {
  cout << "Adding node" << endl;
}

void BinarySearchTree::insertNode(Node *root, string word) {
  cout << "Inserting node" << endl;
}

void BinarySearchTree::searchNode(string word) {
  cout << "Searching node" << endl;
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