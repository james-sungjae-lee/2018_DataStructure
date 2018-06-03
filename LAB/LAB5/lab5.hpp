#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

class Node{
private:
  string name;
  int weight;
  int height;

  Node *next;
  Node *prev;
  Node(string inName, int inWeight, int inHeight){
    name = inName;
    weight = inWeight;
    height = inHeight;
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

  int isEmpty();
  int listLength();

  void insertByName(string inName, int inWeight, int inHeight);
  void deleteNode(string key);

  void forwardList();
  void backwardList();

  void searchList(string);
  void findNth(int Nth);
};

void List::insertByName(string inName, int inWeight, int inHeight){
  Node *temp = new Node(inName, inWeight, inHeight);
  Node *p, *q;
  if (head == 0) {
    head = temp;
  // }else if (temp -> name[0] < head -> name[0]) {
    /* code */

  }else if (temp -> name.compare(head -> name) < 0) {
    temp -> next = head;
    head -> prev = temp;
    head = temp;
  }else{
    p = head;
    q = head;
    while ((p != 0) && (p -> name.compare(temp -> name) < 0)) {
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

void List::deleteNode(string key) {
  Node *p, *q;
  if (head == 0) {
    std::cerr << "List is empty" << '\n';
  }else{
    if (head -> name == key) {
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
      while (p != 0 && p -> name != key) {
        q = p;
        p = p -> next;
      }
      if ((p -> next != 0) && (p -> name == key)) {
        q -> next = p -> next;
        p -> next -> prev = q;
        delete p;
      }else if (p -> next == 0 && p -> name == key) {
        q -> next = 0;
        delete p;
      }else{
        std::cout << key << " is not in the list" << '\n';
      }
    }
  }
}

void List::searchList(string key){
  if (!isEmpty()) {
    Node *p = head;
    while (p != 0 && p -> name != key) {
      p = p -> next;
    }
    if (p != 0) {
      std::cout << p -> name << " is in the list" << '\n';
    }else{
      std::cout << key << " is not in the list" << '\n';
    }
  }else{
    std::cout << "List is empty" << '\n';
  }
}

void List::forwardList(){
  if (!isEmpty()) {
    Node *p = head;
    std::cout << "---Forward List---" << '\n';
    while (p != 0) {
      std::cout << p -> name << " " << p -> weight << " " << p -> height << " " << '\n';
      p = p -> next;
    }
  }else{
    std::cout << "List is empty" << '\n';
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
      std::cout << p -> name << " " << p -> weight << " " << p -> height << " " << '\n';
      p = p -> prev;
    }
  }else{
    std::cout << "List is empty" << '\n';
  }
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

int List::isEmpty(){
  return (head == 0);
}

void List::findNth(int Nth){
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
    std::cout << current -> name << " "<< current -> weight << " "<< current -> height << '\n';
  }else{
    std::cout << "No such a line!" << '\n';
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
