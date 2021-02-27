#include "node.h"
#include "tree.h"

#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
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
    out.open(fileName);
    in = &out;

    cout << "Reading your file..." << endl;
    if(!out.is_open()) {
      cout << "Error: Your file could not be read. It probably does not exist." << endl;
      return 1;
    }
    else if (out.peek() == ifstream::traits_type::eof()) {
      cout << "Error: Your file is empty, so it could not be used." << endl;
      return 1;
    }

    // filter the orignal filename for slashes
    size_t positionSlash;
    while((positionSlash = fileName.find('/')) != string::npos) {
      string tempSubstr = fileName.substr(positionSlash+1); // get the rest of the string after the current slash found
      fileName = tempSubstr;
    }

    // get filename after slashes removed
    size_t position = fileName.find('.');
    if(position != string::npos) {
      string newBaseFileName = fileName.substr(0, position);
      cout << "new base filename: " << newBaseFileName << endl;
      outputBaseFileName = newBaseFileName;
    }
    else
      outputBaseFileName = fileName;
  }
  else {
    cout << "Error: Too many arguments given. Please retry with 1 or 2 arguments (including the command)." << endl;
    return 1;
  }

  // Initiate tree
  BinarySearchTree searchTree;

  Node *rootPtr = searchTree.buildTree(in);

  cout << "\n";
  
  if (rootPtr == NULL)
  {
    cout << "Error: Input was not added successfully, you probably provided an empty set of inputs" << endl;
    return 1;
  }

  cout << "\n";

  // Print Traversals as output to a file
  ofstream outputFile;

  outputFile.open((outputBaseFileName + ".preorder"), ios::trunc);

  if(!outputFile.is_open()) {
    cout << "Error: Could not open a file to print your preorder traversal to.\n" << endl;
  }
  else {
    cout.rdbuf(outputFile.rdbuf());

    searchTree.printPreorder(rootPtr, 0);

    outputFile.close();
  }

  outputFile.open((outputBaseFileName + ".inorder"), ios::trunc);

  if(!outputFile.is_open()) {
    cout << "Error: Could not open a file to print your inorder traversal to.\n" << endl;
  }
  else {
    cout.rdbuf(outputFile.rdbuf());

    searchTree.printInorder(rootPtr, 0);

    outputFile.close();
  }

  outputFile.open((outputBaseFileName + ".postorder"), ios::trunc);

  if(!outputFile.is_open()) {
    cout << "Error: Could not open a file to print your postorder traversal to.\n" << endl;
  }
  else {
    cout.rdbuf(outputFile.rdbuf());

    searchTree.printPostorder(rootPtr, 0);

    outputFile.close();
  }

  cout << "\n\nEnd of program." << endl;

  return 0;
}