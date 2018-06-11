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

int matrix[MAX][MAX] = {
    {0,28,0,0,0,10,0},
    {28,0,16,0,0,0,14},
    {0,16,0,12,0,0,0},
    {0,0,12,0,22,0,18},
    {0,0,0,22,0,25,24},
    {10,0,0,0,25,0,0},
    {0,14,0,18,24,0,0},
};

Node lowcost[MAX];

void init();
void Clear_mark();
void dfs(int v);
void prim(int v);

int main(int argc, char const *argv[]) {
  int v = 0;
  Clear_mark();
  init();
  dfs(v);
  prim(v);
  return 0;
}

void init(){
  Node *move;
  Node *st;
  Node *temp;

  for (size_t i = 0; i < MAX; i++) {
    st = graph[i];
    std::cout << "V" << i << " ";

    for (size_t j = 0; j < MAX; j++) {
      if (matrix[i][j] != 0) {
        temp = new Node;
        temp->myself = i;
        temp->linked = j;
        temp->edges = matrix[i][j];

        if (graph[i] == st) {
          move = temp;
          graph[i] = temp;
          std::cout << temp->edges << "(" << temp->myself << ", "<< temp->linked<< ")"<< "    ";
        }else{
          move->link = temp;
          move = temp;
          std::cout << temp->edges << "(" << temp->myself << ", "<< temp->linked<< ")"<< "    ";
        }
      }
    }
    temp->link = NULL;
    std::cout << '\n';
  }
}

void dfs(int v){
  Node *p;
  visited[v] = true;

  for(p = graph[v]; p; p = p->link){
    if (!visited[p->linked]) {
      dfs(p->linked);
    }
  }
}

void Clear_mark(){
  for (size_t i = 0; i < MAX; i++) {
    visited[i] = false;
  }
}

void prim(int v){
  for (size_t i = 0; i < MAX; i++) {
    lowcost[i] = graph[v][i];
  }
}







//
