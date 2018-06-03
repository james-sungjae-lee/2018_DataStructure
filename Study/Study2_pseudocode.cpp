#include <iostream>
using namespace std;

// Ex) {find maximum of three numbers a,b,c}
// input a,b,c
// large:= a
// if b>large then large:= b
// if c>large then large:= c
// return large;

int main(int argc, char const *argv[]) {
  int arr[10] = {1, 2, 3, 4, 5, 6, 99, 10};
  int max = 0;
  for (size_t i = 0; i < 10; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  std::cout << max << '\n';
  return 0;
}
