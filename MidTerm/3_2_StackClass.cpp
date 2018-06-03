#include <iostream>
using namespace std;

const int stackSize = 10;

class Stack{
private:
  int stack[stackSize];
  int top;
public:
  Stack(){top = -1;}
  void push(int val){stack[++top] = val;}
  int pop(){return stack[top--];}
  int isEmpty(){return top == -1;}
  int isFull(){return top == stackSize - 1;}
  void displayStack();
};

void Stack::displayStack(){
  int sp;
  sp = top;
  while (sp != -1) {
    std::cout << stack[sp--] << " ";
  }
  std::cout << '\n';
}

int main(int argc, char const *argv[]) {
  Stack s1;
  for (size_t i = 0; i < 10; i++) {
    s1.push(i);
  }
  s1.displayStack();
  for (size_t i = 0; i < 5; i++) {
    s1.pop();
  }
  s1.displayStack();
  return 0;
}
