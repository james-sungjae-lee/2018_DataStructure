#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 6

using namespace std;

class Node{
public:
  int edges;
  char myself;
  char linked;
  Node *next = NULL;

  Node(char myself, int edges , char linked){
    this->myself = myself;
    this->edges = edges;
    this->linked = linked;
  }
  bool operator > (const Node &str) const{
    return (edges > str.edges);
  }
  bool operator < (const Node &str) const{
    return (edges < str.edges);
  }
};

vector<Node> graph;
Node *adjacencyList[MAX];

void inputToList() {

  ifstream inStream;
  int numCases;
  char myself;
  int edges;
  char linked;

  Node *temp;
  Node *move;

  for (size_t i = 0; i < MAX; i++) {
    adjacencyList[i] = NULL;
  }

  inStream.open("input.txt");
  if (inStream.fail()) {
   std::cerr << "Input file opening failed." << '\n';
   exit(1);
  }

  inStream >> numCases;
  for (size_t i = 0; i < numCases; i++) {
    inStream >> myself >> edges >> linked;
    temp = new Node(myself, edges, linked);
    for (size_t j = 0; j < MAX; j++) {
      if (myself-'A' == j) { // myself 가 들어갈 위치를 찾는다.
        move = adjacencyList[j];
        if (move == NULL) {
          adjacencyList[j] = temp;
        }else{
          while (move->next != NULL) {
            move = move->next;
          }
          move->next = temp;
          move = move->next;
          move->next = NULL;
        }
      }
    }
  }
}

void printAdjacencyList() {
  Node *move;

  std::cout << "***** Print Adjacency List *****" << '\n';

  for (size_t i = 0; i < MAX; i++) {
    if (adjacencyList[i] != NULL) {
      std::cout << adjacencyList[i]->myself << " :  ";
      move = adjacencyList[i];
    }
    while (move->next != NULL) {

    }
    std::cout << '\n';
  }
}

int main(int argc, char const *argv[]) {
  inputToList();
  printAdjacencyList();
  // graph.push_back(temp);
  // sort(graph.begin(), graph.end(),less<Node>());
  return 0;
}












//
