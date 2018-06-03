// 20132651 경영학부 경영학전공 이성재
//LAB0_2RE.cpp

//공부할 것
//fstream 을 활용한 FILE IO
//FILE 을 dat 형태로 저장하는 것
//FILE 을 줄 단위로 읽어오는 것
//줄 단위로 읽어온 것을 출력 + 단어분석 하는 것
//분석의 결과를 출력하는 것

// 다음 데이터 파일에서 한 line씩 읽고 각 Line의 단어 개수를 출력하는 프로그램을 작성하시오
// 예) [Data File] 다음 데이터 파일 이름을 “lab0-2.dat”로 저장.
// A program that translates a high level language to a machine language
// is called a compiler. A compiler is thus a somewhat peculiar sort
// of program and its output is yet another program. To avoid confusion,
// the input program is usually called the source program or
// source code, and the translated version produced by the compiler is called

// [출력] 실행했을 경우, 다음과 같은 결과를 출력한다. /* 다음은 실행 결과임
// A program that translates a high level language to a machine language
// The number of words : 12
// is called a compiler. A compiler is thus a somewhat peculiar sort
// The number of words : 12
// of program and its output is yet another program. To avoid confusion,
// The number of words : 12
// the input program is usually called the source program or
// The number of words : 10
// source code, and the translated version produced by the compiler is called
// The number of words : 12
// Total Number of Words: 58

// While (buffer is not empty)) {
// Print One Line;
// WordCount (buffer, WC);
// Print Count (WC)
// }
// Print TotalWordCount;

// WordCount(buffer, WC)
// //Initialize pointer IN=1, OUT=0; //단어가 시작되면 state= IN이 됨
// int i = 0; int state = OUT; // 단어가 시작되지 않음
// while (buffer[i] != '\0') { //Until End of Line
// if (isalpha(buffer[i])) {
// if (state == OUT) { ++wc; state = IN;
// } //문자 이고 state=IN이면 do nothing
// else if (buffer[i] == ' ')
// state = OUT;
// i++;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// 질문1. 바이너리 파일에 문자열 넣기
// 질문2. 이러한 문장은 무엇으로 처리하는게 좋은가?
// 질문3. 바이너리 파일에서 문자열 한 줄씩 불러오기
// string에 저장. string -> binary 변환
// 벡터 - 템플릿<> - 스트링 //
//  문장 끝에 \n, list를 for문으로 돌린다.
// 스플릿 메소드 //

// int WordCount(string buffer, int WC){
//   int i = 0;
//   int state = 0;
//   while (buffer[i] != '\0') {
//     if (isalpha(buffer[i])) {
//       if (state == 0) {
//         ++WC;
//         state = 1;
//       }else if(buffer[i] == ' '){
//         state = 0;
//         i++;
//       }
//     }
//   }
// }
int WordCount(string buffer, int WC){
  int i = 0;
  int state = 0;
}

int WordPrint(string buffer){
  int i = 0;
  while (buffer[i] != '\n') {
    std::cout << buffer[i] << '\n';
  }
  return 0;
}

// 파일로 내보낼 스트링 벡터 out_buffer 와 다시 읽어올 스트링 벡터 in_buffer 입니다.
  string out_buffer = "A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called";
  int str_len; // 무언가를 위해 필요한 str_len 입니다.
  string in_buffer;

int main()
{
    //data3.dat 에 out_buffer의 내용을 binary로 저장합니다.
    ofstream os("data3.dat", ios::out | ios::binary);
    os.write(reinterpret_cast<char*>(& out_buffer), sizeof(out_buffer));
    os.close();

    //data3.dat에 저장된 내용을 읽어와 str_len에 저장합니다.
    ifstream is("data3.dat", ios::in | ios::binary);
    if (! is.read(reinterpret_cast<char*>(&str_len), sizeof(str_len))) {
      std::cout << "Error" << '\n';
      return 1;
    }
    if (str_len > 0 && str_len < 10000) {
      char *p_str_buf = new char[str_len + 1];
      if (! is.read(p_str_buf, str_len+1)) {
        delete[] p_str_buf;
        std::cout << "Error" << '\n';
        return 1;
      }
      if (p_str_buf[str_len] == 0) {
        in_buffer = string(p_str_buf);
      }
    }
    std::cout << in_buffer << '\n';
    return 0;
  }
