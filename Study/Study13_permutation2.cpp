#include <iostream>

using namespace std;

int permutation(int n, int r){
  if (n == r) {
    return 1;
  }else if(r == 1){
    return 1;
  }else{
    return permutation(n-1, r-1) * (n / ((n-r) * r));
  }
}
// 3,2 -> 2,1 // 왜안되는지 알았다. n 이 끝까지 가지 않기 때문이다.
// 이를 해결하기 위해서는, r 과 n 을 따로 계산하는 수 밖에 없겠다.
//
// 3, 2 -> 3 / 1 x 2 )) x 2, 1 = 2 / 1 x 1 = 2 = 3

int main(int argc, char const *argv[]) {
  std::cout << permutation(3, 2) << '\n';
  return 0;
}

// n! / (n-r)! * r! = n / (n-r) x r } x { n-1 / n-r-1 x r-1 }...

//
