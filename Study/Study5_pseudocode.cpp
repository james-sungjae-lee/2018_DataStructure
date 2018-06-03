#include <iostream>
using namespace std;

// ex) Testing whether a positive integer is prime
// procedure is_prime(m)
// for i=2 to m-1 do
// if m MOD i=0 then return false
// else return(true)
// end is_prime.

int main (int argc, char const *argv[]) {
  int m;
  std::cin >> m;
  for (size_t i = 2; i < m-1; i++) {
    if (m % i == 0) {
      std::cout << "소수가 아님" << '\n';
      break;
    }else{
      std::cout << "소수임" << '\n';
      break;
    }
  }
}
