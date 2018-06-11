// 20132651 경영학부 경영학전공 이성재
//LAB0_2_WordCountAlgorithm.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//공부할 것
//fstream 을 활용한 FILE IO
//FILE 을 dat 형태로 저장하는 것
//FILE 을 줄 단위로 읽어오는 것
//줄 단위로 읽어온 것을 출력 + 단어분석 하는 것
//분석의 결과를 출력하는 것
int main(int argc, char const *argv[]) {
  ofstream out("test.txt");
  	string s;
    if (out.is_open()) {
    out << "A program that translates a high level language to a machine language
    is called a compiler. A compiler is thus a somewhat peculiar sort
    of program and its output is yet another program. To avoid confusion,
    the input program is usually called the source program or
    source code, and the translated version produced by the compiler is called"
  	}
  return 0;
}

//
// while (buffer != OUT) {
//   std::cout << (First Line) << '\n';
//   WordCount (buffer, WC);
//   std::cout << Count(WC) << '\n';
// }
//
// std::cout << TotalWordCount << '\n';
//
// int WordCount(int buffer[], int WC){
//   int i = 0;
//   int OUT = 0;
//   int IN = 1;
//   int state = OUT; // 단어가 시작되지 않음
//   while (buffer[i] != '\0') { //Until End of Line
//   if (isalpha(buffer[i])) {
//   if (state == OUT) { ++WC; state = IN;
//   } //문자 이고 state=IN이면 do nothing
//   else if (buffer[i] == ' ')
//   state = OUT;
//   i++;
//   }
// };
//
// //Initialize pointer IN=1, OUT=0; //단어가 시작되면 state= IN이 됨
