#include <iostream>
#include <string>
#include <stdlib.h>

const int stackSize = 100;
typedef struct{int row; int col; int dir;}structStack;
structStack stack[stackSize];
int top;

void createStack(), push(int), traverseStack(), displayStack();
int pop(), isFull(), isEmpty();
int num;
char input[10];


void createStack() {
  top = -1;
}

int isFull(){
  if (top == stackSize -1) {
    return 1;
  }else{
    return 0;
  }
}

int isEmpty(){
  if (top == -1) {
    return 1;
  }else{
    return 0;
  }
}


void push(structStack) {
  ++top;
  struct stack[top] = structStack;
}

int pop(){
  return (stack[top--]);
}

void displayStack() {
  int sp;
  if (isEmpty()) {
    std::cout << "Stack is empty" << '\n';
  }else{
    sp = top;
    while (sp != -1) {
      std::cout << stack[sp] ;
      --sp;
    }
    std::cout << '\n';
  }
}
