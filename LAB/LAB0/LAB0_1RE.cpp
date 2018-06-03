//20132651 경영학부 경영학전공 이성재
//LAB0_1RE.cpp

// 파일과 콘솔 입출력 스트림을 헤더파일로 설정한다.
#include <iostream>
#include <fstream>

// 네임스페이스는 std를 기본으로 설정한다.
using namespace std;

// Lab0-1: Find Min and Max numbers
// 1) Data file: 10개의 정수로 구성한다. (예: 90, 40, 60, 10, 50, 80, 20, 70, 15, 25) Lab0-1.dat
// 2) Output: Minimum number is 10 at position 4,
// Maximum number is 90 at position 1

// 최댓값과 최솟값의 위치를 나태내는 변수를 p_min, p_max로 설정한다.
int p_min = 0;
int p_max = 0;

// data 배열과 배열 요소의 크기를 받아와 최솟값을 출력하는 findMin함수를 정의한다.
int findMin(int data[], int n){
  int min = data[0];  // 우선 최솟값 변수를 min으로 설정하고, 받아온 배열의 첫 인자를 대입한다.
  for (int i = 0; i < n; i++) { // 배열의 두 번째 인자부터 n번째 인자까지 min과 비교하며, 작을 경우 min에 대입한다.
    if (data[i] < min) {
      min = data[i];
      p_min = i+1;  // 이 때, 현재까지의 최솟값이 된 min의 위치는 i+1 번째이므로, 이를 p_min에 저장한다.
    }
  }
  return min; // findMin의 결과값으로 배열 전체의 최솟값인 min을 반환한다.
}

// data 배열과 배열 요소의 크기를 받아와 최댓값을 출력하는 findMax함수를 정의한다.
int findMax(int data[], int n){
  int max = data[0];  // 우선 최댓값 변수를 max로 설정하고, 받아온 배열의 첫 인자를 대입한다.
  for (int i = 0; i < n; i++) { // 배열의 두 번째 인자부터 n번째 인자까지 max와 비교하며, 클 경우 max에 대입한다.
    if (data[i] > max) {
      max = data[i];
      p_max = i+1;  // 이 때, 현재까지의 최댓값이 된 max의 위치는 i+1 번째이므로, 이를 p_max에 저장한다.
    }
  }
  return max; // findMax의 결과값으로 배열 전체의 최댓값인 max를 반환한다.
}

// 바이너리 데이터 파일을 읽고 쓸 메인 함수를 구현한다.
int main(int argc, char const *argv[]) {

  // 파일을 내보내기 위한 ofstream 으로 ouput을 정의하고, LAB0_1.dat 파일을 바이너리, 쓰기, 비우기 형식으로 읽어온다.
  ofstream output("LAB0_1.dat", ios::out | ios::binary | ios::trunc);
  int out_arr[] = {90, 40, 60, 10, 50, 80, 20, 70, 15, 25}; //내보낼 내용의 배열을 out_arr로 설정하고, 작성한다.
  output.write((char*)out_arr, sizeof(out_arr));  // out_arr를 write 함수를 이용해 파일에 입력한다.
  output.close(); // 파일을 닫는다.

  int in_arr[sizeof(out_arr)/sizeof(out_arr[0])]; // 배열을 읽어와 저장할 곳으로 in_arr를 정의하고, 크기를 out_arr와 맞춘다.
  ifstream input("LAB0_1.dat", ios::in | ios::binary);  //파일을 읽어오기 위한 ifstream 으로 input을 정의하고, LAB0_1.dat파일을 바이너리, 읽기 형식으로 읽어온다.
  input.read((char*)in_arr, sizeof(in_arr));  // 파일의 내용을 read로 읽어와 in_arr에 저장한다.
  input.close();  // 파일을 닫는다.

  //findMin 과 findMax 함수에 읽어온 배열, in_arr 와 in_arr의 크기를 넣어 최댓값과 최솟값을 계산한다.
  std::cout << "Minimum number is " << findMin(in_arr, sizeof(in_arr)/sizeof(in_arr[0])) << " at position " << p_min << '\n';
  std::cout << "Maximum number is " << findMax(in_arr, sizeof(in_arr)/sizeof(in_arr[0])) << " at position " << p_max << '\n';

  return 0;
}
