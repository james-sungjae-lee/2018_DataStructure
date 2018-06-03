#include <iostream>

using namespace std;

// n 번째 까지의 피보나치 수열을 출력하는 프로그램
// 피보나치 : 이전 수와 새로운 수의 합.
// 1, 1, 2, 3, 5, 8, 13, 21, 34...
// 0, 1, 2, 5,

// int arr[];
// arr[0] = 1;
// arr[1] = 0 + 1;
// arr[2] = arr[1] + arr[0] = 2;
// arr[3] = arr[2] + arr[1] = 2 + 1 = 3;
// ...
// arr[n] = arr[n-1] + arr[n-2]


int fibo(int n){
  int m = 0;
  if (m < 0) {
    return m;
  }
  return fibo(m);
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::cout << fibo(n) << '\n';
  return 0;
}
