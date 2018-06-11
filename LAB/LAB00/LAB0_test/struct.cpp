#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
  struct Score{
    int number;
    char name[30];
    int score;
  }
  grades[]={{1, "a", 10}};

  ofstream os;
  os.open("test2.dat", ofstream::binary);
  if (os.fail()) {
    std::cout << "test2.dat 파일을 열 수 없습니다." << '\n';
    exit(1);
  }
  os.write((char *)&grades, sizeof(grades));
  os.close();
  return 0;
}
