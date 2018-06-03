#include <iostream>
#define MAX_TERMS 101
typedef struct{
  int col;
  int row;
  int value;
}SMarray ;

SMarray a[MAX_TERMS];
SMarray b[MAX_TERMS];

void transpose(SMarray a[], SMarray b[]){
  int n, currentb;
  n = a[0].value;

  b[0].row = a[0].col;
  b[0].col = a[0].row;
  b[0].value = n;

  if (n > 0) {
    currentb = 1;
    for (size_t i = 0; i < a[0].col; i++) {
      for (size_t j = 0; j <= n; j++) {
        if (a[j].col == i) {
          b[currentb].row = a[j].col;
          b[currentb].col = a[j].row;
          b[currentb].value = a[j].value;
          currentb ++ ;
        }
      }
    }
  }
}
//O(col * elements)
