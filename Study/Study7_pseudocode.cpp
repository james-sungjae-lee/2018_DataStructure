#include <iostream>
using namespace std;

// Ex) Find largest in a finite sequence (while loop)
// procedure find_large (s,n)
// begin
// large := s1
// i:=2
// while i ≤ n do
// begin
// if si >large then large := si
// i:= i+1
// end
// return(large)
// end find_large

int main (int argc, char const *argv[]) {
  int arr[10] = {1, 2, 3, 4, 5, 10, 20, 30, 40};
  int i = 2;
  int large = arr[0];
  int n = 0;
  std::cin >> n;

  while (i <= n) {
    if (arr[i] > large) {
      large = arr[i];
      i += 1;
    }
  }
  return large;
}
