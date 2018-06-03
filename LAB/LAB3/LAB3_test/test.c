#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1
#define MAX_STACK_SIZE 100 // 최대 스택 사이즈
#define MAX_EXPR_SIZE 100 // 수식 최대 사이즈
typedef enum {
LPAREN , RPAREN , PLUS, MINUS , TIMES, DIVIDE , MOD ,
LOGICAL_AND , LOGICAL_OR ,LEFT_SHIFT , RIGHT_SHIFT ,
EQUAL , NOT_EQAUL , LESS , GRATER , LESS_EQUAL , GRATER_EQUAL ,
EOS , OPERAND
} PRECEDENCE; // 우선순위
//////////////////////////////////////////////////////////////////////////
// Global Variable.
int stack[MAX_STACK_SIZE]; // 수식에 대한 스택
char expr[MAX_EXPR_SIZE]; // 수식을 저장하는 문자배열.
// in-stack precedence
const int isp[] = { 0,19,12,12,13,13,13,5,4,11,11,9,9,10,10,10,10,0 };
// incoming precedence
const int icp[] = { 20,19,12,12,13,13,13,5,4,11,11,9,9,10,10,10,10,0 };
/************************************************************************
* Function Prototype Declaration.
*************************************************************************/
int eval( void ); // 후위 표현 수식을 계산.
void stack_push( int* top , int item ); // 스택 푸쉬.
int stack_pop( int* top ); // 스택 팝
void postfix( void ); // 수식을 후위 표현으로 변환
// 후위표현으로 표현 된 수식중 연산자를 문자로 표현
void print_token( PRECEDENCE token , char** str );
// 토큰을 받아옴. 토큰의 종류
PRECEDENCE get_token( char* symbol , int* n );
//////////////////////////////////////////////////////////////////////////
// main 함수
int main ( void )
{
printf("----------------------------------₩n");
printf("| Converting infix to postfix |₩n");
printf("----------------------------------₩n₩n");
printf("수식을 입력하세요 ex : 3*9/2+3(ENTER) \nInput : ");
scanf("%s" , expr); // 수식 입력 받음
postfix(); // 후위표기로 변환
printf("₩n₩n결과 : %d ₩n₩n", eval() ); // 후위식을 계산.
return 0;
}
//////////////////////////////////////////////////////////////////////////
// 해당식을 후위 연산자로 변환




void postfix ( void )
{
char symbol; // 연산자, 피연산자
char expr_post[MAX_EXPR_SIZE] = {0,}; // 후위 표기식으로 저장하는 문자열.
char* str = expr_post; // 어디까지 읽었는지 저장하기 위한 포인터.
PRECEDENCE token; // 토큰을 받는 변수
int n = 0 , top = 0; // 문자열의 인덱스, 스택탑
// 스택의 제일 처음은 EOS
stack[0] = EOS;
// 중위 -> 후위 변환 알고리즘 책참조.
// 토큰이 EOS, 즉 문자의 끝일때 까지 반복
for ( token = get_token( &symbol , &n ) ; token != EOS ;
token = get_token( &symbol , &n ) )
{
if ( token == OPERAND ) // 피연산자라면 출력.
*str++ = symbol;
else if (token == RPAREN )
{ // 폐괄호라면.
while( stack[top] != LPAREN ) // 스택탑이 개괄호 전까지
print_token(stack_pop(&top) , &str ); // 스택의 내용을 차례대로 출력.
stack_pop(&top); // 스택의 탑 , 즉 개괄호는 버린다.
}
else {
// 폐괄호가 아니라면
// 연산자 우선순위를 검사.
// 들어오는 쪽이 스택안의 것보다 우선순위가 높거나 같을때 까지.
while ( isp[stack[top]] > icp[token] )
print_token(stack_pop(&top) , &str ); // 스택내용을 출력.
stack_push( &top , token ); // 들어갈려하는 토큰 삽입.
}
}
// 나머지 스택 내의 내용들을 문자열에 저장.
while ( (token = stack_pop(&top)) != EOS && top > -1)
print_token(token , &str );
// 후위 표현 출력.
printf("postfix expression : %s ₩n" , expr_post );
strcpy( expr , expr_post ); // 전역변수에 저장.(계산)
}






