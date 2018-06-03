#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX 6

class Node{
public:
  int data;
  Node *next;
};

void matrixToList();
void Clear_visited();
void dfs(int);

Node *graph[MAX];
int visited[MAX];
int matrix[MAX][MAX] = {{0,1,1,0,0,0},{1,0,1,1,0,0},{1,1,0,0,0,1},{0,1,0,0,1,1},{0,0,0,1,0,1},{0,0,1,1,1,0}};

void matrixToList() {
  Node *move;
  Node *st;
  Node *temp;

  for (size_t i = 0; i < MAX; i++) {
    st = graph[i];
    std::cout << "V" << i << ":    ";

    for (size_t j = 0; j < MAX; j++) {
      if (matrix[i][j] != 0) {

        temp = new Node;
        temp->data = j;

        if (graph[i] == st) {
          move = temp;
          graph[i] = temp;
          std::cout << temp->data << " -> ";
        }else{
          move->next = temp;
          move = temp;
          std::cout << temp->data << " -> ";
        }
      }
    }
    temp->next = NULL;
    std::cout << "NULL" << '\n';
    std::cout << '\n';
  }
}

void dfs(int v) {
  Node *w;
  visited[v] = true;
  std::cout << "V"<< v << "  -->  ";
  for(w = graph[v]; w; w = w->next){
    if (!visited[w->data]) {
      dfs(w->data);
    }
  }
}

void Clear_visited() {
  for (size_t i = 0; i < MAX; i++) {
    visited[i] = false;
  }
}

int main(int argc, char const *argv[]) {
  int v;

  std::cout << "------ Graph Operations (DFS) ------" << '\n' << '\n';

  Clear_visited();
  matrixToList();

  std::cout << "Starting DFS at V0 " << '\n';
  v = 0;
  dfs(v);
  std::cout << "DFS END" << '\n';
  return 0;
}
