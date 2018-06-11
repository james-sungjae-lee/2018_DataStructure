#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream file_reader("myfile.txt");
  if (! file_reader.is_open()) {
    std::cout << "Could not open file!" << '\n';
  }
  int number;
  if (file_reader >> number) {
    std::cout << "The value is : " << number << '\n';
  }
  return 0;
}
