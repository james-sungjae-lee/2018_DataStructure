#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int stackSize = 100;
int stack[stackSize];
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


// get expression(exp);
// int check() {
// for(i=0; i<strlen(exp); i++){
// if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') push(exp[i]);
// if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
// if(stack empty) {
// print("UnBalanced ");
// print ("Right parentheses are more than left parentheses"); break;}
// else {
// temp=pop();
// if(!match(temp, exp[i])) {
// print("UnBalanced ");
// print("Mismatched parentheses are : ");
// print(temp, exp[i]); break; }
// }
// }
// if(stack empty) print("Balanced ");
// else {print("UnBalanced ");
// print ("Left parentheses are more than right parentheses); }


// ( A * B ) + ( C * D)
// ( A * ( B + ( C * D + E ) ) )
// ( ( A + B)
// ( A + B } )
// ( A + B ) - { C + D } - [ F + G ]
// { A + ( B - [ C + D ] ) * E ) }

int check(string exp);
char exp[100];

int main(int argc, char const *argv[]) {

  createStack();
  ifstream inStream;

  inStream.open("LAB3_1.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }
   for (size_t i = 0; i < 100; i++) {
     inStream >> exp[i];
   }
   check(exp);

  inStream.close();
  return 0;
}

int check(char exp[]){
  for (size_t i = 0; i < 10; i++) {
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
          std::cout << "UnBalanced" ;
          std::cout << "Mismatched parentheses are : " ;
          std::cout << temp << " " << exp[i] << '\n';
          break; // temp / exp <= 단어 넣기
        }
      }
    }
  }
  return 0;
}
