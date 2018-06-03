#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int stackSize = 100;
char stack[stackSize];
int top;

void createStack(), push(int), traverseStack(), displayStack();
char pop(), isFull(), isEmpty();
int num;
char input[10];

void createStack() {
  top = -1;
}

char isFull(){
  if (top == stackSize -1) {
    return 1;
  }else{
    return 0;
  }
}

char isEmpty(){
  if (top == -1) {
    return 1;
  }else{
    return 0;
  }
}


void push(int num) {
  ++top;
  stack[top] = num;
}

char pop(){
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

int check(char exp[]){
  for (size_t i = 0; i < strlen(exp); i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      push(exp[i]);
    }

    if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if (isEmpty()) {
        std::cout << "UnBalanced" << '\n';
        std::cout << "Right parentheses are more than left parentheses" << '\n';
      }else{
        char temp = pop();
        if (temp != exp[i]) {
          std::cout << "UnBalanced" << " ";
          std::cout << "Mismatched parentheses are : " ;
          std::cout << temp << " " << exp[i] << '\n';
          break;
        }
      }
    }
  }
  if (isEmpty()) {
    std::cout << "Balanced" << '\n';
  }else{
    std::cout << "UnBalanced " ;
    std::cout << "Left parentheses are more than right parentheses" << '\n';
  }
  return 0;
}

int main(int argc, char const *argv[]) {

    createStack();

    ifstream inStream;

    inStream.open("LAB3_1.txt");

     if (inStream.fail()) {
       std::cerr << "Input file opening failed." << '\n';
       exit(1);
     }

// 1. 파일에서 한 문장 읽어오기. 읽어온 문장은 배열로 저장학.
// 2. 배열을 check 에 넣고 검사하기
// 3. 다음 문장 반복하기.
// 4. 파일이 끝났으면 종료
string line;
  while (getline(inStream, line)) {
    std::cout << line << "  ";
    char myArray[line.size()+1];
    strcpy(myArray, line.c_str());
    check(myArray);
  }

  return 0;

  inStream.close();
}
