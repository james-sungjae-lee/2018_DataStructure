#include <iostream>
using namespace std;

struct Node{
private:
  int data;
  Node *left;
  Node *right;
  friend class Tree;
};

class Tree{
public:
  Node *root;
public:
  Tree(){root = 0;}
  void insertTree(int);
  void printTree();
};

void Tree::insertTree(int data){
  Node *temp = new Node;
  Node *p;
  p = root;
  temp -> data = data;
  temp -> left = 0;
  temp -> right = 0;
  if (root == 0) {
    root = temp;
  }else{
    if (root -> left == 0) {
      root -> left = temp;
    }else if (root -> right == 0) {
      root -> right = temp;
    }else{
      p = root -> left;
      p -> left = temp;
    }
  }
}

void Tree::printTree(){
  Node *p;
  p = root;
  std::cout << root -> data << '\n';
  p = root -> left;
  std::cout << p -> data << '\n';
  p = root -> right;
  std::cout << p -> data << '\n';
  std::cout << p -> data << '\n';
}

int main(int argc, char const *argv[]) {
  Tree t;
  for (size_t i = 1; i < 4; i++) {
    t.insertTree(i);
  }
  t.printTree();

  return 0;
}
