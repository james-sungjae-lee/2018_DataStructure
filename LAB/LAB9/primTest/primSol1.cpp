#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX 6

class Node{
public:
  int edges;
  int myself;
  int linked;
};

int visited[MAX];
Node lowcost[MAX];
Node nodeMatrix[MAX][MAX];
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
void checkVisited();
void checkNextCost();
void clearMark();

int main(int argc, char const *argv[]) {
  int v = 0;
  clearMark();
  createNodeMatrix();
  prim(v);
  return 0;
}

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
      temp.linked = j;
      nodeMatrix[i][j] = temp;
    }
  }
}

void checkMinNode() {
  minNode.edges = 100;
  for (size_t i = 0; i < MAX; i++) {
    if (lowcost[i].edges < minNode.edges) {
      minNode.edges = lowcost[i].edges;
      minNode.myself = lowcost[i].myself;
      minNode.linked = lowcost[i].linked;
    }
  }
  if (minNode.edges == 100) {
    std::cout << "Graph is END !" << '\n';
    minNode.edges = 101;
    return;
  }
  // std::cout << " ( " << minNode.myself << ", " << minNode.linked << " ) "<<  '\n';
  // char to num / num to char
  std::cout << " ( " << char(minNode.myself + 65) << ", " << char(minNode.linked + 65) << " ) "<<  '\n';
  lowcost[minNode.linked].edges = 99;
  visited[minNode.myself] = true;
  visited[minNode.linked] = true;
}

bool checkVisited(int v){
  if (visited[v] == true) {
    return false;
  }else{
    return true;
  }
}

void checkNextCost() {
  for (size_t i = 0; i < MAX; i++) {
    if (nodeMatrix[minNode.linked][i].edges < lowcost[i].edges && checkVisited(i)) {
      lowcost[i].edges = nodeMatrix[minNode.linked][i].edges;
      lowcost[i].myself = nodeMatrix[minNode.linked][i].myself;
      lowcost[i].linked = nodeMatrix[minNode.linked][i].linked;
    }
  }
  checkMinNode();
}

void prim(int v){
  std::cout << " ( V, K ) " << "\n\n";

  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = nodeMatrix[v][i];
  }
  visited[v] = true;
  checkMinNode();

  while (minNode.edges != 101) {
    checkNextCost();
  }
}
