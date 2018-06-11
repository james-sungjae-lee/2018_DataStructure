#include <iostream>
#define MAX_SIZE 100
#define MAX_TERMS 101
#define SWAP(x, y, t)((t) = (x), (x) = (y), (y) = (t))
using namespace std;

void mult(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE]){
  for (size_t i = 0; i < MAX_SIZE; i++) {
    for (size_t j = 0; j < MAX_SIZE; j++) {
      c[i][j] = 0;
      for (size_t k = 0; k < MAX_SIZE; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

void transpose(int a[][MAX_SIZE]){
  int temp;
  for (size_t i = 0; i < MAX_SIZE - 1; i++) {
    for (size_t j = 0; j < MAX_SIZE; j++) {
      SWAP(a[i][j], a[j][i], temp);
    }
  }
}
