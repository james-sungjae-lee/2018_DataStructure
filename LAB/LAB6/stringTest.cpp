#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


int main(int argc, char const *argv[]) {
  string a = "kim";
  string b = "lee";

  if (a.compare(b) < 0) {
    std::cout << "true" << '\n';
  }else{
    std::cout << "false" << '\n';
  }

  return 0;
}
