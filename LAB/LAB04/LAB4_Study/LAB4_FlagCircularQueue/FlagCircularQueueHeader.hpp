#include <iostream>
#include <string>
#include <stdlib.h>

const int queueSize = 10;
int queue[queueSize];
int rear, front;

void createQueue(), enQueue(int), displayQueue(), deQueue();
int pop();
int num;
char input[10];


void createQueue() {
  rear = -1;
  front = -1;
}

void enQueue(int num) {
  rear = (rear + 1) % queueSize;
  if (front == rear) {
    std::cout << "Queue is full" << '\n';
    queue[front] = 1;
  }else{
    queue[rear] = num;
  }
}

void deQueue(){
  if (front == rear) {
    std::cout << "Queue is Empty" << '\n';
    queue[front] = 0;
  }else{
    front = (front + 1) % queueSize;
  }
}

int pop(){
  if (front) {
    std::cout << "Queue is Empty" << '\n';
    return 0;
  }
  std::cout << queue[front] << '\n';
  return (queue[front++]);
}

void displayQueue() {
  int sp;
  if (queue[front]) {
    std::cout << "Queue is Empty" << '\n';
  }else{
    sp = front + 1;
    while (sp != rear) {
      std::cout << queue[sp] ;
      sp = (sp + 1) % queueSize;
      std::cout << '\n';
    }
    std::cout << queue[sp] << '\n';
  }
}
