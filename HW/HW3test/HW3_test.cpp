#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  Node(){
    left = NULL;
    right = NULL;
  }
  friend class Tree;
};

class Tree{
public:
  Node *root;
public:
  Tree(){root = NULL;}
  void inorder(Node *p);
  Node *insertBst(Node *p, int data);
};

Node *Tree::insertBst(Node *p, int data){
  if (p == NULL) {
    p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    root = p;
    std::cout << "root is " << root->data << '\n';
  }else if (data < p->data) {
    p->left = insertBst(p->left, data);
  }else if (data > p->data) {
    p->right = insertBst(p->right, data);
  }
  return p;
}




int main(int argc, char const *argv[]) {
  Tree a;
  a.insertBst(a.root, 10);
  if (a.root == NULL) {
    std::cout << "root is still null" << '\n';
  }
  a.insertBst(a.root, 20);

  return 0;
}












//
