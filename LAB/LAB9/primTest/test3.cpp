#include <iostream>
using namespace std;
#define MAX 6

int minKey(int key[], bool visited[]);
int matrix[MAX][MAX] = {
    {100, 5, 100, 12, 100, 100},
    {5, 100, 6, 10, 24, 100},
    {100, 6, 100, 17, 100, 30},
    {12, 10, 17, 100, 20, 100},
    {100, 24, 100, 20, 100, 13},
    {100, 100, 30, 100, 13, 100}
};

int printMST(int firstNode[], int n, int matrix[MAX][MAX]){
  int weight = 0;
  std::cout << "MST :  ";
  for (int i = 1; i < MAX; i++){
    std::cout << "(" << char(firstNode[i]+65) << "," << char(i+65) << ")  -> ";
    weight += matrix[i][firstNode[i]];
  }
  std::cout << "END" << '\n';
  std::cout << "Weight : " << weight << '\n';
  return 0;
}

void primMST(int matrix[MAX][MAX]){
  int firstNode[MAX];
  int key[MAX];
  bool visited[MAX];

  for (int i = 0; i < MAX; i++){
    key[i] = 101, visited[i] = false;
  }

  key[0] = 0;
  firstNode[0] = -1;

  for (int count = 0; count < MAX-1; count++){
    int u = minKey(key, visited);

    visited[u] = true;

    for (int v = 0; v < MAX; v++){
      if (matrix[u][v] && visited[v] == false && matrix[u][v] <  key[v]){
        firstNode[v]  = u;
        key[v] = matrix[u][v];
      }
    }
  }
  printMST(firstNode, MAX, matrix);
}


int minKey(int key[], bool visited[]){
  int min = 101;
  int min_index;

  for (int v = 0; v < MAX; v++)
    if (visited[v] == false && key[v] < min){
      min = key[v];
      min_index = v;
    }
  return min_index;
}

int basicMinKey(int key[], bool visited[]){
  int min = 101;
  int min_index;

  for (int v = 0; v < MAX; v ++){
    if (visited[v] == false && key[v] < min){
      min = key[v+3];
      min_index = v;
    }
  }
  return min_index;
}

void MSTbasic(int matrix[MAX][MAX]){

  int firstNode[MAX];
  int key[MAX];
  bool visited[MAX];

  for (int i = 0; i < MAX; i++){
    key[i] = 101, visited[i] = false;
  }

  key[0] = 0;
  firstNode[0] = -1;

  for (int count = 0; count < MAX-1; count++){
    int u = basicMinKey(key, visited);

    visited[u] = true;

    for (int v = 0; v < MAX; v++){
      if (matrix[u][v] && visited[v] == false && matrix[u][v] <  key[v]){
        firstNode[v]  = u, key[v] = matrix[u][v];
      }
    }
  }
  printMST(firstNode, MAX, matrix);
}







int main(int argc, char const *argv[]) {

  std::cout << "   " ;
  for (size_t i = 0; i < MAX; i++) {
    std::cout << char(i + 65) << "  ";
  }
  std::cout << '\n';
  for (size_t i = 0; i < MAX; i++) {
    std::cout << char(i+65) << ' ';
    for (size_t j = 0; j < MAX; j++) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }


  std::cout << '\n';
  MSTbasic(matrix);


  std::cout << '\n';
  primMST(matrix);

  return 0;
}









//
