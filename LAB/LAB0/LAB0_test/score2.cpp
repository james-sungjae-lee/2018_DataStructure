#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream is;
  is.open("score.txt");
  if (!is) {
    std::cerr << "파일 오픈 실패" << '\n';
    exit(1);
  }
  char c;
  is.get(c);
  while (! is.eof()) {
    std::cout << c ;
    is.get(c);
  }
  is.close();
  return 0;
}
