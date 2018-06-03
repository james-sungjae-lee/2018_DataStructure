#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

typedef int Type;

class Node{
private:
  Type val;
  Node *next;
  Node *prev;
  Node(Type data){
    val = data;
    next = 0;
    prev = 0;
  }
  friend class List;
};

class List{
private:
  Node *head;
public:
  List();
  ~List();

  void insertFirst(Type data);
  void insertLast(Type data);
  void insertNumber(Type data);
  void locateCurrent(Type);
  void deleteList(Type);
  void forwardList();
  void backwardList();
  void searchList(Type);
  void insertNth(Type data, Type Nth);

  int listLength();
  int isEmpty();
};

int List::isEmpty(){
  return (head == 0);
}

List::List(){
  head = 0;
}

List::~List(){
  Node *p;

  while (head != 0) {
    p = head;
    head = head -> next;
    delete p;
  }
}

void List::insertFirst(Type data){
  Node *temp = new Node(data);
  if (head == 0) {
    head = temp;
  }else{
    temp -> next = head;
    head -> prev = temp;
    head = temp;
  }
}

void List::insertLast(Type data){
  Node *temp = new Node(data);
  Node *p;

  if (head == 0) {
    head = temp;
  }else{
    p = head;
    while (p -> next != 0) {
      p = p -> next;
    }
    p -> next = temp;
    temp -> prev = p;
  }
}


void List::insertNumber(Type data){
  Node *temp = new Node(data);
  Node *p, *q;
  if (head == 0) {
    head = temp;
  }else if (temp -> val < head -> val) {
    temp -> next = head;
    head -> prev = temp;
    head = temp;
  }else{
    p = head;
    q = head;
    while ((p != 0) && (p -> val < temp -> val)) {
      q = p;
      p = p -> next;
    }
    if (p != 0) {
      temp -> next = p;
      temp -> prev = q;
      q -> next = temp;
      p -> prev = temp;
    }else{
      q -> next = temp;
      temp -> prev = q;
    }
  }
}

void List::deleteList(Type key){
  Node *p, *q;

  if (head == 0) {
    std::cerr << "List is empty" << '\n';
  }else{
    if (head -> val == key) {
      if (head -> next != 0) {
        p = head;
        head = head -> next;
        head -> prev = 0;
        delete p;
      }else{
        head = 0;
      }
    }else{
      q = head;
      p = head;
      while (p != 0 && p -> val != key) {
        q = p;
        p = p -> next;
      }
      if ((p -> next != 0) && (p -> val == key)) {
        q -> next = p -> next;
        p -> next -> prev = q;
        delete p;
      }else if (p -> next == 0 && p -> val == key) {
        q -> next = 0;
        delete p;
      }else{
        std::cout << key << " is not in the list" << '\n';
      }
    }
  }
}

void List::forwardList(){
  if (!isEmpty()) {
    Node *p = head;
    std::cout << "---Forward List---" << '\n';
    while (p != 0) {
      std::cout << p -> val << '\n';
      p = p -> next;
    }
  }else{
    std::cout << "List is empty!" << '\n';
  }
}

void List::backwardList(){
  if (!isEmpty()) {
    Node *p = head;
    while (p -> next != 0) {
      p = p -> next;
    }
    std::cout << "---Backward List---" << '\n';
    while (p != 0) {
      std::cout << p -> val << '\n';
      p = p -> prev;
    }
  }else{
    std::cout << "List is empty" << '\n';
  }
}

void List::searchList(Type key){
  if (!isEmpty()) {
    Node *p = head;
    while (p != 0 && p -> val != key) {
      p = p -> next;
    }
    if (p != 0) {
      std::cout << p -> val << " is in the list" << '\n';
    }else{
      std::cout << key << " is not in the list" << '\n';
    }
  }else{
    std::cout << "List is empty" << '\n';
  }
}

void List::locateCurrent(Type Nth){
  Node *p;
  Node *current;
  int pos = 1;

  if (head == 0) {
    std::cout << "List is empty" << '\n';
  }else if (listLength() >= Nth) {
    p = head;
    while (pos != Nth) {
      p = p -> next;
      pos ++;
    }
    current = p;
    std::cout << pos << "th value : " ;
    std::cout << current -> val << '\n';
  }else{
    std::cout << "No such a line" << '\n';
  }
}

void List::insertNth(Type data, Type Nth){
  Node *p;
  Node *temp = new Node(data);
  p = head;

  for (size_t i = 1; i < Nth; i++) {
    p = p -> next;
  }
  if (p == head) {
    temp -> next = p;
    p -> prev = temp;
    head = temp;
  }else{
    p -> prev -> next = temp;
    temp -> prev = p -> prev;
    p -> prev = temp;
    temp -> next = p;
  }
}

int List::listLength(){
  Node *p;
  p = head;
  int cnt = 0;
  while (p != 0) {
    cnt ++;
    p = p -> next;
  }
  return cnt;
}
