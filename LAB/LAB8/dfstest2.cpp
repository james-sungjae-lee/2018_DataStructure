#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX 8

typedef struct Node *p;

typedef struct Node{
  p link;
  int data;
}Node;

p graph[MAX];
int mark[MAX];

int matrix[MAX][MAX] = {
    {0,1,1,0,0,0,0,0},
    {1,0,0,1,1,0,0,0},
    {1,0,0,0,0,1,1,0},
    {0,1,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,1,1,1,1,0},
};

void init();
void Clear_mark();
void dfs(int);

void init() {
  int x, y;

  p move;
  p st;
  p temp;

  for (size_t i = 0; i < MAX; i++) {
    st = graph[i];
    std::cout << "V" << i << "  --->  ";

    for (size_t j = 0; j < MAX; j++) {
      if (matrix[i][j] != 0) {
        temp = (p)malloc(sizeof(Node));
        temp->data = j;

        if (graph[i] == st) {
          move = temp;
          graph[i] = temp;
          std::cout << temp->data << "    ";
        }else{
          move->link = temp;
          move = temp;
          std::cout << temp->data << "    ";
        }
      }
    }
    temp->link = NULL;
    std::cout << '\n';
  }
}

void dfs(int v) {
  p w;
  mark[v] = true;
  std::cout << v << "   ";

  for(w = graph[v]; w; w = w->link){
    if (!mark[w->data]) {
      dfs(w->data);
    }
  }
}

void Clear_mark() {
  for (size_t i = 0; i < MAX; i++) {
    mark[i] = false;
  }
}

int main(int argc, char const *argv[]) {
  int v;
  Clear_mark();
  init();

  std::cout << "어느 점에서 시작할까요? : ";
  std::cin >> v;
  dfs(v);
  return 0;
}
