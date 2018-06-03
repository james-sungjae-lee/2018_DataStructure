#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int WordCount(string buffer){
  int WC = 0;
  for (size_t i = 0; i < sizeof(buffer)/sizeof(buffer[0]); i++) {
    if (buffer[i] == '\n') { // 줄바꿈을 만났을 때,
      std::cout << WC << '\n'; // WC 를 출력합니다.
      if (buffer[i] == ' ') {
        ++WC;
      }else{
        std::cout << buffer[i];
      }
    }
  }
  return 0;
}

string buffer1 = "abc def\n abcabc\n af af awef";

int main(int argc, char const *argv[]) {
  std::cout << WordCount(buffer1) << '\n';
  return 0;
}
