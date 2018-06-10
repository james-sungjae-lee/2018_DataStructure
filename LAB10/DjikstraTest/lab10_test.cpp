#include <iostream>
using namespace std;

#define MAX 8

bool found[MAX];
int mydistance[MAX];
int cost[MAX][MAX];

// 매트릭스 생성 함수
// 0 과 9999 로 초기화 해준 다음, 특정 코스트를 하나씩 넣어준다.

void InitCostMatrix(){
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      if (i == j) {
        cost[i][j] = 0;
      }else{
        cost[i][j] = 9999;
      }
    }
  }
  cost[1][0] = 300;
  cost[2][0] = 1000;
  cost[2][1] = 800;
  cost[3][2] = 1200;
  cost[4][3] = 1500;
  cost[4][5] = 250;
  cost[5][3] = 1000;
  cost[5][6] = 900;
  cost[5][7] = 1400;
  cost[6][7] = 1000;
  cost[7][0] = 1700;
}

int choose(){
  int min = 10000;
  int index = -1;
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

// 매트릭스의 한 점에서 각 점까지의 최소비용 거리를 구하는 함수

void ShortestPath(int v){
  int u;

  // 가장 먼저 방문 여부를 확인할 found 배열을 false 로 초기화한다.
  // 그 다음, 가장 첫 줄을 mydistance 배열의 초기값으로 저장한다.

  for (size_t i = 0; i < MAX; i++) {
    found[i] = false;
    mydistance[i] = cost[v][i];
  }

  // 시작점 v 를 먼저 방문 표시를 해준 다음, 해당 점에서 자기 자신으로 가는 비용을 0으로 초기화한다.

  found[v] = true;
  mydistance[v] = 0;

  // 본격적인 알고리즘의 진행이다.
  // 앞에서 선언했던 u 변수에 현재 mydistance 중 가장 적은 비용의 점을 저장한다.
  // 그리고, 해당 점에 대해 방문 표시를 하도록 한다.

  for (size_t i = 0; i < MAX - 1; i++) {
    u = choose();
    found[u] = true;

    //

    for (size_t j = 0; j < MAX; j++) {
      if (!found[j]) {
        if (mydistance[u] + cost[u][j] < mydistance[j]) {
          mydistance[j] = mydistance[u] + cost[u][j];
        }
      }
    }
  }
}

void printMatrix(){
  for (size_t i = 0; i < MAX; i++) {
    for (size_t j = 0; j < MAX; j++) {
      std::cout << cost[i][j] << ' ';
    }
    std::cout  << '\n';
  }
}

int main(int argc, char const *argv[]) {
  InitCostMatrix();
  ShortestPath(0);
  PrintPath();
  // printMatrix();
  return 0;
}