//////////////////////////////////////////////////////////////////////////
// 토큰의 종류를 반환.
PRECEDENCE get_token( char* symbol , int* n )
{
switch( *symbol = expr[(*n)++] )
{
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
case '!': // ! 뒤에 문자가 = 일경우
if ( expr[*n] =='=' ){
  ++*(n); return NOT_EQAUL; // logical not equal 연산자 반환
}
return EOS; // 그렇지 않다면 eos 반환
default : return OPERAND; // 기본값으로 피연산자 반환
}
}
//////////////////////////////////////////////////////////////////////////
// 후위표기식을 계산.
int eval(void)
{
PRECEDENCE token; // 토큰
char symbol; // 문자
int op1, op2; // 피연산자 1 ,2
int n = 0; // 문자열의 인덱스
int top = -1; // 스택탑
// 토큰을 받아옴
token = get_token( &symbol , & n );
while ( token != EOS )
{
// 피연산자라면 문자를 숫자로 변환해서 스택에 넣는다.
if( token == OPERAND )
stack_push( &top , symbol - '0' );/*문자로된 값을 숫자로 변환*/
else{
// symbol이 연산자라면
// 스택에 저장 해놨던 피연산자를 꺼내온다.
// 예를 들어 a b c + d * - 에서 ‘+’ 연산 을 하는 피연산자는
// 스택 탑과 바로 밑의 피연산자이다.
// 스택에는 밑에서 부터 a , b , c 상으로 저장 되어있는데.
// c + b 가 아니라 b + c 이기 때문에 역순으로 받아 와야 한다.
op2 = stack_pop(&top); // 두번째 피연산자.
op1 = stack_pop(&top); // 첫번째 피연산자.
switch( token )
{ // 해당연산자에 맞게 연산하여 그 결과값을 스택에 저장.
case PLUS: stack_push( &top , op1 + op2 ); break;
case MINUS: stack_push( &top , op1 - op2 ); break;
case TIMES: stack_push( &top , op1 * op2 ); break;
case DIVIDE: stack_push( &top , op1 / op2 ); break;
case MOD: stack_push( &top , op1 % op2 ); break;
case LOGICAL_AND: stack_push( &top , op1 && op2 ); break;
case LOGICAL_OR : stack_push( &top , op1 || op2 ); break;
case LEFT_SHIFT: stack_push( &top , op1 << op2 ); break;
case RIGHT_SHIFT : stack_push( &top , op1 >> op2 ); break;
case EQUAL : stack_push( &top , op1 == op2 ); break;
case NOT_EQAUL : stack_push( &top , op1 != op2 ); break;
case LESS : stack_push( &top , op1 < op2 ); break;
case GRATER: stack_push( &top , op1 > op2 ); break;
case LESS_EQUAL: stack_push( &top , op1 <= op2 ); break;
case GRATER_EQUAL: stack_push( &top , op1 >= op2 ); break;
default: break;
}
}
// 연산후 해당 문자의 토큰값을 받아온다
token = get_token( &symbol , &n );
}
// 최종 결과 값을 반환.
return stack_pop( &top ); // 결과 반환
}
//////////////////////////////////////////////////////////////////////////
// 해당 토큰에 해당하는 기호(연산자)로 문자로 삽입.
void print_token( PRECEDENCE token , char** str )
{
switch( token )
{
case PLUS: *(*str)++ = '+'; return; // +
case MINUS: *(*str)++ = '-'; return; // -
case DIVIDE: *(*str)++ = '/'; return; // /
case TIMES: *(*str)++ = '*'; return; // *
case MOD: *(*str)++ = '%'; return; // %
case LESS : *(*str)++ = '<'; return; // <
case GRATER: *(*str)++ = '>'; return; // >
// & 문자 다음에 & 문자를 하나 더 삽입 , 밑의 연산자가 2개의 공간를 차지하는 것도 같게 처리
case LOGICAL_AND: *(*str)++ = '&'; *(*str)++ = '&'; return;
case LOGICAL_OR : *(*str)++ = '|'; *(*str)++ = '|'; return; // ||
case LEFT_SHIFT: *(*str)++ = '<'; *(*str)++ = '<'; return; // <<
case RIGHT_SHIFT : *(*str)++ = '>'; *(*str)++ = '>'; return; // >>
case EQUAL : *(*str)++ = '='; *(*str)++ = '='; return; // ==
case NOT_EQAUL : *(*str)++ = '!'; *(*str)++ = '='; return; // !=
case LESS_EQUAL: *(*str)++ = '<'; *(*str)++ = '='; return; // <=
case GRATER_EQUAL: *(*str)++ = '>'; *(*str)++ = '='; return; // >=
case EOS: return;
default : return;
}
}
//////////////////////////////////////////////////////////////////////////
// 스택 푸쉬
void stack_push( int* top , int item )
{
if ( (*top) == MAX_STACK_SIZE ) fprintf(stderr , "The stack is full.₩n" ), exit(1);
stack[++(*top)] = item ;
}
//////////////////////////////////////////////////////////////////////////
// 스택 팝
int stack_pop( int* top )
{
if ( (*top) == -1 ) return EOS;
return stack[(*top)--];
}
