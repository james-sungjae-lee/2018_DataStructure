#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  friend class Tree;
};

class Tree{
public:
  Node *root;
  Tree(){root = NULL;}
  void insertTree(int);
};

void Tree::insertTree(int data){
  if (root == NULL) {
    std::cout << "root is null" << '\n';
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    root = temp;
  }else{

  }
}

int main(int argc, char const *argv[]) {
  Tree a;
  a.insertTree(10);
  a.insertTree(20);
  return 0;
}
