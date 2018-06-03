#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
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

int matrix[MAX][MAX];

void prim(int v);
void createNodeMatrix();
void checkMinNode();
void checkVisited();
void checkNextCost();
void clearMark();
void createMatrix();

int main(int argc, char const *argv[]) {
  int v = 0;
  clearMark();
  createMatrix();
  createNodeMatrix();
  prim(v);
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
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
  std::cout << " ( " << char(minNode.myself+65) << ", " << char(minNode.linked+65) << " ) "<<  '\n';
  lowcost[minNode.linked].edges = 100;
  visited[minNode.myself] = true;
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

void createMatrix() {

  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      matrix[i][j] = 100;
    }
  }

  ifstream inStream;

  inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   char myself;
   int inEdges;
   char linked;
   for (size_t i = 0; i < 10; i++) {
     inStream >> myself >> inEdges >> linked;

     matrix[myself - 65][linked - 65] = inEdges;
     matrix[linked - 65][myself - 65] = inEdges;

   }
  inStream.close();

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
