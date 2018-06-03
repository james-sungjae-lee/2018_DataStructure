#include <iostream>

using namespace std;

int fact(long n){
    if(n == 1){
      return 1;
    }else{
      return n * fact(n-1);
    }
};

int permutation(int n, int r ){// 3, 2
  int k = fact(n) / (fact(n-r) * fact(r));
  return k;
};

int main(int argc, char const *argv[]) {
  int x, y;
  std::cout << "P(n,r) 의 n값 : " ;
  std::cin >> x;
  std::cout << "P(n,r) 의 r값 : " ;
  std::cin >> y;
  // calculate xCy
  if (x < y) {
    std::cout << "Error!" << '\n';
  }

  std::cout << "result : " << permutation(x,y) << '\n';
  return 0;
}

// 3 P 2 = P(n,r) = n! / (r! * (n-r)!) = 6 / 2*1 = 3.
// 순열 ? 4 C 2 == 결국 팩토리얼 연산
