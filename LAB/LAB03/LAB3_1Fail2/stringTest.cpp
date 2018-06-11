#include "LAB3_1.hpp"

#include <fstream>
#include <cstdlib>

using namespace std;
ifstream inStream;

int main(int argc, char const *argv[]) {

  inStream.open("LAB3_1.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }
   string firstLine;
   getline(inStream, firstLine);
   std::cout << firstLine << '\n';

   for (size_t i = 0; i < 100; i++) {
     if (firstLine[i] == '\0') {
       std::cout << "문장 끗" << '\n';
       break;
     }
     std::cout << firstLine[i] << '\n';
   }


  inStream.close();
  return 0;
}
