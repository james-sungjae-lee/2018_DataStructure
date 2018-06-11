// 20132651 경영학부 경영학전공 이성재
// LAB1_1recursiveFibonacci.cpp

#include <iostream>

using namespace std;

int fibo(int n){
  if (n == 0) {
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    return fibo(n-1) + fibo(n-2);
  }
}

int main(int argc, char const *argv[]) {
  int num;
  std::cout << "숫자를 입력하세요 : " ;
  std::cin >> num;
  num += 1;
  for (size_t i = 1; i < num; i++) {
    std::cout << fibo(i) << '\n';
  }
  std::cout << "final value is " << fibo(num - 1) << '\n';
  return 0;
}
