#include <iostream>
#include <string>
#include <stdlib.h>

const int queueSize = 100;
int queue[queueSize];
int rear, front;

void createQueue(), enQueue(int), displayQueue(), deQueue();
int isFull(), isEmpty(), pop();
int num;
char input[10];


void createQueue() {
  rear = -1;
  front = -1;
}

int isFull(){
  if (rear == (queueSize - 1)) {
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


void enQueue(int num) {
  queue[rear++] = num;
}

void deQueue(){
  front++;
}

int pop(){
  if (isEmpty()) {
    std::cout << "Queue is Empty" << '\n';
    return 0;
  }
  std::cout << queue[front] << '\n';
  return (queue[front++]);
}

void displayQueue() {
  int sp;
  if (isEmpty()) {
    std::cout << "Queue is empty" << '\n';
  }else{
    sp = front;
    while (sp != rear) {
      std::cout << queue[sp] ;
      ++sp;
      std::cout << '\n';
    }
  }
}
