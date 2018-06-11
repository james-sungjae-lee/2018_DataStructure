#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
  ofstream os;
  char c;
  os.open("score.txt");
  while (cin.get(c)) {
    os.put(c);
  }
  os.close();
  return 0;
}
