#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// "A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called"

int str_len;
int WC;

int main(int argc, char const *argv[]) {
  ofstream output("data6.dat", ios::out | ios::binary);
  std::vector<string> in_buffer;
  in_buffer.push_back("A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called");
  output.write(reinterpret_cast<char*>(&in_buffer), sizeof(in_buffer));
  output.close();

  ifstream input("data6.dat", ios::in | ios::binary);
  std::vector<string> out_buffer;
  input.read(reinterpret_cast<char*>(&out_buffer), sizeof(out_buffer));

  std::cout << out_buffer[0] << '\n';

  return 0;
}

// 1. 띄어쓰기 + 엔터 가 있는 문장을 vector 형태의 string에 저장 : OK
// 2. 저장된 vector 를 binary 형태의 .dat 파일로 저장 : OK
// 3. 저장된 dat 파일을 불러와서 새로운 vector 형태의 string에 저장 : OK
// 4. 저장된 vector의 string 에서 한 글자씩 떼어와 분석 -> NO
// 5. 띄어쓰기가 나타나면 word ++, 엔터가 나타나면 문장과 word 출력후, word리셋
// 6. eof 이 되면 전체 word 값을 출력.
