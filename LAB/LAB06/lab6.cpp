#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
  char data;
  Node *left;
  Node *right;
  int prio;
  Node(){
    left = 0;
    right = 0;
  }
  friend class Tree;
};

class Tree{
public:
  Node *root;
public:
  Tree(){root = 0;}
  // ~Tree();
  void buildTree(char);
  void operandNode(Node *newNode);
  void operatorNode(Node *newNode);
  void inorder(Node *p);
  void postorder(Node *p);
  void preorder(Node *p);
  int evaluationTree(Node *p);
};

char prec[4][2] = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};

void Tree::buildTree(char expA){
    Node *temp = new Node;
    temp -> data = expA;
    temp -> prio = 4;

    for (size_t i = 0; i < 4; i++) {
      if (temp -> data == prec[i][0]) {
        temp -> prio = prec[i][1];
      }
    }
    if (temp -> prio == 4) {
      operandNode(temp);
    }else{
      operatorNode(temp);
    }
}

void Tree::operandNode(Node *newNode){
  Node *p;
  if (root == 0) {
    root = newNode;
  }else{
    p = root;
    while (p -> right != 0) {
      p = p -> right;
    }
    p -> right = newNode;
  }
}

void Tree::operatorNode(Node *newNode){
  Node *p;
  p = root;
  if (root -> prio > newNode -> prio) {
    newNode -> left = root;
  }

   if (root -> prio >= newNode -> prio) {
      newNode -> left = root;
      root = newNode;
  }else{
     newNode -> left = root -> right;
     root -> right = newNode;
  }
}

void Tree::inorder(Node *p){
  if(p){
    inorder(p -> left);
    std::cout << p -> data << ' ';
    inorder(p -> right);
  }
}

void Tree::postorder(Node *p) {
  if (p) {
    postorder(p -> left);
    postorder(p -> right);
    std::cout << p -> data << ' ';
  }
}

void Tree::preorder(Node *p) {
  if (p) {
    std::cout << p -> data << ' ';
    preorder(p -> left);
    preorder(p -> right);
  }
}

int Tree::evaluationTree(Node *p){
  int result = 0;
  int left;
  int right;
  if (p) {
    if ('0' <= p -> data && p -> data <= '9') {
      result = p -> data - '0';
    }else{
      left = evaluationTree(p -> left);
      right = evaluationTree(p -> right);
      switch (p -> data) {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/': result = left / right; break;
        default: break;
      }
    }
  }else{
    std::cout << "Empty tree" << '\n';
  }
  return result;
}

int main(int argc, char const *argv[]) {
  Tree t;
  std::cout << "수식을 입력하세요 : " ;
  string k;
  std::cin >> k;
  for (size_t i = 0; i < k.length(); i++) {
    t.buildTree(k[i]);
  }
  std::cout << "infix" << '\n';
  t.inorder(t.root);
  std::cout << '\n';
  std::cout << "postfix" << '\n';
  t.postorder(t.root);
  std::cout << '\n';
  std::cout << "prefix" << '\n';
  t.preorder(t.root);
  if (k[0] >=48 && k[0] <= 57) {
    std::cout << '\n';
    std::cout << "result : "<< t.evaluationTree(t.root) << '\n';
  }

  return 0;
}
