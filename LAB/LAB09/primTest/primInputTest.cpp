#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

#define MAX 7

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
void getMatrix();

int main(int argc, char const *argv[]) {
  int v = 0;
  clearMark();
  getMatrix();
  prim(v);
  return 0;
}

void clearMark(){
  for (size_t i = 0; i < MAX; i++) {
    visited[i] = false;
  }
}

void checkMinNode() {
  minNode.edges = 99;
  for (size_t i = 0; i < MAX; i++) {
    if (lowcost[i].edges < minNode.edges) {
      minNode.edges = lowcost[i].edges;
      minNode.myself = lowcost[i].myself;
      minNode.linked = lowcost[i].linked;
    }
  }
  if (minNode.edges == 99) {
    std::cout << "Graph is END !" << '\n';
    minNode.edges = 100;
    return;
  }
  std::cout << " ( " << char(minNode.myself + 65) << ", " << char(minNode.linked + 65) << " ) "<<  '\n';
  lowcost[minNode.linked].edges = 99;
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

void getMatrix(){

  ifstream inStream;
  Node temp;

  inStream.open("input.txt");
   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   for (size_t i = 0; i < MAX; i++) {
     for (size_t j = 0; j < MAX; j++) {
       temp.myself = i;
       temp.linked = j;
       temp.edges = 99;
       nodeMatrix[i][j] = temp;
     }
   }

   char inff;
   int inEdges;
   char inll;
   for (size_t i = 0; i < 10; i++) {
     inStream >> inff >> inEdges >> inll;

     temp.myself = inff - 65;
     temp.linked = inll - 65;
     temp.edges = inEdges;

     nodeMatrix[temp.myself][temp.linked] = temp;
     nodeMatrix[temp.linked][temp.myself] = temp;
   }
  inStream.close();

}

bool allVisited(){
  for (size_t i = 0; i < MAX; i++) {
    if (visited[i] == false) {
      return false;
    }
  }
  return true;
}

void prim(int v){
  std::cout << " ( V, K ) " << "\n\n";

  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = nodeMatrix[v][i];
  }
  visited[v] = true;
  checkMinNode();
  checkMinNode();
  checkMinNode();
  checkMinNode();
  for (size_t i = 0; i < MAX; i++) {
    std::cout << visited[i] <<  ' ';
  }


  // while (minNode.edges != 100 && !allVisited()) {
  //   checkNextCost();
  // }
}
