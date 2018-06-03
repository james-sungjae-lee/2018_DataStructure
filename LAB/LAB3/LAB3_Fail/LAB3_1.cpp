#include <iostream>
#include <string>
#include <stdlib.h>

const int stackSize = 100;
int stack[stackSize];
int top;

void createStack(), push(int), traverseStack(), displayStack();
int pop(), isFull(), isEmpty();
int num;
char input[10];

int main(int argc, char const *argv[]) {
  createStack();

  while (1) {
    std::cout << "Enter command(push, pop, traverse, exit) : " << '\n';
    std::cin >> input;

    if (strcmp(input, "push") == 0) {
      if (!isFull()) {
        std::cout << "Enter an integer to push : " << '\n';
        std::cin >> num;
        push(num);
      }else{
        std::cout << "Stack is Full" << '\n';
      }
    }else if(strcmp(input, "pop") == 0){
      if (!isEmpty()) {
        num = pop();
        std::cout << num << "is popped" << '\n';
      }else{
        std::cout << "Stack is empty" << '\n';
      }
    }else if (strcmp(input, "traverse") == 0) {
      displayStack();
    }
else if (strcmp(input, "exit") == 0) {
      exit(0);
    }
    else{
      std::cout << "Bad Command!" << '\n';
    }
  }
  return 0;
}

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
  if (top == 01) {
    return 1;
  }else{
    return 0;
  }
}


void push(int num) {
  ++top;
  stack[top] = num;
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
