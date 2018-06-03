#include <iostream>
using namespace std;

// ex) Find sum of first n odd numbers (n개 홀수의 합)
// procedure find_odd
// begin
// sum <- 0
// i  1
// input n
// while i ≤ n do
// begin
// sum  sum + i ;
// i  i+2
// end
// output sum
// end

int main(int argc, char const *argv[]) {
  int sum = 0;
  int i = 1;
  int n;
  std::cin >> n;
  while (i <= n) {
    sum += i;
    i += 2;
  }
  std::cout << sum << '\n';
  return 0;
}
