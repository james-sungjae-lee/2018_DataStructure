#include <iostream>
using namespace std;

const int stackSize = 11;
int stack[stackSize];
int top;
void creatStack();
void push(int);
int pop();
int isFull();
int isEmpty();
void displayStack();

int main(int argc, char const *argv[]) {

  creatStack();
  for (size_t i = 1; i < 10; i++) {
    push(i);
  }
  displayStack();
  for (size_t i = 0; i < 5; i++) {
    pop();
  }
  std::cout << '\n';
  displayStack();




  return 0;
}

void creatStack(){
  top = -1;
}

int isFull(){
  if (top == stackSize - 1) {
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

void push(int num){
  ++top;
  stack[top] = num;
}

int pop(){
  if (!isEmpty()) {
    return stack[top--];
  }else{
    std::cout << "Stack is Empty!" << '\n';
  }
  return 0;
}

void displayStack(){
  int sp;
  if (isEmpty()) {
    std::cout << "Stack is Empty!" << '\n';
  }else{
    sp = top;
    while (sp != -1) {
      std::cout << stack[sp] << '\n';
      sp--;
    }
  }
}
