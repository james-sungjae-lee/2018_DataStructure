#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  friend class BST;
};

class BST{
private:
  Node *root;
  Node *insertBST(Node *p, int data);
  Node *dropBST(Node *p);
  Node *findMin(Node *p);
  Node *deleteBST(Node *p, int key);
  void inorderBST(Node *p);
  Node *searchBST(Node *p, int key);
  void drawTree(Node *p, int level);

public:
  void insertBST(int data){root = insertBST(root, data);}
  void deleteBST(int key){root = deleteBST(root, key);}
  void inorderBST(){inorderBST(root); std::cout << '\n';}
  void searchBST(int key){searchBST(root, key);}
  void drawTree(){drawTree(root, 1);};
  ~BST(){root = dropBST(root);}
};

// private 내부 함수의 상세 구현 내용

Node *BST::dropBST(Node *p){
  if (p == NULL) {
    return NULL;
  }
  dropBST(p->left);
  dropBST(p->right);
  delete p;

  return NULL;
}

Node *BST::insertBST(Node *p, int data){
  if (p == NULL) {
    p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
  }else if (data < p->data) {
    p->left = insertBST(p->left, data);
  }else if (data > p->data) {
    p->right = insertBST(p->right, data);
  }
  return p;
}

Node *BST::findMin(Node *p){
  if (p == NULL) {
    return NULL;
  }else if (p->left == NULL) {
    return p;
  }else{
    return findMin(p->left);
  }
}

Node *BST::deleteBST(Node *p, int key){
  Node *temp;
  if (p == NULL) {
    std::cout << key <<" is not found!" << '\n';
    return NULL;
  }else if (key < p->data) {
    p->left = deleteBST(p->left, key);
  }else if (key > p->data) {
    p->right = deleteBST(p->right, key);
  }else if (p->left && p->right) {
    temp = findMin(p->right);
    p->data = temp->data;
    p->right = deleteBST(p->right, p->data);
  }else{
    temp = p;
    if (p->left == NULL) {
      p = p->right;
    }else if(p->right == NULL) {
      p = p->left;
    }
    delete temp;
  }
  return p;
}

void BST::inorderBST(Node *p){
  if (p == NULL) {
    return;
  }
  inorderBST(p->left);
  std::cout << p->data << ' ';
  inorderBST(p->right);
}

Node *BST::searchBST(Node *p, int key){
  if (p == NULL) {
    std::cout << key << " is not found" << '\n';
    return NULL;
  }else if (key < p->data) {
    return searchBST(p->left, key);
  }else if (key > p->data) {
    return searchBST(p->right, key);
  }else{
    std::cout << key << " is found!" << '\n';
    return p;
  }
}

void BST::drawTree(Node *p, int level){
  if (p != 0 && level <= 7) {
    drawTree(p->right, level + 1);
    for (size_t i = 1; i <= (level-1); i++) {
      std::cout << "      ";
    }
    std::cout << p->data;
    if (p->left != 0 && p->right != 0)
      std::cout << "  <" << '\n';
    else if (p->right != 0)
      std::cout << "   /" << '\n';
    else if (p->left != 0)
      std::cout << "   \\" << '\n';
    else
      std::cout << '\n';
    drawTree(p->left, level+1);
  }
}



int main(int argc, char const *argv[]) {
  BST test;

  test.insertBST(30);
  test.insertBST(40);
  test.insertBST(50);
  test.insertBST(20);
  test.insertBST(10);
  test.drawTree();
  std::cout << "------------------------" << '\n';

  test.deleteBST(20);
  test.drawTree();
  std::cout << "------------------------" << '\n';

  test.deleteBST(50);
  test.drawTree();
  std::cout << "------------------------" << '\n';

  test.deleteBST(30);
  test.drawTree();
  std::cout << "------------------------" << '\n';

  test.searchBST(40);

  test.searchBST(50);

  return 0;
}
