#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  ofstream os;
  os.open("test.txt");
  char c;
  while (cin.get(c)) {
    os.put(c);
  }
  os.close();
  return 0;
}
