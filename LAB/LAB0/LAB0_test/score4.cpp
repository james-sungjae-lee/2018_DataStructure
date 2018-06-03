#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  ifstream is;
  ofstream os;
  is.open("score.txt");
  if (is.fail()) {
    std::cerr << "파일 오픈 실패" << '\n';
    exit(1);
  }
  os.open("result2.txt");
  if (os.fail()) {
    std::cerr << "파일 오픈 실패" << '\n';
    exit(1);
  }
  char c;
  int line_number = 1;
  is.get(c);
  os << line_number << ": ";
  while (! is.eof()) {
    os << c;
    if (c == '\n') {
      line_number ++;
      os << line_number << ": ";
    }
    is.get(c);
  }
  is.close();
  os.close();
  return 0;
}
// 중요한 점! 한 디렉터리 안에 결과값으로 나타나는 동일명의 파일이 있다면
// 정상적으로 출력되지 않는다.
