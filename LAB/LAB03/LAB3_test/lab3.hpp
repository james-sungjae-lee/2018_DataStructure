#include <iostream>
#include <stdlib.h>
#include <cstring>

#define FALSE 0
#define TRUE 1
#define MAX_STACK 100
#define MAX_EXPR 100

typedef enum {
LPAREN , RPAREN , PLUS, MINUS , TIMES, DIVIDE , MOD ,
LOGICAL_AND , LOGICAL_OR ,LEFT_SHIFT , RIGHT_SHIFT ,
EQUAL , NOT_EQAUL , LESS , GRATER , LESS_EQUAL , GRATER_EQUAL ,
EOS , OPERAND
}PRECEDENCE;

int stack[MAX_STACK];
char expr[MAX_EXPR];

const int isp[] = { 0,19,12,12,13,13,13,5,4,11,11,9,9,10,10,10,10,0 };
const int icp[] = { 20,19,12,12,13,13,13,5,4,11,11,9,9,10,10,10,10,0 };

int eval(void);
void push(int* top, int item);
int pop( int* top ); // 스택 팝
void postfix(void);
void printToken( PRECEDENCE token , char** str );

PRECEDENCE temp;

PRECEDENCE getToken(char* symbol, int* n);

void postfix(void){
  char symbol;
  char expr_post[MAX_EXPR] = {0,};
  char* str = expr_post;
  PRECEDENCE token;
  int n = 0;
  int top = 0;

  stack[0] = EOS;

  for(token = getToken(&symbol, &n); token != EOS ; token = getToken(&symbol, &n)){
    if (token == OPERAND) {
      *str++ = symbol;
    }else if (token == RPAREN) {
      while (stack[top] != LPAREN)
      temp = (PRECEDENCE)pop(&top);
      printToken(temp, &str);
      pop(&top);
    }else{
      while (isp[stack[top]] > icp[token]) {
        printToken(temp, &str);
        push(&top, token);
      }
    }
  }
  temp = (PRECEDENCE)pop(&top);
  while (token != EOS && top > -1){
    printToken(temp, &str);
  }
  std::cout << "Postfix : " << expr_post << '\n';
  strcpy(expr, expr_post);
}

PRECEDENCE getToken(char* symbol, int* n){
  switch (*symbol = expr[(*n)++]) {
    case '(': return LPAREN;
    case ')': return RPAREN;
    case '+': return PLUS;
    case '-': return MINUS;
    case '/': return DIVIDE;
    case '*': return TIMES;
    case '%': return MOD;
    case '\0': return EOS;
    case '<':

    if ( expr[*n] =='<' ){ // < 뒤에 문자가 <일경우
    // 포인터를 다음 문자를 가르키고 left shift 연산자 반환
    ++*(n); return LEFT_SHIFT;
    }
    else if ( expr[*n] == '=' ) { // = 라면
    ++*(n); return LESS_EQUAL; // less or equal 연산자 반환
    }
    return LESS; // 그렇지 않다면 less then 반환.
    case '>':
    if ( expr[*n] == '>' ){ // > 뒤에 문자가 >일경우
    ++*(n); return RIGHT_SHIFT; // right shift 연산자 반환
    }
    else if ( expr[*n] == '=' ){ // = 라면
    ++*(n); return GRATER_EQUAL; // grater or equal 연산자 반환
    }
    return GRATER; // 그렇지 않다면 grater then 반환
    case '&':
    if ( expr[*n] == '&' ){ // & 뒤에 문자가 &일경우
    ++*(n); return LOGICAL_AND; // logical and 연산자 반환
    }
    return EOS;
    case '|':
    if ( expr[*n] =='|' ){ // | 뒤에 문자가 | S일경우
    ++*(n); return LOGICAL_OR; // logical or 연산자 반환
    }
    return EOS;
    case '=':
    if( expr[*n] == '=') { // = 뒤에 문자가 = 일경우
    ++*(n); return EQUAL; // logical equal 연산자 반환
    }
    return EOS;
    case '!':
    if ( expr[*n] =='=' ){
      ++*(n); return NOT_EQAUL;
    }
    return EOS;
    default : return OPERAND;
  }
}

int eval(void){
  PRECEDENCE token;
  char symbol;
  char op1, op2;
  int n = 0;
  int top = -1;

  token = getToken(&symbol, &n);
  while (token != EOS) {
    if (token == OPERAND) {
      push(&top, symbol - '0');
    }else{
      op2 = pop(&top);
      op1 = pop(&top);
      switch( token )
      {
      case PLUS: push( &top , op1 + op2 ); break;
      case MINUS: push( &top , op1 - op2 ); break;
      case TIMES: push( &top , op1 * op2 ); break;
      case DIVIDE: push( &top , op1 / op2 ); break;
      case MOD: push( &top , op1 % op2 ); break;
      case LOGICAL_AND: push( &top , op1 && op2 ); break;
      case LOGICAL_OR : push( &top , op1 || op2 ); break;
      case LEFT_SHIFT: push( &top , op1 << op2 ); break;
      case RIGHT_SHIFT : push( &top , op1 >> op2 ); break;
      case EQUAL : push( &top , op1 == op2 ); break;
      case NOT_EQAUL : push( &top , op1 != op2 ); break;
      case LESS : push( &top , op1 < op2 ); break;
      case GRATER: push( &top , op1 > op2 ); break;
      case LESS_EQUAL: push( &top , op1 <= op2 ); break;
      case GRATER_EQUAL: push( &top , op1 >= op2 ); break;
      default: break;
      }
    }
    token = getToken(&symbol, &n);
  }
  return pop(&top);
}

void printToken(PRECEDENCE token, char** str){
  switch (token) {
    case PLUS: *(*str)++ = '+'; return;
    case MINUS: *(*str)++ = '-'; return;
    case DIVIDE: *(*str)++ = '/'; return;
    case TIMES: *(*str)++ = '*'; return;
    case MOD: *(*str)++ = '%'; return;
    case EOS: return;
    default : return;
  }
}

void push(int* top, int item){
  if ((*top) == MAX_STACK) {
    std::cerr << "Stack is Full!" << '\n';
    exit(1);
  }
  stack[++(*top)] = item;
}

int pop(int* top){
  if ((*top) == -1) {
    return EOS;
  }
  return stack[(*top)--];
}
