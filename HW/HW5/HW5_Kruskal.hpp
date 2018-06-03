#ifndef _KRUSKAL_H_
#define _KRUSKAL_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define MAX 6

using namespace std;

class Node{
public:
  char myself;
  int edges;
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

void inputToArray();
void arrayToList();
void printList();
void sortData();
void printSortedData();

bool allVisited();
void kruskalMST();
void sortKruskalMST();
void printKruskalMST();

#endif
