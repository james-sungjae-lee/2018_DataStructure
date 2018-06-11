#include <iostream>
using namespace std;

struct Node{
private:
  int data;
  Node *next;
  friend class List;
};

class List{
private:
  Node *head;
public:
  List(){head = 0;}
  void insertNodeFirst(int);
  void insertNodeLast(int);
  void insertNodeBackHead(int);
  void deleteNode(int);
  void deleteFront();
  void deleteEnd();
  ~List();
  bool isEmpty();
  void traverseList();
  void searchList(int);
  void display();
};

bool List::isEmpty(){
  if (head == 0) {
    return true;
  }else{
    return false;
  }
}

void List::insertNodeFirst(int data){

  Node *temp = new Node;

  (temp -> data) = data;
  (temp -> next) = 0;
  std::cout << data << " Inserted! " << '\n';
  if (head != 0) {
    (temp -> next) = head;
    head = temp;
  }else{
    head = temp;
  }
}

void List::insertNodeLast(int data){
  Node *temp = new Node;
  Node *p;
  (temp -> data) = data;
  (temp -> next) = 0;
  std::cout << data << " Inserted Last!" << '\n';
  if (head != 0) {
    p = head;
    while ((p -> next) != 0) {
      p = (p -> next);
    }
    (p -> next) = temp;
  }else{
    head = temp;
  }
}

void List::insertNodeBackHead(int data) {
  Node *temp = new Node;
  temp -> data = data;
  if (head -> next == 0) {
    head -> next = temp;
    std::cout << data << " Inserted BackHead(Last)!" << '\n';
  }else{
    temp -> next = head -> next;
    head -> next = temp;
    std::cout << data << " Inserted BackHead(middle)!" << '\n';
  }
}

void List::deleteNode(int num) {
  Node *p, *q;
  if ((head -> data) == num) {
    p = head;
    head = (head -> next);
    delete p;
  }else{
    p = head;
    while ((p != 0) && ((p -> data) != num)) {
      q = p;
      p = (p -> next);
    }
    if (p != 0) {
      (q -> next) = (p -> next);
      delete p;
    }else{
      std::cout << num << " is not in the list" << '\n';
    }
  }
}

void List::deleteFront() {
  if (isEmpty() != 1 ) {
    Node *p;
    p = head;
    head = head -> next;
    delete p;
    std::cout << "Front Deleted" << '\n';
  }else{
    std::cout << "Queue is Empty!" << '\n';
  }
}
void List::deleteEnd() {
  if (isEmpty() != 1 ) {
    Node *p, *q;
    p = head;
    q = head;
    while ((p->next) != NULL) {
      q = p;
      p = p->next;
    }
    q -> next = NULL;
    delete p;
    std::cout << "End Deleted" << '\n';
  }else{
    std::cout << "Queue is Empty!" << '\n';
  }
}

void List::traverseList() {
  Node *p;
  if (!isEmpty()) {
    p = head;
    while (p) {
      std::cout << (p -> data) << '\n';
      p = (p -> next);
    }
    std::cout << '\n';
  }else{
    std::cout << "List is Empty!" << '\n';
  }
}

List::~List() {
  Node *p;
  while (head != 0) {
    p = head;
    head = (head -> next);
    delete p;
  }
}

void List::searchList(int num){
  Node *p;
  if (head != 0) {
    p = head;
    while ((p != 0) && ((p->data ) != num)) {
      p = (p -> next);
    }
    if (p) {
      std::cout << (p -> data) << " is found" << '\n';
    }else{
      std::cout << "Can not found " << num << '\n';
    }
  }
}

void List::display() {
  Node *p;
  p = head;
  while (p) {
    std::cout << (p->data) << " Printed!"<< '\n';
    p = (p -> next);
  }
}


int main(int argc, char const *argv[]) {

  List a;
  for (size_t i = 0; i < 10; i++) {
    a.insertNodeLast(i);
  }
  for (size_t i = 0; i < 5; i++) {
    a.deleteEnd();
  }
std::cout << '\n';
  a. display();

  a.traverseList();

  a.display();

  return 0;
}
