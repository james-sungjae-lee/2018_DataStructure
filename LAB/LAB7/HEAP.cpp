#include <iostream>
using namespace std;
#define MAX_ELEMENTS 9

int heap[MAX_ELEMENTS] = {0};
int n = 0;

bool HEAP_FULL(int n){
  return n == MAX_ELEMENTS - 1;
}

bool HEAP_EMPTY(int n){
  return !n;
}

void insert_maxheap(int item, int *n) {
  int i;
  if (HEAP_FULL(*n)) {
    std::cout << "Heap is full" << '\n';
    exit(1);
  }
  i = ++(*n);
  while ((i != 1) && (item > heap[i/2])) {
    heap[i] = heap[i/2];
    i = i/2;
  }
  heap[i] = item;
  n++;
}

int delete_maxheap(int *n){
  int parent, child;
  int item, temp;

  item = heap[1];
  temp = heap[(*n)--];
  parent = 1;
  child = 2;

  while (child <= *n) {
    if ((child < *n) && (heap[child] < heap[child + 1])) {
      child ++;
    }
    if (temp >= heap[child]) {
      break;
    }
    heap[parent] = heap[child];
    parent = child;
    child = child * 2;
  }
  heap[parent] = temp;

  int i = 1;
  while (n[i+1] != 0) {
    i++;
  }
  n[i] = 0;
  n--;
  return item;
}

void print_maxheap(int *n){
  int i = 1;
  while (n[i] != 0) {
    std::cout << n[i] << ' ';
    i++;
  }
  std::cout << '\n';
}

void search_maxheap(int key, int *n){
  int i = 1;
  while (n[i] != key && i < MAX_ELEMENTS) {
    i++;
  }
  if (n[i] == key) {
    std::cout << key << " found in " << i << "th!"<< '\n';
  }else{
    std::cout << key << " is not in the heap" << '\n';
  }
}

int level_maxheap(int *n) {
  int i = 1;
  while (n[i] != 0) {
    i++;
  }
  int x = 1;
  int idx = 0;
  while (i > x) {
    x *= 2;
    idx ++;
  }
  return idx;
}

int main(int argc, char const *argv[]) {
  int k = 8;
  while (k != 5) {
    std::cout << "menu : 1)insert  2)delete  3)print  4)search  5)quit  6)Full test 7)Empty test  8)Level Test" << '\n';
    std::cin >> k;
    switch (k) {
      case 1:{
        std::cout << "insert maxheap / 0 to stop" << '\n';
        int x = 1;
        while (x != 0) {
          std::cin >> x;
          if (x == 0) {
            break;
          }
          insert_maxheap(x, heap);
          std::cout << x << " inserted!" << '\n';
        }
        print_maxheap(heap);
        break;
      }
      case 2:{
        std::cout << "root of maxheap deleted" << '\n';
        delete_maxheap(heap);
        break;
      }
      case 3:{
        std::cout << "print maxheap" << '\n';
        print_maxheap(heap);
        break;
      }
      case 4:{
        std::cout << "search maxheap / 0 to stop" << '\n';
        int x = 1;
        while (x != 0) {
          std::cin >> x;
          if (x == 0) {
            break;
          }
          search_maxheap(x, heap);
        }
        break;
      }
      case 5:{
        std::cout << "quit!" << '\n';
        exit(1);
      }
      case 6:{
        if (HEAP_FULL(*heap)) {
          std::cout << "heap is FULL" << '\n';
        }else{
          std::cout << "heap is not FULL" << '\n';
        }
        break;
      }
      case 7:{
        if (HEAP_EMPTY(*heap)) {
          std::cout << "heap is empty" << '\n';
        }else{
          std::cout << "heap is not empty" << '\n';
        }
        break;
      }
      case 8:{
        std::cout << level_maxheap(heap) << " level" << '\n';
      }
    }
  }

  return 0;
}
