// *********************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : stack.hpp
// * Description: 미로 문제를 해결하기 위한 스택 자료구조를 헤더파일로 만든 것입니다.
// * Variables
// * a, b, c: 3개의 값을 받아서 저장하는 스택. 미로의 row, col, dir 값을 받음.
// * top : 스택의 현재 위치, 즉 스택이 쌓인 양을 측정하는 변수.
// * stackSize: 스택의 크기를 지정하는 고정변수.
// * stack[][]: 3개의 값을 저장하는 2차원 배열 구조의 스택.
// * 현재 위치인 top은 행의 역할을, 그리고 각 행에 대해 0, 1, 2번째 인덱스에
// * 스택으로 받아온 3개의 값 a, b, c 가 들어가게 된다.
// **********************************************************

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

const int stackSize = 100;
int top;
int a, b, c;

void createStack(), push(int a, int b, int c), displayStack();
int pop0(),pop1(),pop2(), topMinus();
int isFull(), isEmpty();
int stack[stackSize][stackSize];

// **********************************************************
// * function: void createStack
// * description: 스택을 만드는 함수
// * variables
// * top : 스택의 현재 위치를 -1로 초기화.
// **********************************************************

void createStack(){
  top = -1;
}

// **********************************************************
// * function: int isFull
// * description: 현재 스택이 가득 찬 상태인지 판별하는 함수.
// * variables
// * top 과 stackSize - 1: 두 변수를 비교하여 같으면 가득 참,
// * 다르면 가득 차지 않음을 1과 0값을 return 하여 나타냄.
// **********************************************************

int isFull(){
  if (top == stackSize - 1) {
    return 1;
  }else{
    return 0;
  }
}

// **********************************************************
// * function: int isEmpty
// * description: 현재 스택이 빈 상태인지 판별하는 함수.
// * variables
// * top : 현재 스택의 위치를 판별하여, 바닥값인 -1 의 경우 스택이 비었다는
// * 의미로 1을 return. 그렇지 않으면 0을 return.
// **********************************************************

int isEmpty(){
  if (top == -1) {
    return 1;
  }else{
    return 0;
  }
}

// **********************************************************
// * function: void push
// * description: 현재 스택에 3개의 int 값을 차례로 넣는 함수.
// * variables
// * top: 우선 스택에 값을 넣었다는 의미로 스택의 위치를 한 칸 높여준다.
// * stack[top][0](그리고 [1],[2]): top 행의 0, 1, 2번째 칸에
// * 외부로부터 받아온 a, b, c의 변수 값을 넣는다.
// **********************************************************

void push(int a, int b, int c){
  ++top;
  stack[top][0] = a;
  stack[top][1] = b;
  stack[top][2] = c;
}
// **********************************************************
// * function: int pop0, int pop1, int pop2
// * description: 현재 위치의 스택에서 각각 0, 1, 2번째 값을 뽑아옴.
// * variables
// * top: 현재 뽑아오고자 하는 가장 상단의 스택의 위치.
// * stack[top][0](그리고 [1], [2]): 각각의 위치의 값을 뽑아온다.
// **********************************************************

int pop0(){
  return (stack[top][0]);
}
int pop1(){
  return (stack[top][1]);
}
int pop2(){
  return (stack[top][2]);
}

// **********************************************************
// * function: int topMinus
// * description: top 의 위치를 1칸 아래로 변화시켜 줌.
// * variables
// * top: 변화시키고자 하는 현재 상단의 위치.
// * 기존의 pop() 함수의 경우, 1개의 변수만을 뽑아오므로 pop과 함께 사용이
// * 가능했지만, pop을 3가지로 나누어서 사용할 경우, top 값을 변화시키는
// * 새로운 함수가 필요하다고 생각하여 만들었습니다.
// **********************************************************

int topMinus(){
  top--;
  return 0;
}
