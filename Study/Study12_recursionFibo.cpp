#include <iostream>
using namespace std;

// i = 0 -> 1 -> 1 -> 2 -> 3 -> 5 ->...
// fibo 함수에 n 을 넣는다.
// i = n 이면 멈춘다.
// i = 0 에서 시작한다. // 지날수록 i++ 된다.
//
//

int fibo(int n){
  if(n==0){
    return 0;
  }else if(n==1){
    return 1;
  }else{
    return fibo(n-1) + fibo(n-2);
  }
}

int main(int argc, char const *argv[]) {
  int number;
  std::cin >> number;
  std::cout << fibo(number) << '\n';
  return 0;
}

// int point = 0;
// int number = 10;
// int a;

// int fibo(int k){
//   if (point == number) {
//     return a;
//   }else{
//     point++;
//     return fibo(point);
//   }
// }

// 다르게 접근하자. n 번째 피보나치 수열은
// n-1 번째 까지의 피보나치 수열


// int fibo (int arr[], int i){
//
//   if(i == fibo_num){
//     return arr[i-1];
//   }else{
//     arr[i] = arr[i-1] + arr[i-2];
//     i ++;
//     return (fibo(i));
//   }
// // }
// int main(int argc, char const *argv[]) {
//   std::cin >> fibo_num;
//   int arr[fibo_num];
//   std::cout << fibo(arr, fibo_num) << '\n';
//   return 0;
// }


// n 번째 피보나치 수열을 구하시오
// n 을 넣으면, 피보나치 수열을 1부터 구하다가,
// n 번째 피보나치 수열에 도달했을 때,
// 재귀를 멈추고 n 번째 피보나치 수열을 반환함.

// n == 1 -> arr[0] = 0; // arr[1] = 1;
// n == 2 -> arr[2] = arr[1] + arr[0];
// ...
// n == n -> arr[n] = arr[n-1] + arr[n-2];

// i = n 이면 반환
// 그 전까지는 arr i 를 "재귀로" 구함.
//
