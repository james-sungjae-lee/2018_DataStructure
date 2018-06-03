#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
  ofstream file_writer("highscore2.txt", ios::app);
  if (!file_writer.is_open()) {
    std::cout << "Could not open file!" << '\n';
    return 0;
  }
  for (size_t i = 0; i < 10; i++) {
    file_writer << 10 - i << '\n';
  }
}
