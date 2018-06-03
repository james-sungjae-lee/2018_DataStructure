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
  friend class linkedQueue;
};

class linkedQueue{
private:
  Node *front;
  Node *rear;

public:
  linkedQueue(){
    front = 0;
    rear = 0;
  }
  ~linkedQueue(){};
  void createQueue();
  void enqueue(int);
  int dequeue();
  int isEmpty();

  void displayQueue();
  void searchQueue(int);
};

int linkedQueue::isEmpty(){
  if (front == 0) {
    return 1;
  }else{
    return 0;
  }
}

void linkedQueue::createQueue() {
  front = 0;
  rear = 0;
}

void linkedQueue::enqueue(int data) {
  Node *temp = new Node(data);

  if (front == 0) {
    front = temp;
    rear = temp;
  }else{
    rear -> next = temp;
    rear = temp;
  }
}

int linkedQueue::dequeue(){

  Node *p;
  int num;
  num = front -> data;
  p = front;

  if (front == rear) {
    front = 0;
    rear = 0;
  }else{
    front = front -> next;
    delete p;
    return num;
  }
  return 0;
}

void linkedQueue::displayQueue() {
  Node *p;
  if (!isEmpty()) {
    p = front;
    while (p) {
      std::cout << p -> data;
      p = p->next;
    }
    std::cout << '\n';
  }else{
    std::cout << "Queue is Empty!" << '\n';
  }
}

int main(int argc, char const *argv[]) {
  linkedQueue b;
  b.createQueue();

  for (size_t i = 0; i < 10; i++) {
    b.enqueue(i);
  }
  for (size_t i = 0; i < 5; i++) {
    b.dequeue();
  }

  b.displayQueue();
  return 0;
}
