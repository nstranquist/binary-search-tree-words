// Main file for the program

#include "node.h"
#include "tree.h"

#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <string>

using namespace std;

// method of getting keyboard input:
// 1. If keyboard input, read the input into temporary file, after which the rest of the program always processes file input
// 2. If keyboard input, set file pointer to stdin otherwise set file pointer to the actual file, then process always from the file pointer

int main(int argc, char *argv[])
{
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

  // // Save original std::cin, std::cout
  // std::streambuf *coutbuf = std::cout.rdbuf();
  // std::streambuf *cinbuf = std::cin.rdbuf();

  // std::ofstream out("outfile.txt");
  // std::ifstream in("infile.txt");

  // //Read from infile.txt using std::cin
  // std::cin.rdbuf(in.rdbuf());

  // //Write to outfile.txt through std::cout
  // std::cout.rdbuf(out.rdbuf());

  // std::string test;
  // cout << "test: " << test << endl;
  // std::cin >> test;           //from infile.txt
  // std::cout << test << "  "; //to outfile.txt

  // //Restore back.
  // std::cin.rdbuf(cinbuf);
  // std::cout.rdbuf(coutbuf);

  istream *in;
  ifstream out;

  if (argc == 1)
    in = &cin;
  // Argument given, open the file and use it
  else
  {
    out.open(argv[1]);
    in = &out;
  }

  // Read from in

  string line;
  while (getline(*in, line)) {
    cout << line << endl;
    if(line == "EOF" || line == "") {
      cout << "end of file" << endl;
      break;
    }
  }

  return 0;

  cout << "arg count: " << argc << endl;

  if (argc == 1)
  {
    cout << "either redirecting or reading from keyboard input" << endl;
    cout << "will now validate and read the user's file" << endl;

    // Make sure to validate program
    bool valid = true;
    if (!valid)
    {
      cout << "File was not valid. Exiting..." << endl;
      return 0;
    }

    outputBaseFileName = "inputFileName";

    // TODO: read from file, don't just delete it
    file.open(inputFileName, ios::in);
    if (!file)
    {
      cout << "File not created" << endl;
      cout << "Error! Exiting program..." << endl;
      return 0;
    }
    else
    {
      cout << "File created successfully" << endl;
      file.close();
    }
  }
  else if (argc == 2)
  {
    inputFileName = argv[1];
    cout << "user wants us to test their file: " << inputFileName << endl;
    cout << "will begin user keyboard input loop (and write to temp file)" << endl;

    // Read from the file (string inputFileName)
    outFile.open(inputFileName);
    if (!outFile)
    {
      cout << "File not created" << endl;
      cout << "Error! Exiting program..." << endl;
      return 0;
    }
    else
    {
      cout << "File created successfully" << endl;
    }

    cout << "Please enter the text that you want processed (Enter \"EOF\" or enter to stop):" << endl;
    bool continueInput = true;
    while (continueInput)
    {
      // get input
      string newInput;
      cin >> newInput;
      if (newInput == "EOF")
      {
        continueInput = false;
      }
      else
      {
        // write the input to file
        outFile << newInput;
        outFile << "\n";
      }
    }
    outFile.close();
  }
  else
  {
    cout << "This program only supports 1 or 2 arguments. You have entered too many arguments. Exiting..." << endl;
  }

  // Build Tree and Conduct Traversals
  cout << "Building BST"
       << "\n\n";

  BinarySearchTree searchTree;

  Node *rootPtr = searchTree.buildTree(inputFileName);

  cout << "\n\n";

  if (rootPtr == NULL)
  {
    cout << "root ptr is still null" << endl;
  }
  else
  {
    cout << "search tree root key: " << rootPtr->key << endl;
  }

  cout << "\n\n----------------Printing tree Preorder--------------\n\n"
       << endl;
  searchTree.printPreorder(rootPtr);

  cout << "\n\n----------------Printing tree Inorder--------------\n\n"
       << endl;
  searchTree.printInorder(rootPtr, 0);

  cout << "\n\n----------------Printing tree Postorder--------------\n\n"
       << endl;
  searchTree.printPostorder(rootPtr, 0);

  cout << "End of program." << endl;

  if (file.is_open())
  {
    file.close();
  }

  return 0;
}