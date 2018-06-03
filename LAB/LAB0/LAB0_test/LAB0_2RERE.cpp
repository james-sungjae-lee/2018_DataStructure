#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//구조체 정의
struct Record{
  string buffer;
};

int main(int argc, char const *argv[]) {
  // 내보내는 구조체 out_rec
  Record out_rec;
  out_rec.buffer = "A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called";

  //쓰기전용 out_file
  ofstream out_file(
    "records.dat", ios::trunc | ios::out | ios::binary
  );
  out_file.write(
    out_rec.buffer.c_str(),
    out_rec.buffer.length() + 1
  );
  out_file.close();

  //읽기전용 in_file 설정
  ifstream in_file(
    "records.dat", ios::in | ios::binary
  );

  //읽어서 저장할 구조체 in_rec
  Record in_rec;

  int str_len;
  in_file.seekg(0, ios::beg);
  if (! in_file.read(reinterpret_cast<char*>(&str_len), sizeof(str_len))) {
    std::cout << "Error" << '\n';
    return 1;
  }

  if (str_len > 0 && str_len < 10000) {
    char *p_str_buf = new char[str_len + 1];
    if (! in_file.read(p_str_buf, str_len + 1)) {
      delete[] p_str_buf;
      std::cout << "Error" << '\n';
      return 1;
    }
    if (p_str_buf[str_len] == 0) {
      in_rec.buffer = string(p_str_buf);
    }
    delete[] p_str_buf;
  }
  in_file.close();

  std::cout << in_rec.buffer;

  return 0;
}
