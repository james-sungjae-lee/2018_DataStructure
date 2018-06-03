#include <iostream>
using namespace std;

// Ex) finding a prime larger then a given integer
// procedure large_prime(n)
// m=n+1
// while not(is_prime(m)) do
// m=m+1
// return m
// end large_prime

int is_prime () {
  int m;
  std::cin >> m;
  for (size_t i = 2; i < m-1; i++) {
    if (m % i == 0) {
      std::cout << "소수가 아님" << '\n';
      return 0;
    }else{
      std::cout << "소수임" << '\n';
      return 1;
    }
  }
}

int main(int argc, char const *argv[]) {
  int x;
  is_prime(x);
  return 0;
}
