#include <iostream>
using namespace std;

// {Compute sum of two numbers, first and second}
// {And the result is assigned to SUM}
// BEGIN
// INPUT first and second
// sum  first + second
// END.

int main(int argc, char const *argv[]) {
  int a, b, sum;
  std::cout << "첫 번째 숫자 입력" << '\n';
  std::cin >> a;
  std::cout << "두 번째 숫자 입력" << '\n';
  std::cin >> b;
  sum = a + b;
  std::cout << sum << '\n';
  return 0;
}

// Ex) {find maximum of three numbers a,b,c}
// input a,b,c
// large:= a
// if b>large then large:= b
// if c>large then large:= c
// return large;
// Ex) Find minimum of the three numbers a,b,c
