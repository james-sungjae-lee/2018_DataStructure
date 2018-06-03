#include <iostream>
using namespace std;

class Node{
private:
  int data;
  Node *next;
  Node(int value){
    data = value;
    next = 0;
  }
  friend class linkedStack;
};

class linkedStack{
private:
  Node *head;

public:
  linkedStack(){
    head = 0;
  }
  ~linkedStack(){};
  void createStack();
  void push(int);
  int pop();
  int isEmpty();
  void displayStack();
  void searchStack(int);
};

void linkedStack::createStack(){
  head = 0;
}

void linkedStack::push(int data){
  Node *temp = new Node(data);

  if (head == 0) {
    head = temp;
  }else{
    temp -> next = head;
    head = temp;
  }
}

int linkedStack::pop(){
  Node *p;
  int num;

  num = head -> data;
  p = head;
  head = head -> next;
  delete p;
  return num;
}

int linkedStack::isEmpty(){
  if (head == 0) {
    return 1;
  }else{
    return 0;
  }
}


void linkedStack::displayStack(){
  Node *p;

  if (!isEmpty()) {
    p = head;
    while (p) {
      std::cout << p -> data << '\n' ;
      p = p -> next;
    }
    std::cout << '\n';
  }
  else{
    std::cout << "Stack is Empty!" << '\n';
  }
}

int main(int argc, char const *argv[]) {
  linkedStack a;
  for (size_t i = 0; i < 10; i++) {
    a.push(i);
  }
  a.displayStack();
  return 0;
}
