#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX_TERMS 100
using namespace std;
typedef struct{
  string type;
  float a;
  float b;
}term ;

term a[MAX_TERMS];

using namespace std;
int main(int argc, char const *argv[]) {
  ifstream inStream;

   inStream.open("lab2.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

std::cout << fixed;
cout.precision(2);

for (size_t i = 0; i < 7; i++) {
  inStream >> a[i].type;
  string k = a[i].type;
  if ( k == "circle") {
    inStream >> a[i].a;
    std::cout << k << " ";
    std::cout << a[i].a << "             ";
    std::cout << 3.14 * a[i].a * a[i].a << '\n';
    std::cout << '\n';
  }else if(k == "triangle"){
    std::cout << k << " ";
    inStream >> a[i].a;
    inStream >> a[i].b;
    std::cout << a[i].a << " ";
    std::cout << a[i].b << "     ";
    std::cout << (a[i].a * a[i].b)/ 2 << '\n';
    std::cout << '\n';
  }else{
    std::cout << k << " ";
    inStream >> a[i].a;
    inStream >> a[i].b;
    std::cout << a[i].a << " ";
    std::cout << a[i].b << "    ";
    std::cout << a[i].a * a[i].b << '\n';
    std::cout << '\n';
  }
}
  inStream.close();
  return 0;
}
