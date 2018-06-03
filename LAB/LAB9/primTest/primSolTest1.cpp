#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

#define MAX 6

class Node{
public:
  char ff;
  char ll;
  int edges;
};

int visited[MAX];
Node lowcost[MAX];
Node nodeMatrix[MAX][MAX];
Node minNode;

void prim(char v);
void createNodeMatrix();
void checkMinNode();
void checkVisited();
void checkNextCost();
void clearMarkAndMatrix();
bool allVisited();

int main(int argc, char const *argv[]) {
  char v = 'A';
  clearMarkAndMatrix();
  createNodeMatrix();
  prim(v);

  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      std::cout << nodeMatrix[i][j].edges  << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

void clearMarkAndMatrix() {
  Node temp;

  for (size_t i = 0; i < MAX; i++) {
    visited[i] = false;
  }
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      temp.ff = i;
      temp.ll = j;
      temp.edges = 99;
      nodeMatrix[i][j] = temp;
    }
  }
}

void createNodeMatrix(){
  ifstream inStream;
  Node temp;

  inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   char inff;
   int inEdges;
   char inll;
   for (size_t i = 0; i < 10; i++) {
     inStream >> inff >> inEdges >> inll;

     temp.ff = inff;
     temp.ll = inll;
     temp.edges = inEdges;

     nodeMatrix[inff-65][inll-65] = temp;
   }
  inStream.close();
}

void checkMinNode(){
  minNode.edges = 99;
  for (size_t i = 0; i < MAX; i++) {
    if (lowcost[i].edges < minNode.edges) {
      minNode.edges = lowcost[i].edges;
      minNode.ff = lowcost[i].ff;
      minNode.ll = lowcost[i].ll;
    }
  }
  if (minNode.edges == 99) {
    std::cout << "Graph is END!" << '\n';
    minNode.edges = 100;
    return;
  }
  std::cout << " ( " << minNode.ff << ", " << minNode.ll << " ) "<<  '\n';
  lowcost[minNode.ll - 65].edges = 99;
  visited[minNode.ll - 65] = true;

  for (size_t i = 0; i < MAX; i++) {
    std::cout << visited[i] << ' ';
  }
  std::cout << '\n';
}

bool checkVisited(char v){
  if (visited[v - 65] == true) {
    return false;
  }else{
    return true;
  }
}

void checkNextCost(){
  for (size_t i = 0; i < MAX; i++) {
    if (nodeMatrix[minNode.ll - 65][i].edges < lowcost[i].edges && checkVisited(i)) {
      lowcost[i].edges = nodeMatrix[minNode.ll - 65][i].edges;
      lowcost[i].ff = nodeMatrix[minNode.ll - 65][i].ff;
      lowcost[i].ll = nodeMatrix[minNode.ll - 65][i].ll;
    }
  }
  for (size_t i = 0; i < MAX; i++) {
    std::cout << lowcost[i].edges << ' ';
  }
  std::cout << '\n';

  checkMinNode();
}

bool allVisited(){
  for (size_t i = 0; i < MAX; i++) {
    if (visited[i] == false) {
      return false;
    }
  }
  return true;
}

void prim(char v){
  std::cout << " ( V, K ) " << "\n\n";
  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = nodeMatrix[v - 65][i];
  }
  visited[v - 65] = true;
  for (size_t i = 0; i < MAX; i++) {
    std::cout << lowcost[i].edges << ' ';
  }
  std::cout << '\n';
  checkMinNode();

  while (minNode.edges != 100 && !allVisited()) {
    checkNextCost();
  }
}



















//
