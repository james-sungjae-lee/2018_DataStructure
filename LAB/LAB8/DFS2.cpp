#include <iostream>
using namespace std;

struct Node{
public:
  int data;
  Node *next;
  friend class List;
};

class List{
public:
  Node *head;
public:
  List(){head = 0;}
  void insertNode(int);
};

void List::insertNode(int data) {
  Node *temp = new Node;
  Node *p;
  temp->data = data;
  temp->next = 0;

  if (head != 0) {
    p = head;
    while (p->next != 0) {
      p = p->next;
    }
    p->next = temp;
  }else{
    head = temp;
  }
}

int main(int argc, char const *argv[]) {
  List DFS[10];

  List a;
  a.insertNode(1);
  for (size_t i = 0; i < 3; i++) {
    a.insertNode(i+2);
  }
  List b;
  b.insertNode(2);
  for (size_t i = 0; i < 2; i++) {
    b.insertNode(i+2);
  }
  List c;
  c.insertNode(3);
  for (size_t i = 0; i < 1; i++) {
    c.insertNode(i+2);
  }

  DFS[0] = a;
  DFS[1] = b;
  DFS[2] = c;






  return 0;
}















//
