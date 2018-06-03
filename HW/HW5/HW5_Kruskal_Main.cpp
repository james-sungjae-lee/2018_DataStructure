#include "HW5_Kruskal.hpp"

int main(int argc, char const *argv[]) {

  inputToArray();
  arrayToList();
  printList();

  sortData();
  printSortedData();

  kruskalMST();
  sortKruskalMST();
  printKruskalMST();

  return 0;
}
