#include "LAB3_1.hpp"
#include <fstream>
#include <cstring>

using namespace std;
ifstream inStream;

int check();

int main(int argc, char const *argv[]) {
  inStream.open("LAB3_1.txt");


  if (inStream.fail()) {
    std::cerr << "파일 오픈 에러" << '\n';
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
  createStack();
  string oneLine;
  getline(inStream, oneLine);

  std::cout << oneLine << '\n';
  int k = oneLine.length();

  for (size_t i = 0; i < k; i++) {
    if (oneLine[i] == '(' || oneLine[i] =='{' || oneLine[i] == '[') {
      push(oneLine[i]);
    }

    if (oneLine[i] == ')' || oneLine[i] == '}' || oneLine[i] == ']') {
      if (isEmpty()) {
        std::cout << "틀림 : 오른쪽 연산자가 왼쪽보다 더 많음!" << '\n';
        return 0;
      }else{
        char temp = pop();

        if (temp == '(') {
          temp = ')';
        }else if(temp == '{'){
          temp = '}';
        }else{
          temp = ']';
        }

        if (oneLine[i] != temp) {
          if (temp == ')') {
            temp = '(';
          }else if(temp == '}'){
            temp = '{';
          }else{
            temp = '[';
          }
          std::cout << "틀림 : 양쪽의 연산자가 다름! : " ;
          std::cout << temp << " " << oneLine[i] << '\n';
          return 0;
        }
      }
    }
  }

  if (isEmpty()) {
    std::cout << "맞음" << '\n';
  }else{
    std::cout << "틀림 : 왼쪽의 연산자가 더 많음!" << '\n';
  }
  return 0;
}
