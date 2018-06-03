#include <iostream>
using namespace std;



int main(int argc, char const *argv[]) {
  typedef struct{int vert; int horiz;}offsets;
  offsets a[9];
  a[0].vert = 1;
  std::cout << a[0].vert << '\n';
  return 0;
}
