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
  Node *insertBst(Node *p,int data);
  void insertBst(int data);

  Node *searchBst(Node *p, int key);
  void printSearch(int key);

  void drawTree();
  void drawBSTree(Node *, int);
};

void Tree::insertBst(int data){
  insertBst(root, data);
}

Node *Tree::insertBst(Node *p, int data){
  if (p == NULL) {
    p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
  }else if (data < p->data) {
    p->left = insertBst(p->left, data);
  }else if (data > p->data) {
    p->right = insertBst(p->right, data);
  }
  return p;
}

Node *Tree::searchBst(Node *p, int key){
  if (p == NULL) {
    return NULL;
  }else{
    if (key == p->data) {
      return p;
    }else if (key < p->data) {
      p = searchBst(p->left, key);
    }else if (key > p->data) {
      p = searchBst(p->right, key);
    }
  }
  return p;
}

void Tree::printSearch(int key) {
  Node *temp = searchBst(root, key);
  if (temp == NULL) {
    std::cout << key << "can't found" << '\n';
  }else{
    std::cout << key << " found! " << '\n';
  }
}

void Tree::drawTree(){drawBSTree(root, 1);}

void Tree::drawBSTree(Node *p, int level) {
if (p != 0 && level <= 7) {
drawBSTree(p->right, level+1);
for (int i = 1; i <= (level-1); i++)
cout << " ";
cout << p->data;
if (p->left != 0 && p->right != 0) cout << " <" << endl;
else if (p->right != 0) cout << " /" << endl;
else if (p->left != 0) cout << " \\" << endl;
else cout << endl;
drawBSTree(p->left, level+1);
}
}




int main(int argc, char const *argv[]) {
  Tree a;
  a.root = new Node;
  a.root->data = 1;
  a.root->left = NULL;
  a.root->right = NULL;

  a.insertBst(10);
  a.insertBst(4);
  a.insertBst(80);
  a.insertBst(44);
  a.insertBst(33);
  a.insertBst(70);

  a.drawTree();
  a.printSearch(1);

  return 0;
}












//
