#include <iostream>
const int MAX_VERTICES = 10;
using namespace std;

class Node{
public:
  int data;
  Node *link;
  friend class Tree;
};

class Tree{
public:
  Node *root;
  void dfs(int);
};

int visited[MAX_VERTICES];
Node *graph[MAX_VERTICES];

void dfs(int v){
  Node *w;
  visited[v] = 1;
  cout << v;

  for(w = graph[v]; w != NULL; w = w->link){
    if (!visited[w ->data]) {
      dfs(w->data);
    }
  }
}

int main(int argc, char const *argv[]) {
  Tree a0;
  Node *temp1 = new Node;
  Node *temp2 = new Node;
  temp1->data = 1;
  temp1->link = temp2;
  temp2->data = 2;
  a0.root = temp1;

  graph[0] = a0;





  return 0;
}
