#include <iostream>

using namespace std;

int n_fibo;

int fibo(int n){
  int arr[n];
  arr[0] = 0;
  arr[1] = 1;
  for (size_t i = 2; i < n; i++) {
    arr[i] = arr[i-2] + arr[i-1];
    std::cout << arr[i] << '\n';
  }
  return arr[n-1];
}

int main(int argc, char const *argv[]) {
  std::cin >> n_fibo;
  std::cout << fibo(n_fibo) << '\n';
  return 0;
}
