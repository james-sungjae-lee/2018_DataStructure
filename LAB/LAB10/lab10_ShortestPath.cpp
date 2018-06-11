#include <iostream>
using namespace std;

#define MAX 7

bool found[MAX];
int mydistance[MAX];
int cost[MAX][MAX];

void InitCostMatrix(){
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      cost[i][j] = 100;
    }
  }
  cost[0][1] = 2;
  cost[0][2] = 4;
  cost[0][3] = 5;
  cost[1][3] = 2;
  cost[1][4] = 7;
  cost[2][3] = 1;
  cost[2][5] = 4;
  cost[3][1] = 2;
  cost[3][2] = 1;
  cost[3][4] = 4;
  cost[3][5] = 3;
  cost[4][1] = 7;
  cost[4][3] = 4;
  cost[4][5] = 1;
  cost[4][6] = 5;
  cost[5][2] = 4;
  cost[5][3] = 3;
  cost[5][4] = 1;
  cost[5][6] = 7;
  cost[6][4] = 7;
  cost[6][5] = 5;
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
  std::cout << "Dist : ";
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

  PrintPath();

  for (size_t i = 0; i < MAX - 1; i++) {
    u = choose();
    found[u] = true;
    std::cout << "(Selected Node : " << u << " )"<< "\n\n";

    for (size_t j = 0; j < MAX; j++) {
      if (!found[j]) {
        if (mydistance[u] + cost[u][j] < mydistance[j]) {
          mydistance[j] = mydistance[u] + cost[u][j];
        }
      }
    }
    if (i < MAX - 2) {
      PrintPath();
    }
  }
}

void printMatrix() {
  for (size_t i = 0; i < MAX; i++) {
    std::cout << "V" << i << '\t';
  }
  std::cout << '\n';
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      std::cout << cost[i][j] << '\t';
    }
    std::cout << '\n';
  }
  std::cout << "\n\n";
}

int main(int argc, char const *argv[]) {
  InitCostMatrix();
  printMatrix();
  ShortestPath(0);
  return 0;
}
