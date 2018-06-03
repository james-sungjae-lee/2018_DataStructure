#include <iostream>
#include <string>
#include <stdlib.h>

const int queueSize = 3;
char queue[queueSize];
int rear, front;

void createQueue(), enQueue(char), displayQueue(), deQueue();
int isFull(), isEmpty();

void createQueue() {
  rear = -1;
  front = -1;
}

int isFull(){
  if (front == (rear + 1) % queueSize) {
    return 1;
  }else{
    return 0;
  }
}

int isEmpty(){
  if (front == rear) {
    return 1;
  }else{
    return 0;
  }
}


void enQueue(char ch) {
  if (front == (rear + 1) % queueSize) {
    std::cout << "Queue is full" << '\n';
  }else{
    rear = (rear + 1) % queueSize;
    queue[rear] = ch;
  }
}

void deQueue(){
  if (isEmpty()) {
    std::cout << "Queue is Empty" << '\n';
  }else{
    front = (front + 1) % queueSize;
    queue[front] = 0;
  }
}

void displayQueue() {
  int sp;
  if (isEmpty()) {
    std::cout << "Queue is Empty" << '\n';
  }else{
    sp = front + 1;
    while (sp != rear) {
      std::cout << queue[sp] ;
      sp = (sp + 1) % queueSize;
      std::cout << '\n';
    }
    std::cout << queue[rear] << '\n';
  }
}
