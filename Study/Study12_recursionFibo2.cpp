#include <iostream>
using namespace std;

int fibo(int n){
  if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    return fibo(n-1) + fibo(n-2);
  }
}

int main(int argc, char const *argv[]) {
  int number;
  std::cin >> number;
  number += 1;
  for (size_t i = 1; i < number; i++) {
    std::cout << fibo(i) << '\n';
  }
  return 0;
}
