#include "HW5_Kruskal.hpp"

Node *adjList[MAX];
vector<Node> graph;
vector<Node> kruskal;
int visited[MAX] = {false};

void inputToArray(){
  ifstream inStream;
  int numCases;
  char myself;
  int edges;
  char linked;

  inStream.open("input.txt");
  if (inStream.fail()) {
   std::cerr << "Input file opening failed." << '\n';
   exit(1);
  }

  inStream >> numCases;
  for (size_t i = 0; i < numCases; i++) {
    inStream >> myself >> edges >> linked;
    Node temp = Node(myself, edges, linked);
    graph.push_back(temp);
  }
}

void arrayToList(){
  for (size_t i = 0; i < MAX; i++) {
    Node *temp = new Node('A' + i, 0, 'A' + i);
    temp->next = NULL;
    adjList[i] = temp;
  }

  Node *move;
  for (size_t i = 0; i < graph.size(); i++) {

    move = adjList[graph[i].myself - 'A'];
    while (move->next != NULL) {
      move = move->next;
    }
    move->next = new Node(graph[i].myself, graph[i].edges, graph[i].linked);
    move->next->next = NULL;
  }
}

void printList(){
  std::cout << "***** Print Adjacency List *****" << "\n\n";
  Node *move;
  for (size_t i = 0; i < MAX; i++) {
    move = adjList[i];
    std::cout << move->myself << " :  " ;
    while (move->next != NULL) {
      move = move->next;
      std::cout << move->linked << " (Cost : " << move->edges << ")" << " -> ";
    }
    std::cout << "NULL" << "\n";
  }
  std::cout << '\n';
}

void sortData() {
  sort(graph.begin(), graph.end(),less<Node>());
}

void printSortedData() {
  std::cout << "***** Print Sorted Data *****" << "\n\n";
  for (size_t i = 0; i < graph.size(); i++) {
    std::cout << graph[i].myself << "  " << graph[i].edges << "  " << graph[i].linked << '\n';
  }
  std::cout << '\n';
}

bool allVisited(){
  for (size_t i = 0; i < MAX; i++) {
    if (visited[i] == false) {
      return false;
    }
  }
  return true;
}


void kruskalMST() {
  char first, last;
  kruskal.push_back(graph[0]);

  first = kruskal[0].myself;
  last = kruskal[0].linked;
  Node dumpNode = Node(0, 100, 0);
  Node firstNode = dumpNode;
  Node lastNode = dumpNode;

  while (!allVisited()) {
    firstNode = dumpNode;
    lastNode = dumpNode;
    visited[first - 'A'] = true;
    visited[last - 'A'] = true;

    for (size_t i = 0; i < graph.size(); i++) {
      if ((graph[i].myself == first && !visited[graph[i].linked - 'A']) || (graph[i].linked == first && !visited[graph[i].myself - 'A'])) {
        firstNode = graph[i];
        break;
      }
    }
    for (size_t i = 0; i < graph.size(); i++) {
      if ((graph[i].myself == last && !visited[graph[i].linked - 'A']) || (graph[i].linked == last && !visited[graph[i].myself - 'A'])) {
        lastNode = graph[i];
        break;
      }
    }
    if (firstNode.edges == dumpNode.edges && lastNode.edges == dumpNode.edges) {
      break;
    }
    if (firstNode.edges < lastNode.edges) {
      kruskal.push_back(firstNode);
      if (firstNode.myself == first) {
        first = firstNode.linked;
      }else{
        first = firstNode.myself;
      }
    }else{
      kruskal.push_back(lastNode);
      if (lastNode.myself == last) {
        last = lastNode.linked;
      }else{
        last = lastNode.myself;
      }
    }
  }
}

void sortKruskalMST() {
  sort(kruskal.begin(), kruskal.end(),less<Node>());
}

void printKruskalMST(){
  std::cout << "***** Print Kruskal MST *****" << "\n\n";
  for (size_t i = 0; i < kruskal.size(); i++) {
    std::cout << kruskal[i].myself << "  "<< kruskal[i].edges << "  " << kruskal[i].linked << '\n';
  }
}
