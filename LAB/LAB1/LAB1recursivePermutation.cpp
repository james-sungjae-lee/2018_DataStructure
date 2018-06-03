#include <iostream>

using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7};

void swap(int *a, int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void arr2(){
  for (size_t i = 0; i < sizeof(arr) /sizeof(int); i++) {
    std::cout << arr[i];
  }
  std::cout << '\n';
}

void permutation(int n, int r){
  if (r == 0) {
    arr2();
    return;
  }

  for(int i = n-1 ; i>=0; i--) {
    swap(&arr[i], &arr[n-1]);
    permutation(n-1, r-1);
    swap(&arr[i], &arr[n-1]);
  }
}

int main(int argc, char const *argv[]) {

  permutation( sizeof(arr) / (sizeof(int)), sizeof(arr) / sizeof(int));
  return 0;
}
