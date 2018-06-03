#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX_TERMS 101
typedef struct{
  int col;
  int row;
  int value;
}term ;

term a[MAX_TERMS];
term b[MAX_TERMS];

using namespace std;

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
  ifstream inStream;
  int numValue;

   inStream.open("lab2_1.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }
inStream >> numValue;
a[0].value = numValue;

for (size_t i = 1; i <= numValue; i++) {
  inStream >> a[i].value;
}
std::cout << '\n';
for (size_t i = 0; i <= numValue; i++) {
  inStream >> a[i].col;
}
std::cout  << '\n';
for (size_t i = 0; i <= numValue; i++) {
  inStream >> a[i].row;
}

fast_transpose(a, b, numValue);
std::cout << "row " << "  col " << "  value" <<'\n';

for (size_t i = 0; i < numValue; i++) {
  std::cout << b[i].row << "     ";
  std::cout << b[i].col << "     ";
  std::cout << b[i].value << "     ";
  std::cout << '\n';
}
  inStream.close();
  return 0;
}
