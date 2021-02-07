# 4280 P0 - Project 1 - Nico Stranquist

### Steps to run this project:
1. xyz

### Notes
- Done in c++
- tests are in the /tests directory
- 

### To Do:
[ ] Makefile where P0 is the command to invoke it
[ ] Get command line arguments and print them out
  - P0 ... - will just read from keyboard until EOF (which is "enter" key?)
  - P0 < filename - will redirect from somefile instead of keyboard, tests keyboard input
  - P0 filename - reads from "filename.sp2020" 
[ ] Process input properly (to build tree with, presumably)
  - assume all inputs are strings, all separated by either space, tab, or newline
  - if input file is not readable, output error
  - 
[ ] Error handling
[ ] Output
  - Generate 3 Files:
    - file.preorder, file,inorder, and file.postorder
    --> "file" is either the basename given, or defaults to "output" if none given
  - a Node will print the node's first 2 letters (first two letters of all the strings in the node) intended by 2 * depth of the node, followed by list of strings from the node set (root considered to be 0)
