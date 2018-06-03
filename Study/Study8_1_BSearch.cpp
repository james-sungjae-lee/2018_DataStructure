#include <iostream>
using namespace std;

int compare(int list[], int x, int m){
  if (list[m] == x) {
    return 0;
  }else{
    if (list[m] < x) {
      return -1;
    }else{
      return 1;
    }
  }
}

int binsearch(int list[], int searchnum, int left, int right){
  int middle;
  if (left <= right) {
    middle = (left + right)/2;
    switch (compare(list, searchnum, middle)) {
      case -1: return binsearch(list, searchnum, middle+1, right);
      case 0: return middle;
      case 1: return binsearch(list, searchnum, left, middle-1);
  }
  }
  return -1;
};

int main(int argc, char const *argv[]) {
  int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int num, found;
  std::cout << "Enter an integer to search : ";
  std::cin >> num;
  found = binsearch(data, num, 0, 9);
  if (found == -1) {
    std::cout << "Not in the list" << '\n';
  }else{
    std::cout << "Found at position : " << found << '\n';
  }
  return 0;
}
