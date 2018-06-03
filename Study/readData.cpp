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

  inStream.close();
  return 0;
}
