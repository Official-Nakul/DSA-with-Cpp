#include "Tree.hpp"
#include <iostream>
using namespace std;

int main() {
  Tree tree = Tree();
  int num[] = {5, 2, -1, -1, 6, -1, -1};
  Node *node = tree.buildPreOrder(num);
  tree.preOrder(node);
  cout<<endl;
  Node *root = tree.Populate();
  tree.preOrder(root);
  return 0;
}