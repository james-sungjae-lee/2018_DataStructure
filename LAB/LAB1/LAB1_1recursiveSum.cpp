// 20132651 경영학부 경영학전공 이성재
// LAB1_1recursiveSum.cpp

#include <iostream>

using namespace std;

int sum(int n, int m){
  if (n == 0) {
    std::cout << n << " , " << m << '\n';
    std::cout << "두 수의 합은 : " ;
    return m;
  }else{
    std::cout << n << " , " << m << '\n';
    return sum(n-1, m+1);
  }
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
