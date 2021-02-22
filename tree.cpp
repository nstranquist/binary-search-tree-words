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
  Node *node = new Node();

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

  // Initialize root node with the first word
  string word;
  string first_key;

  getline(fileToRead, word);

  cout << "First word: " << word << endl;

  first_key = this->getCharKey(word);

  this->insertNode(first_key, word);

  while(getline(fileToRead, word)) {
    // Read each word from file
    cout << "\n" << "word: " << word << "\n";

    // add word as separate entity to input
    string key = this->getCharKey(word);

    cout << "key: " << key << "\n\n";

    // search through current tree
    // - if match is found, add word to the node
    // - if match is not found, insert the node into the tree

    Node *foundNode = this->searchNode(key);
    
    if(foundNode == NULL) {
      cout << "Node was not found. Adding to tree" << endl;
      this->insertNode(key, word);
    }
    else {
      cout << "Node with key was found. Inserting word into node" << endl;
      this->addWordToNode(foundNode, word);
    }
  }

  fileToRead.close();

  return this->root;
}

// root -> left -> right
void BinarySearchTree::printPreorder(Node *rootPtr) {
  if (rootPtr==NULL)
    return;

  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  cout << "key: " << rootPtr->key << "\nwords: " << rootPtr->words << "\n\n";
  // cout << rootPtr->data << " ";
  printPreorder(rootPtr->left);
  printPreorder(rootPtr->right);
}

// left -> root -> right
void BinarySearchTree::printInorder(Node *rootPtr, int level) {
  if (rootPtr==NULL) return;

  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printInorder(rootPtr->left,level+1);
  cout << "key: " << rootPtr->key << "\nwords: " << rootPtr->words << "\n\n";
  printInorder(rootPtr->right,level+1);
}

// left -> right -> root
void BinarySearchTree::printPostorder(Node *rootPtr, int level) {
  if (rootPtr==NULL) return;
  
  // printf("%*c%d:%-9s ",level*2,' ',level/*, NodeId.info*/); // assume some info printed as string
  printPostorder(rootPtr->left,level+1);
  printPostorder(rootPtr->right,level+1);
  cout << "key: " << rootPtr->key << "\nwords: " << rootPtr->words << "\n\n";
}

void BinarySearchTree::addWordToNode(Node *temp, string word) {
  cout << "Adding word to node: " << word << endl;

  cout << "Existing words: " << temp->words << endl;

  temp->words = temp->words + " " + word;

  cout << "Words after edit: " << temp->words << endl;
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
  cout << "Inserting node" << endl;

  // if root is null, need to initialize it
  if(this->root == NULL) {
    cout << "Root is null. Initializing..." << endl;
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