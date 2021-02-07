#ifndef NODE_H
#define NODE_H

#include <string>

class nodeType {
  public:
    // string data;
    nodeType* left;
    nodeType* right;
    
    nodeType(){};

  private:
    void find();
    void insert();
    void remove();
};

#endif