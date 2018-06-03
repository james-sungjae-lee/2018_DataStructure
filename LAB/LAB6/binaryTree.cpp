#include <iostream>
using namespace std;

struct node{
  char data;
  int prio;
  struct node *left;
  struct node *right;
};

class Node{
private:
  int data;
  Node *left;
  Node *right;
  Node(int value){
    data = value;
    left = 0;
    right = 0;
  }
  friend class Tree;
};

class Tree{
private:
  Node *root;
public:
  Tree(){
    root = 0;
  }
  ~Tree();
};

char prec[4][2] = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};
