#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cout << "usage: " << argv[0] << " <filename>" << '\n';
  }else{
    ifstream the_file(argv[1]);
    if (! the_file.is_open()) {
      std::cout << "Could not open file" << argv[1] << '\n';
      return 1;
    }
    char x;
    while(the_file.get(x)){
      std::cout << x << '\n';
    }
  }
}
