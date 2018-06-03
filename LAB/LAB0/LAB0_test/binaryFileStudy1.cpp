// 바이너리 파일을 만들고, array 데이터를 입력한다.
// 파일을 불러와 읽고, 출력한다.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  int testArr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  fstream a_file(
    "Study1.bin",
    ios::trunc | ios::binary | ios::in | ios::out
  );

  a_file.write(reinterpret_cast<char*>(testArr1), sizeof(testArr1));

  int testArr2[10];

  a_file.read((char*)testArr2, sizeof(testArr2));

  // if (! a_file.read(reinterpret_cast<char*>(&testArr2), sizeof(&testArr2))){
  //   std::cout << "Error" << '\n';
  //   return 1;
  // }
  std::cout << "testArr1[6]: "<< testArr1[6] << '\n';
  std::cout << "testArr2[6]: "<< testArr2[6] << '\n';

}
