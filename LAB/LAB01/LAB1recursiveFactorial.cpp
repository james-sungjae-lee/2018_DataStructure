#include <iostream>

using namespace std;

int fact(int n){
  if (n == 1) {
    return 1;
  }else{
    return n + fact(n-1);
  }
}

int main(int argc, char const *argv[]) {
  int num;
  std::cout << "몇 팩토리얼을 계산하나요? : " << '\n';
  std::cin >> num;
  std::cout << num << " 팩토리얼을 계산합니다." << '\n';
  std::cout << fact(num) << '\n';
  return 0;
}
