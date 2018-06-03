#include <iostream>
using namespace std;

int factorial(int n)
{
int fact = 1;
for (int i=1; i <= n; i++)
fact = fact*i;
return fact;
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::cout << factorial(n) << '\n';
  return 0;
}
