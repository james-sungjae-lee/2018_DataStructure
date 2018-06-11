#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream file_reader("myfile.txt");
  if (! file_reader.is_open()) {
    std::cout << "Could not open file!" << '\n';
  }
  int number;
  file_reader >> number;
  return 0;
}
