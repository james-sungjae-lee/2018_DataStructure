// 20132651 경영학부 경영학전공 이성재
// LAB1_2recursiveFactSum.cpp

#include <iostream>

using namespace std;

int factSum(int n){
  if (n == 1) {
    std::cout << n << " = " ;
    return 1;
  }else{
    std::cout << n << " + " ;
    return n + factSum(n-1);
  }
}
int main(int argc, char const *argv[]) {
  int num;
  std::cout << "숫자를 입력하세요 : " ;
  std::cin >> num;
  std::cout << factSum(num) << '\n';
  return 0;
}
