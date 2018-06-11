// 20132651 경영학부 경영학전공 이성재
// LAB1_1whileSum.cpp

// Lab1: while 문을 활용한 Sum

#include <iostream>

using namespace std;

int sum(int n, int m){
  while (n != 0) {
    std::cout << n << " , " << m << '\n';
    n = n - 1;
    m = m + 1;
  }
  std::cout << n << " , " << m << '\n';
  return m;
}

int main(int argc, char const *argv[]) {
  int n, m;
  std::cout << "첫 번째 숫자 : " ;
  std::cin >> n;
  std::cout << "두 번째 숫자 : " ;
  std::cin >> m;
  std::cout << sum(n, m) << '\n';
  return 0;
}
