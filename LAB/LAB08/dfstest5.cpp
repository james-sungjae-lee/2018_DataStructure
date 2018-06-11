#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define MAX 4

typedef struct Node *p;

typedef struct Node{
  p link;
  int data;
}Node;

p graph[MAX];
int mark[MAX];
ifstream inStream;
int numTestCases;
int matrix[MAX][MAX];

void init();
void Clear_mark();
void dfs(int);
void make_Matrix();

int main(int argc, char const *argv[]) {
  int v;
  Clear_mark();
  make_Matrix();
  init();

  std::cout << " Starting DFS at : ";
  std::cin >> v;
  dfs(v);

  return 0;
}

void make_Matrix(){

  inStream.open("input.txt");

   if (inStream.fail()) {
     std::cerr << "Input file opening failed." << '\n';
     exit(1);
   }

   inStream >> numTestCases;
   int a;
   int bnum;
   int b;

  for (size_t i = 0; i < numTestCases; i++) {
    for (size_t j = 0; j < numTestCases; j++) {
      matrix[i][j] = 0;
    }
  }

  for (size_t i = 0; i < numTestCases; i++) {
    inStream >> a;
    inStream >> bnum;
    for (size_t j = 0; j < bnum; j++) {
      inStream >> b;
      matrix[a][b] = 1;
      matrix[b][a] = 1;
    }
  }

  for (size_t i = 0; i < numTestCases; i++) {
    for (size_t j = 0; j < numTestCases; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
  inStream.close();
}

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
