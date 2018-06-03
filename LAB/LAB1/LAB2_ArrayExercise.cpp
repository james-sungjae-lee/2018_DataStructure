// Read matrix A from datafile (lab2-1.txt) and store into array
//  Transpose Matrix A into Matrix B
//  Printout Matrix B from the Array
// 매트릭스 A 로 읽어서, B 로 출력하라

#include <iostream>
#define MAX_TERMS 101
typedef struct{
  int col;
  int row;
  int value;
}term ;

term a[MAX_TERMS] ;
term b[MAX_TERMS];



void fast_transpose(term a[], term b[], int MAX_COL){
  int row_terms[MAX_COL], starting_pos[MAX_COL];
  int num_cols = a[0].col, num_terms = a[0].value;

  b[0].row = num_cols;
  b[0].col = a[0].row;
  b[0].value = num_terms;

  if (num_terms > 0) {
    for (size_t i = 0; i < num_cols; i++) {
      row_terms[i] = 0;
    }
    for (size_t i = 1; i < num_terms; i++) {
      row_terms[a[i].col]++;
    }

    starting_pos[0] = 1;

    for (size_t i = 1; i < num_cols; i++) {
      starting_pos[i] = starting_pos[i-1] + row_terms[i-1];
    }
    for (size_t i = 1; i <= num_cols; i++) {
      int j = starting_pos[a[i].col]++;
      b[j].row = a[i].col;
      b[j].col = a[i].row;
      b[j].value = a[i].value;
    }
  }
}

int main(int argc, char const *argv[]) {

  for (size_t i = 0; i < 10; i++) {
    for (size_t j = 0; j < 10; j++) {
      std::cout << a.col[i] << '\n';
    }
  }
  return 0;
}
//O(columns + elements)
