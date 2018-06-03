// 20132651 경영학부 경영학전공 이성재
//LAB0_1_FindMinAndMaxNumber.cpp
#include <iostream>
#include <fstream>
using namespace std;

// Lab0-1: Find Min and Max numbers
// 1) Data file: 10개의 정수로 구성한다. (예: 90, 40, 60, 10, 50, 80, 20, 70, 15, 25) Lab0-1.dat
// 2) Output: Minimum number is 10 at position 4,
// Maximum number is 90 at position 1
// 다음 코드 참조

int testArr[10] = {90, 40, 60, 10, 50, 80, 20, 70, 15, 25};
int p_min = 0;
int p_max = 0;

int findMin(int data[], int n){
  int min = data[0];
  for (int i = 1; i < 10; i++) {
    if (data[i] < min) {
      min = data[i];
      p_min = i;
    }
  }
  return min;
}

int findMax(int data[], int n) {
int max = data[0];
for (int i = 1; i < n; i++){
  if (data[i] > max){
    max = data[i];
    p_max = i;
  }
}
return max;
}

int main(int argc, char const *argv[]) {
  std::cout << "Minimum number is " << findMin(testArr, sizeof(testArr)) << " at position " << p_min+1 << '\n';
  std::cout << "Maximum number is " << findMax(testArr, sizeof(testArr)) << " at position " << p_max+1 << '\n';
  std::cout << sizeof(testArr) << '\n';
  return 0;
}
