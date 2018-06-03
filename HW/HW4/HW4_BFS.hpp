// ******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW4_BFS.hpp
// *
// * Description
// * 헤더파일 및 정의사항
// * : iostream : 콘솔창에 결과를 출력하기 위한 헤더파일입니다.
// * : using namespace std : 기본 namespace 를 std 로 설정합니다.
// * : define MAX 8 : 현재 다루고자 하는 그래프가 8개의 점으로 이루어져 있으므로, MAX값을 8로 저장합니다.
// *
// * Node 객체의 정의
// * : Node *next : 매트릭스를 링크드리스트 형태로 구현하기 위해, 각 노드마다 다음 노드를 표시하는 포인터로 next를 저장합니다.
// * : int data : int 형 변수를 노드에 데이터로 저장하는 data 변수를 만듭니다.
// * : friend class Graph : Graph 클래스에서 Node 클래스의 구성요소를 사용할 수 있도록 friend 설정합니다.
// *
// * Graph 객체의 정의
// * :
// * : < public 구성요소 >
// * : void matrixToList() : 현재 입력된 매트릭스 형태의 그래프 데이터를, 링크드리스트 형태의 데이터로 변환합니다.
// * : void BFS(int v) : v를 인자로 받아 넓이 우선 탐색의 결과를 출력하는 함수입니다. v 는 넓이 우선 탐색의 시작점입니다.
// * : void printMatrix() : 현재 구성되어 있는 매트릭스 형태의 그래프 데이터를 매트릭스 형태 그대로 출력하는 함수입니다.
// * :
// * : < private 구성요소 >
// * : Node *graph[MAX] : 노드 포인터를 저장하는 배열입니다. 각 노드 포인터는 그래프의 점을 의미하며, 하나의 링크드리스트를 구성합니다.
// * :                    배열의 크기는 MAX로 전체 그래프의 점의 개수와 동일합니다.
// * : int visited[MAX] : 그래프 탐색에서 이미 지나간 점인지 여부를 저장해두는 배열입니다. graph 의 인덱스와 동일한 위치에 true / false 가 저장됩니다.
// * : int queue[MAX] : 넓이 우선 탐색을 진행하기 위해 사용되는 queue 배열입니다. 배열의 크기는 그래프의 점 개수와 동일하게 구성됩니다.
// * : int matrix[MAX][MAX] { ~ } : 그래프 데이터의 최초 입력은 2차원 배열 형태의 매트릭스로 이루어집니다.
// *
// ********************************************************************************************************************

#include <iostream>
using namespace std;
#define MAX 8

class Node{
  Node *next;
  int data;
  friend class Graph;
};

class Graph{
public:
  void matrixToList();
  void BFS(int v);
  void printMatrix();
private:
  void addQueue(int *, int);
  int deleteQueue(int *);

  Node *graph[MAX];
  int visited[MAX];
  int queue[MAX];
  int matrix[MAX][MAX] = {
      {0,1,1,0,0,0,0,0},
      {1,0,0,1,1,0,0,0},
      {1,0,0,0,0,1,1,0},
      {0,1,0,0,0,0,0,1},
      {0,1,0,0,0,0,0,1},
      {0,0,1,0,0,0,0,1},
      {0,0,1,0,0,0,0,1},
      {0,0,0,1,1,1,1,0}};
};
