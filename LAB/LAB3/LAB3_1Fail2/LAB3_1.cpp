#include "LAB3_1.hpp"
#include <fstream>
#include <cstdlib>

using namespace std;
ifstream inStream;

int check();

int main(int argc, char const *argv[]) {

  inStream.open("LAB3_1.txt");

  createStack();

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }
   for (size_t i = 0; i < 6; i++) {
     check();
     std::cout << '\n';
   }

  inStream.close();
  return 0;
}

int check(){
  string oneLine;
  getline(inStream, oneLine);
  std::cout << oneLine << '\n';
  int k = oneLine.length();

  for (size_t i = 0; i < k; i++) {
    if (oneLine[i] == '(' || oneLine[i] == '{' || oneLine[i] == '[') {
      push(oneLine[i]);
    }

    if (oneLine[i] == ')' || oneLine[i] == '}' || oneLine[i] == ']') {
      if (isEmpty()) {
        std::cout << "Unbalanced!" << '\n';
        std::cout << "Right parentheses are more than left parentheses!" << '\n';
        break;
      }else{
        char temp = pop();
        std::cout << temp << '\n';
        std::cout << oneLine[i] << '\n';

        if (temp == '(') {
          temp = ')';
        }else if(temp == '{'){
          temp = '}';
        }else{
          temp = ']';
        }

        if (oneLine[i] != temp) {
          std::cout << "Unbalanced!" << '\n';
          std::cout << "Mismatched parentheses are :";
          std::cout << temp << " and " << oneLine[i] << '\n';
          break;
        }
      }
    }
  }

  if (isEmpty()) {
    std::cout << "Balanced!" << '\n';
  }else{
    std::cout << "Unbalanced!" << '\n';
    std::cout << "Left parentheses are more than right parentheses!" << '\n';
  }















  return 0;
}
