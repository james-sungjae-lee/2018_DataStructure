#include <iostream>
using namespace std;

int factorial (int n)
{
if (n == 0) return 1; /* anchor (종료조건)*/
else return (n*factorial(n-1)); /* recursive step(순환호출) */
}


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::cout << factorial(n) << '\n';
  return 0;
}
