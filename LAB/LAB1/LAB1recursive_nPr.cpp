#include <iostream>

using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7};

void swap(int *a, int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}


void arr2(int s){
  for (size_t i = 0; i < s; i++) {
    std::cout << arr[i];
  }
  std::cout << '\n';
}

void nPr(int n, int r, int depth){
  if (r == depth) {
    arr2(depth);
    return;
  }

  for (size_t i = depth; i < n; i++) {
    swap(&arr[i], &arr[depth]);
    nPr(n, r, depth + 1);
    swap(&arr[i], &arr[depth]);
  }
}

int main(int argc, char const *argv[]) {
  nPr(sizeof(arr)/sizeof(int), 3, 0);
  return 0;
}
