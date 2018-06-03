#include <iostream>
using namespace std;

// Ex) Find minimum of the three numbers a,b,c

int main(int argc, char const *argv[]) {
  int a, b, c, min;
  std::cout << "3개의 숫자를 입력하세요 : " << '\n';
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;

min = a;

if (min > b) {
  min = b;
}
if (min > c) {
  min = c;
}
std::cout << "최솟값은 : " << min << '\n';

  return 0;
}
