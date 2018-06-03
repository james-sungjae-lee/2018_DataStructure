// *********************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW2_StudentRoster.hpp
// *
// * Description
// * : 헤더파일의 포함
// * : iostream : cout 을 이용해 콘솔에 결과값을 출력하기 위한 헤더파일입니다.
// * : fstream : ifstream 을 이용해 data1.txt 와 data2.txt 로부터 데이터를 읽어오기 위한 헤더파일입니다.
// * : cstring : string을 이용해 학생 데이터의 grade변수를 처리하기 위한 헤더파일입니다.
// *
// * : 함수의 프로토타입 정의
// * : readData1 / readData2 : 텍스트 데이터파일을 읽기 위한 함수입니다.
// * : concatenateList : 두 개의 리스트를 합치기 위한 함수입니다.
// * : List::insertByNameNode : 노드를 이름의 알파벳순으로 리스트에 저장하는 함수입니다.
// * : List::displayNode : 현재 리스트의 모든 노드를 차례로 출력하는 함수입니다.
// * : List::displayGradeNode(char selectGrade) 특정 Grade에 해당하는 노드만 출력하는 함수입니다.
// * : List::displayMajorNode(string selectMajor) 특정 Major에 해당하는 노드만 출력하는 함수입니다.
// * : List(){head = NULL} : 리스트를 최초 정의할 때, head값을 NULL로 지정합니다.
// *
// * : 변수의 정의
// * : Node -> name : 학생 데이터의 이름을 저장하는 char 형태의 Node구조체 변수입니다.
// * : Node -> idNum : 학생 데이터의 학번을 저장하는 int 형태의 Node구조체 변수입니다.
// * : Node -> major : 학생 데이터의 전공을 저장하는 string 형태의 Node구조체 변수입니다.
// * : Node -> grade : 학생 데이터의 성적을 저장하는 char 형태의 Node구조체 변수입니다.
// * : Node -> next : 다음 노드의 위치를 가리키는 포인터 변수입니다.
// * : Node -> head : 현재 리스트의 헤드 노드를 가리키는 포인터 변수입니다.
// *
// **********************************************************

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream inStream;

int readData1();
int readData2();
int concatenateList();

char tempName, tempGrade;
string tempMajor;
int tempIdNum;

struct Node{
public:
  char name;
  int idNum;
  string major;
  char grade;
  Node *next;
  friend class List;
};

class List{
public:
  Node *head;
  List(){head = NULL;}
  void insertByNameNode(char inName, int inIdNum, string inMajor, char inGrade);
  void displayNode();
  void displayGradeNode(char selectGrade);
  void displayMajorNode(string selectMajor);
};

List student1;
List student2;
