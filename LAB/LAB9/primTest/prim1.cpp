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

int matrix[MAX][MAX] = {
{100, 5, 100, 12, 100, 100},
{5, 100, 6, 10, 24, 100},
{100, 6, 100, 17, 100, 30},
{12, 10, 17, 100, 20, 100},
{100, 24, 100, 20, 100, 13},
{100, 100, 30, 100, 13, 100}
};

void prim(int v);
void createNodeMatrix();
void checkMinNode();
void checkNextCost();
void clearMark();

void clearMark(){
  for (size_t i = 0; i < MAX; i++) {
    visited[i] = false;
  }
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
  std::cout << " ( " << char(minNode.myself + 65) << ", " << char(minNode.next + 65) << " ) "<<  '\n';
  lowcost[minNode.next].edges = 100;
  visited[minNode.myself] = true;
  visited[minNode.next] = true;
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
  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = nodeMatrix[v][i];
  }
  visited[v] = true;
  checkMinNode();
  while (minNode.edges != 101) {
    checkNextCost();
  }
}

int main(int argc, char const *argv[]) {
  int v = 0;
  clearMark();
  createNodeMatrix();
  prim(v);
  return 0;
}
