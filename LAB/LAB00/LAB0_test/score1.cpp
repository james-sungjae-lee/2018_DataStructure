#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream is;
  is.open("score.txt");
  if (!is) {
    std::cerr << "파일 오픈 실패" << endl;
    exit(1);
  }
  int number;
  char name[30];
  int score;
  is >> number >> name >> score;

  ofstream os;
  os.open("result.txt");
  os << number << " " << name << " " << score << endl;

  is.close();
  os.close();
  return 0;
}
// 중요한 점!! File IO 는 atom 에서 항상 입, 출력을 file 이 존재하는 위치에서 실행하여야 한다.
// 다른 디렉토리에서 실행시키면 제대로 작동하지 않는다. 읽거나 쓰는 파일의 위치는 실행위치이다.
