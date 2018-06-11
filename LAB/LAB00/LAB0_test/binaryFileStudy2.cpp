#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  char input[10000];
  strcpy(input, "A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called");
// "A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called"

  fstream file("data5.dat", ios::binary | ios::in | ios::out | ios::trunc);

  if (!file.is_open()) {
    std::cout << "Error" << '\n';
  }else{
    int length = strlen(input);
    for (size_t counter = 0; counter <= length; counter++) {
      file.put(input[counter]);
    }

    file.seekg(0);
    char ch;
    while(file.good()){
      file.get(ch);
      std::cout << ch ;
    }
  }
  return 0;
}
