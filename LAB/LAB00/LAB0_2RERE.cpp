// 20132651 경영학부 경영학전공 이성재
// Lab0_2RERE.cpp

// 파일과 콘솔 입출력 헤더파일 / 스트링 활용 헤더파일을 입력.
#include<iostream>
#include<fstream>
#include<cstring>

// 네임스페이스를 std 로 설정.
using namespace std;

// 메인함수의 시작.
int main(){

// input에 char 배열을 10000 사이즈로 지정. 그 후 input 에 문자열 삽입. 이 때, 문자열의 엔터 부분은 \n 으로 변환.
char input[10000];
strcpy(input, "A program that translates a high level language to a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called");

// 파일을 내보내는 ofstream 을 fout으로 지정 후, Lab0_2.dat 파일을 바이너리, 쓰기 전용, 비우기 설정으로 오픈.
ofstream fout("LAB0_2.dat", ios::binary | ios::out | ios::trunc);

// 만약 파일이 열리지 않으면, Error 출력. 열리면, input 배열을 파일에 저장.
if (!fout.is_open()) {
  std::cout << "Error" << '\n';
}else{
  int length = strlen(input);
  for (size_t counter = 0; counter <= length; counter++) {
    fout.put(input[counter]);
  }
}
// 파일 생성 후 ofstream인 fout 닫기.
fout.close();

// 파일을 읽어오는 ifstream 을 fin으로 지정 후, 위에서 저장한 Lab0_2.dat 파일을 바이너리, 읽기 전용으로 오픈.
ifstream fin("LAB0_2.dat", ios::binary | ios::in );

// 만약 파일이 열리지 않으면, Error 출력.
if (!fin.is_open()) {
   std::cout << "Error" << '\n';
}

// 단어의 수를 세는 변수 wc, wcAll / 문자열을 임시 저장할 buf[200] / char를 가리키는 포인터 context 와 token 생성.
int wc = 0;
int wcAll = 0;
char buf[200];
char *context = NULL;
char *token;

// while(true) 로 break 가 나올 때 까지 무한반복한다.
   while (true) {
      fin.getline(buf, 200);  // fin 에서 한 줄을 읽어와, 버퍼에 200바이트 저장.
      cout << buf << endl;   // 읽어온 한 문장을 출력.

      token = strtok_r(buf, " ", &context);   // 버퍼를 읽어서 띄어쓰기가 처음 나오는 부분을 token에 저장, 나머지 문자열의 위치를 context에 저장
      while (token) { // token 에 잘라온 문자열이 존재할 경우 (아직 이 문장의 단어 세기가 끝나지 않았을 경우)
         token = strtok_r(NULL, " ", &context);   // token 에 저장 반복 (다음 토큰을 구하기 위해서는 첫 인자를 NULL로 설정해야 함.)
         wc += 1;   // 띄어쓰기가 한 개 나올때 마다 wc 를 1 늘려감.
      } // token 에 내용이 존재할 경우, while문을 작동하며, token이 NULL값을 가질 경우, while문을 끝낸다.

      cout << "The Number of Words : " << wc << endl;      //wc 출력

      wcAll += wc;      // 한 줄의 word count가 끝난 후, total word count 변수인 wcAll에 wc를 저장.
      wc = 0;            // wc 를 리셋 후 반복.

      if (fin.eof()) break;   //파일이 끝나면 반복 중단
   }

// 전체 단어의 개수를 출력 후, fin 을 닫음.
cout << endl;
cout << "Total Number of Words : " << wcAll << endl;
fin.close();

}
