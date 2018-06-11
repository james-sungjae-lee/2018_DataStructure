#include "lab5.hpp"

int main(int argc, char const *argv[]) {
  ifstream inStream;
  inStream.open("lab5.txt");
  string inName;
  int inWeight;
  int inHeight;

  List a;
  for (size_t i = 0; i < 5; i++) {
    inStream >> inName >> inWeight >> inHeight;
    a.insertByName(inName, inWeight, inHeight);
  }

  a.forwardList();
  std::cout << '\n';

  a.searchList("lee");
  std::cout << '\n';

  a.deleteNode("lee");

  a.backwardList();
  std::cout << '\n';

  a.findNth(3);

  inStream.close();

  return 0;
}
