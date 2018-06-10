#include <iostream>
using namespace std;

#define MAX 6

bool found[MAX];
int mydistance[MAX];
int cost[MAX][MAX];

void InitCostMatrix(){
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      if (i == j) {
        cost[i][j] = 0;
      }else{
        cost[i][j] = 99;
      }
    }
  }
  cost[0][1] = 50;
  cost[0][2] = 10;
  cost[0][4] = 45;
  cost[1][2] = 15;
  cost[1][4] = 10;
  cost[2][0] = 20;
  cost[2][3] = 15;
  cost[3][1] = 20;
  cost[3][4] = 35;
  cost[4][3] = 30;
  cost[5][3] = 3;
}

int choose(){
  int min = 99;
  int index;
  for (size_t i = 0; i < MAX; i++) {
    if (mydistance[i] < min && !found[i]) {
      min = mydistance[i];
      index = i;
    }
  }
  return index;
};

void PrintPath(){
  for (size_t i = 0; i < MAX; i++) {
    std::cout << mydistance[i] << " ";
  }
  std::cout << '\n';
}

void ShortestPath(int v){
  int u;
  for (size_t i = 0; i < MAX; i++) {
    found[i] = false;
    mydistance[i] = cost[v][i];
  }

  found[v] = true;
  mydistance[v] = 0;

  for (size_t i = 0; i < MAX - 1; i++) {
    u = choose();
    found[u] = true;

    for (size_t j = 0; j < MAX; j++) {
      if (!found[j]) {
        if (mydistance[u] + cost[u][j] < mydistance[j]) {
          mydistance[j] = mydistance[u] + cost[u][j];
        }
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  InitCostMatrix();
  ShortestPath(0);
  PrintPath();
  return 0;
}
