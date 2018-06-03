// *******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW5_Kruskal_Main.cpp
// *
// * Algorithm Description
// *
// * Variables
// *
// ********************************************************************************************************************

#include "HW5_Kruskal.hpp"

// ********************************************************************************************************************
// * function: int main
// * description
// *
// ********************************************************************************************************************

int main(int argc, char const *argv[]) {

  inputToArray();
  arrayToList();
  printList();

  sortData();
  printSortedData();

  kruskalMST();
  sortKruskalMST();
  printKruskalMST();

  return 0;
}

// ******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW5_Kruskal.hpp
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

#ifndef _KRUSKAL_H_
#define _KRUSKAL_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 6

using namespace std;

class Node{
public:
  char myself;
  int edges;
  char linked;
  Node *next = NULL;

  Node(char myself, int edges , char linked){
    this->myself = myself;
    this->edges = edges;
    this->linked = linked;
  }

  bool operator > (const Node &str) const{
    return (edges > str.edges);
  }
  bool operator < (const Node &str) const{
    return (edges < str.edges);
  }
};

void inputToArray();
void arrayToList();
void printList();
void sortData();
void printSortedData();

bool allVisited();
void kruskalMST();
void sortKruskalMST();
void printKruskalMST();

#endif

// ******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW5_Kruskal.cpp
// * description :
// ********************************************************************************************************************

#include "HW5_Kruskal.hpp"

// ********************************************************************************************************************
// * function : void Graph::matrixToList()
// * description : 최초로 입력된 매트릭스 형태의 그래프 데이터를 링크드리스트 형태로 변환하는 함수입니다.
// *
// * Variable
// * : Node *move : 링크드리스트를 이동하며 현재 노드와 다음 노드를 이어주는 노드 포인터입니다.
// * : Node *headNode : 노드 포인터들의 집합인 graph에서, 실제로 저장되는 가장 첫 번째 헤드 노드를 저장합니다.
// * : Node *temp : 매트릭스를 읽어온 결과 노드를 생성해야 한다면, 이 temp 노드를 새로 생성하여 데이터를 저장합니다.
// *                temp 노드는 graph 리스트 배열에 헤드 노드로 저장되거나, 헤드 노드의 다음 노드들중 하나로 연결됩니다.
// * : Node *grpah[MAX] : 각 링크드 리스트의 헤드 노드를 차례로 저장하는 graph 배열이 이 함수에서 사용됩니다.
// *
// * Algorithm description
// * : 1. 먼저 헤드 노드를 가리키는 포인터 headNode를 헤드 노드를 저장하는 graph 배열의 인자와 같게 설정합니다.
// * :    이를 통해 첫 번째 들어오는 헤드 노드는 graph[i] 에 저장되고, 그렇지 않은 것은 헤드 노드의 next 로 저장되는
// * :    조건문을 작동시킬 수 있게 됩니다.
// * : 2. 다음으로 matrix 의 i, j 번째 인자가 1인지 아닌지 검사합니다. 만약 1 이라면 조건문을 실행하고, 아니라면 무시합니다.
// * : 3. matrix 의 데이터가 1일 때, i 노드와 j 노드가 연결되었다는 의미이므로 temp 노드를 생성하여, data 를 j로 설정합니다.
// * : 4. 이렇게 생성된 temp 노드를 위에서 말한 것 처럼 graph[i] 혹은 next 노드에 저장합니다. 이 때 move 노드 포인터를 이용하여
// * :    현재의 위치를 저장하거나 다음 노드로 이동하여 저장합니다.
// * : 5. 마지막으로 j 회의 반복문이 종료된 후, 하나의 리스트 생성이 완료되었다면 마지막 노드를 NULL 로 설정합니다. (temp -> next = NULL)
// ********************************************************************************************************************

Node *adjList[MAX];
vector<Node> graph;
vector<Node> kruskal;
int visited[MAX] = {false};

void inputToArray(){
  ifstream inStream;
  int numCases;
  char myself;
  int edges;
  char linked;

  inStream.open("input.txt");
  if (inStream.fail()) {
   std::cerr << "Input file opening failed." << '\n';
   exit(1);
  }

  inStream >> numCases;
  for (size_t i = 0; i < numCases; i++) {
    inStream >> myself >> edges >> linked;
    Node temp = Node(myself, edges, linked);
    graph.push_back(temp);
  }
}

