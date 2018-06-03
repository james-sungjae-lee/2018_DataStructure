#include <iostream>
#define MAX 6

using namespace std;

class Node{
public:
  int myself;
  int next;
  int edges;
};

Node nodeMatrix[MAX][MAX];
int visited[MAX];
Node lowcost[MAX];
Node minNode;
int weight = 0;

int matrix[MAX][MAX] = {
{100, 5, 100, 12, 100, 100},
{5, 100, 6, 10, 24, 100},
{100, 6, 100, 17, 100, 30},
{12, 10, 17, 100, 20, 100},
{100, 24, 100, 20, 100, 13},
{100, 100, 30, 100, 13, 100}
};

void greedy(int v);
void createNodeMatrix();
void clearMark();
void checkMinNode();
void updateLowcost();

void clearMark(){
  for (size_t i = 0; i < MAX; i++) {
    visited[i] = false;
  }
  weight = 0;
}

void createNodeMatrix(){
  Node temp;
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      temp.edges = matrix[i][j];
      temp.myself = i;
      temp.next = j;
      nodeMatrix[i][j] = temp;
    }
  }
}

void checkMinNode(){
  minNode.edges = 100;
  for (size_t i = 0; i < MAX; i++) {
    if (lowcost[i].edges < minNode.edges) {
      minNode.edges = lowcost[i].edges;
      minNode.myself = lowcost[i].myself;
      minNode.next = lowcost[i].next;
    }
  }
  if (minNode.edges == 100) {
    std::cout << "Graph is END !" << '\n';
    minNode.edges = 101;
    return;
  }
  std::cout << " ( " << char(minNode.myself + 65) << ", " << char(minNode.next + 65) << " ) "<<  " -> ";
  lowcost[minNode.myself].edges = 100;
  lowcost[minNode.next].edges = 100;
  visited[minNode.myself] = true;
  visited[minNode.next] = true;
  weight += minNode.edges;
}

void updateLowcost(){
  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = nodeMatrix[minNode.next][i];
  }
  for (size_t i = 0; i < MAX; i++) {
    if (visited[i] == true) {
      lowcost[i].edges = 100;
    }
  }
  checkMinNode();
}

void greedy(int v){
  std::cout << "***** Greedy Algorithm *****" << '\n';
  std::cout << "MST : ";
  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = nodeMatrix[v][i];
  }
  checkMinNode();
  while (minNode.edges != 101) {
    updateLowcost();
  }
  std::cout << "weight : " << weight << '\n';
}

void checkNextCost(){
  for (size_t i = 0; i < MAX; i++) {
    if (nodeMatrix[minNode.next][i].edges < lowcost[i].edges && !visited[i]) {
      lowcost[i].edges = nodeMatrix[minNode.next][i].edges;
      lowcost[i].myself = nodeMatrix[minNode.next][i].myself;
      lowcost[i].next = nodeMatrix[minNode.next][i].next;
    }
  }
  checkMinNode();
}

void prim(int v){
  std::cout << "***** Prim Algorithm *****" << '\n';
  std::cout << "MST : ";
  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = nodeMatrix[v][i];
  }
  visited[v] = true;
  checkMinNode();
  while (minNode.edges != 101) {
    checkNextCost();
  }
  std::cout << "weight : " << weight << '\n';
}

void printMatrix(){
  char x = 'A';
  std::cout << "   ";
  for (size_t i = 0; i < MAX; i++) {
    std::cout << x++ << '\t';
  }
  std::cout << '\n';
  x = 'A';
  for (size_t i = 0; i < MAX; i++) {
    std::cout << x++ << " ";
    for (size_t j = 0; j < MAX; j++) {
      std::cout << matrix[i][j] << '\t';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main(int argc, char const *argv[]) {

  printMatrix();
  int v = 0;
  clearMark();
  createNodeMatrix();
  greedy(v);

  std::cout << '\n';
  clearMark();
  prim(v);

  return 0;
}
