// Main file for the program

#include "node.h"
#include "tree.h"

#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  // process command line arguments first and error if improper
  // - first argument should be "P0"
  // - if no arguments after "P0", then read from keyboard in a loop until user enters "EOF"
  // - if next argument is "<", then check for valid filename to follow and read from it
  // - else, assume next argument is the filename, and attempt to read from it
  string outputBaseFileName = "output";

  istream *in;
  ifstream out;

  if (argc == 1) {
    in = &cin;
    cout << "Please enter the words for the program to use. Finish by entering 'EOF' or new line." << endl;
  }
  // Argument given, open the file and use it
  else if (argc == 2)
  {
    string fileName = argv[1];
    cout << "file: " << fileName << endl;
    out.open(fileName);
    in = &out;
    cout << "Reading your file..." << endl;
    if(!out.is_open()) {
      cout << "Your file could not be read. It is either empty or does not exist." << endl;
      return 1;
    }
    // need to get base filename from file

  }
  else {
    cout << "Error: Too many arguments given. Please retry with 1 or 2 arguments (including the command)." << endl;
    return 1;
  }

  // Initiate tree
  BinarySearchTree searchTree;

  Node *rootPtr = searchTree.buildTree(in);

  cout << "\n\n";
  
  // TODO: Null-check the tree
  if (rootPtr == NULL)
  {
    cout << "Error: BST is still null, input was not added successfully." << endl;
    return 1;
  }

  // Print Traversals
  cout << "\n\n----------------Printing tree Preorder--------------\n\n" << endl;
  searchTree.printPreorder(rootPtr, 0);

  cout << "\n\n----------------Printing tree Inorder--------------\n\n" << endl;
  searchTree.printInorder(rootPtr, 0);

  cout << "\n\n----------------Printing tree Postorder--------------\n\n" << endl;
  searchTree.printPostorder(rootPtr, 0);


  cout << "\n\nEnd of program." << endl;

  return 0;
}