#include "node.h"
#include "tree.h"
#include <iostream>
#include <iomanip>
#include <string.h>

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

  int i;
  for(i = 0; i < argc; i++) {
    printf("Argument %d is %s\n", i, argv[i]);
    if(i == 1) {
      if(strcmp(argv[i], "P0") != 0) {
        cout << "Invalid Command. 'P0' not detected" << endl;
        return 0;
      }
    }
  }
  // if filename given, make sure file is readable, error otherwise

  // set up keyboard processing so that below this point there is only one version of the code



  
  string file = "example.txt";

  nodeType node_t = nodeType();

  cout << "would proceed to build tree and print traversals to output filse" << endl;

  // node_t *root = buildTree(file);
  // printPreorder(root);
  // printInorder(root);
  // printPostorder(root);

  return 0;
}