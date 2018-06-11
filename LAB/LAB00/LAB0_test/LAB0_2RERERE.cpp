#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  ofstream output("data4.dat", ios::out | ios::binary);
  string buffer = "A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called";
  output.write(reinterpret_cast<char*>(&buffer), sizeof(buffer));
  output.close();

  ifstream is;
  ifstream input("data4.dat", ios::in | ios::binary);
  string in_buffer;

  if (! is.eof()) {
    for ( int i = 0; i < sizeof(input); i++) {
      input >> buffer[i];
    }
  }
  input.close();
  std::cout << buffer[2] << '\n';
  return 0;
}
