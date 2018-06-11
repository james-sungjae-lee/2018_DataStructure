#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX 7

class Node{
public:
  int edges;
  int myself;
  int linked;
  Node *link;
};

Node *graph[MAX];
int visited[MAX];
Node lowcost[MAX];
Node matrix2[MAX][MAX];
Node minNode;

int matrix[MAX][MAX] = {
    {99,28,99,99,99,10,99},
    {28,99,16,99,99,99,14},
    {99,16,99,12,99,99,99},
    {99,99,12,99,22,99,18},
    {99,99,99,22,99,25,24},
    {10,99,99,99,25,99,99},
    {99,14,99,18,24,99,99},
};


void Clear_mark();
void prim(int v);
void createNodeMatrix();
void checkMinNode();
void checkNextCost();
bool checkVisited(int);

int main(int argc, char const *argv[]) {
  int v = 0;
  Clear_mark();
  createNodeMatrix();
  prim(v);
  return 0;
}

void Clear_mark(){
  for (size_t i = 0; i < MAX; i++) {
    visited[i] = false;
  }
}

void createNodeMatrix() {

  Node temp;

  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      temp.edges = matrix[i][j];
      temp.myself = i;
      temp.linked = j;
      matrix2[i][j] = temp;
    }
  }
}

void checkMinNode(){
  minNode.edges = 99;
  for (size_t i = 0; i < MAX; i++) {
    if (lowcost[i].edges < minNode.edges) {
      minNode.edges = lowcost[i].edges;
      minNode.myself = lowcost[i].myself;
      minNode.linked = lowcost[i].linked;
    }
  }
  if (minNode.edges == 99) {
    std::cout << "Graph is End!" << '\n';
    return;
  }
  std::cout << minNode.edges << " (" << minNode.myself << ", " << minNode.linked << ") "<<  '\n';
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

void checkNextCost(){
  for (size_t i = 0; i < MAX; i++) {
    if (matrix2[minNode.linked][i].edges < lowcost[i].edges && checkVisited(i) ) {
      lowcost[i].edges = matrix2[minNode.linked][i].edges;
      lowcost[i].myself = matrix2[minNode.linked][i].myself;
      lowcost[i].linked = matrix2[minNode.linked][i].linked;
    }
  }

  for (size_t i = 0; i < MAX; i++) {
    std::cout << lowcost[i].edges << ' ';
  }
  std::cout << '\n';
  checkMinNode();
}

void prim(int v){

  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = matrix2[v][i];
  }
  visited[v] = true;
  std::cout << '\n';
  checkMinNode();

  for (size_t i = 0; i < MAX-1; i++) {
    checkNextCost();
  }

  for (size_t i = 0; i < MAX; i++) {
    if (visited[i] == true) {
      std::cout << "1 ";
    }else{
      std::cout << "0 ";
    }
  }

}







//
