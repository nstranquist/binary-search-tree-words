// Main file for the program

#include "node.h"
#include "tree.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>

using namespace std;

// method of getting keyboard input:
// 1. If keyboard input, read the input into temporary file, after which the rest of the program always processes file input
// 2. If keyboard input, set file pointer to stdin otherwise set file pointer to the actual file, then process always from the file pointer

int main(int argc, char* argv[]) {
  // process command line arguments first and error if improper
  // - first argument should be "P0"
  // - if no arguments after "P0", then read from keyboard in a loop until user enters "EOF"
  // - if next argument is "<", then check for valid filename to follow and read from it
  // - else, assume next argument is the filename, and attempt to read from it
  fstream file;
  ofstream outFile;

  // If keyboard input, always write it to a temporary file.
  string inputFileName = "temp-input.txt";
  string tempOutputFileName = "temp-output.txt";

  string outputBaseFileName = "output";

  int i;
  bool fileGiven = false;
  for(i = 0; i < argc; i++) {
    printf("Argument %d is %s\n", i, argv[i]);
    if(i == 1) {
      if(strcmp(argv[i], "P0") != 0) {
        cout << "Invalid Command. 'P0' not detected. Exiting..." << endl;
        return 0;
      }
    }
    if(i == 2) {
      fileGiven = true;
      // check for type
      inputFileName = argv[i];
      cout << "user wants us to test their file" << endl;
      cout << inputFileName << endl;
    }
  }

  // if filename given, make sure file is readable, error otherwise
  if(fileGiven) {
    cout << "will now validate and read the user's file" << endl;

    // Make sure to validate program
    bool valid = true;
    if (!valid) {
      cout << "File was not valid. Exiting..." << endl;
      return 0;
    }
    
    outputBaseFileName = "inputFileName";

    file.open(inputFileName, ios::in);
    if(!file) {
      cout << "File not created" << endl;
      cout << "Error! Exiting program..." << endl;
      return 0;
    }
    else {
      cout << "File created successfully" << endl;
      file.close();
    }
  }
  else {
    cout << "will begin user keyboard input loop (and write to temp file)" << endl;

    // Read from the file (string inputFileName)
    outFile.open(inputFileName);
    if(!outFile) {
      cout << "File not created" << endl;
      cout << "Error! Exiting program..." << endl;
      return 0;
    }
    else {
      cout << "File created successfully" << endl;
    }

    cout << "Please enter the text that you want processed (Enter \"EOF\" or enter to stop):" << endl;
    bool continueInput = true;
    while(continueInput) {
      // get input
      string newInput;
      cin >> newInput;
      if(newInput == "EOF") {
        continueInput = false;
      }
      else {
        // write the input to file
        outFile << newInput;
        outFile << "\n";
      }
    }
    outFile.close();
  }
  
  // Build Tree and Conduct Traversals
  cout << "Building BST" << "\n\n";

  BinarySearchTree searchTree;

  searchTree.buildTree(inputFileName);

  cout << "\n\n";

  if(searchTree.root == NULL) {
    cout << "root ptr is still null" << endl;
  }
  else {
    cout << "search tree root key: " << searchTree.root->key << endl;
  }

  cout << "\n\n----------------Printing tree Preorder--------------\n\n" << endl;
  searchTree.printPreorder(searchTree.root);

  cout << "\n\n----------------Printing tree Inorder--------------\n\n" << endl;
  searchTree.printInorder(searchTree.root, 0);

  cout << "\n\n----------------Printing tree Postorder--------------\n\n" << endl;
  searchTree.printPostorder(searchTree.root, 0);

  cout << "End of program." << endl;

  if(file.is_open()) {
    file.close();
  }

  return 0;
}