void arrayToList(){
  for (size_t i = 0; i < MAX; i++) {
    Node *temp = new Node('A' + i, 0, 'A' + i);
    temp->next = NULL;
    adjList[i] = temp;
  }

  Node *move;
  for (size_t i = 0; i < graph.size(); i++) {

    move = adjList[graph[i].myself - 'A'];
    while (move->next != NULL) {
      move = move->next;
    }
    move->next = new Node(graph[i].myself, graph[i].edges, graph[i].linked);
    move->next->next = NULL;
  }
}

void printList(){
  std::cout << "***** Print Adjacency List *****" << "\n\n";
  Node *move;
  for (size_t i = 0; i < MAX; i++) {
    move = adjList[i];
    std::cout << move->myself << " :  " ;
    while (move->next != NULL) {
      move = move->next;
      std::cout << move->linked << " (Cost : " << move->edges << ")" << " -> ";
    }
    std::cout << "NULL" << "\n";
  }
  std::cout << '\n';
}

void sortData() {
  sort(graph.begin(), graph.end(),less<Node>());
}

void printSortedData() {
  std::cout << "***** Print Sorted Data *****" << "\n\n";
  for (size_t i = 0; i < graph.size(); i++) {
    std::cout << graph[i].myself << "  " << graph[i].edges << "  " << graph[i].linked << '\n';
  }
  std::cout << '\n';
}

bool allVisited(){
  for (size_t i = 0; i < MAX; i++) {
    if (visited[i] == false) {
      return false;
    }
  }
  return true;
}


void kruskalMST() {
  char first, last;
  kruskal.push_back(graph[0]);

  first = kruskal[0].myself;
  last = kruskal[0].linked;
  Node dumpNode = Node(0, 100, 0);
  Node firstNode = dumpNode;
  Node lastNode = dumpNode;

  while (!allVisited()) {
    firstNode = dumpNode;
    lastNode = dumpNode;
    visited[first - 'A'] = true;
    visited[last - 'A'] = true;

    for (size_t i = 0; i < graph.size(); i++) {
      if ((graph[i].myself == first && !visited[graph[i].linked - 'A']) || (graph[i].linked == first && !visited[graph[i].myself - 'A'])) {
        firstNode = graph[i];
        break;
      }
    }
    for (size_t i = 0; i < graph.size(); i++) {
      if ((graph[i].myself == last && !visited[graph[i].linked - 'A']) || (graph[i].linked == last && !visited[graph[i].myself - 'A'])) {
        lastNode = graph[i];
        break;
      }
    }
    if (firstNode.edges == dumpNode.edges && lastNode.edges == dumpNode.edges) {
      break;
    }
    if (firstNode.edges < lastNode.edges) {
      kruskal.push_back(firstNode);
      if (firstNode.myself == first) {
        first = firstNode.linked;
      }else{
        first = firstNode.myself;
      }
    }else{
      kruskal.push_back(lastNode);
      if (lastNode.myself == last) {
        last = lastNode.linked;
      }else{
        last = lastNode.myself;
      }
    }
  }
}

void sortKruskalMST() {
  sort(kruskal.begin(), kruskal.end(),less<Node>());
}

void printKruskalMST(){
  std::cout << "***** Print Kruskal MST *****" << "\n\n";
  for (size_t i = 0; i < kruskal.size(); i++) {
    std::cout << kruskal[i].myself << "  "<< kruskal[i].edges << "  " << kruskal[i].linked << '\n';
  }
}

// *******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : Makefile
// *
// * Algorithm Description
// *
// * Variables
// *
// ********************************************************************************************************************

CC = g++
SOURCE = HW5_Kruskal_Main.o HW5_Kruskal.o
TARGET = HW5

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) -o $@ $^

clean:
	rm -rf *.o $(TARGET)

// *******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : input.txt
// *
// * Algorithm Description
// *
// * Variables
// *
// ********************************************************************************************************************

10
A 6 B
B 7 C
A 1 C
A 5 D
C 5 D
B 3 E
C 8 E
C 4 F
D 2 F
E 9 F
