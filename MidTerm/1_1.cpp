#include <iostream>
using namespace std;

int binarySearch(int data[], int num, int left, int right);

int main(int argc, char const *argv[]) {
  int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int num, found;

  std::cout << "number? : " << " ";
  std::cin >> num;

  found = binarySearch(data, num, 0, 9);

  if (found == -1) {
    std::cout << "Not in the list" << '\n';
  }else{
    std::cout << "Found at position " << found << '\n';
  }

  return 0;
}

int binarySearch(int data[], int num, int left, int right){
  int middle;
  while (left <= right) {
    middle = (left + right) / 2;
    if (num == data[middle]) {
      return middle;
    }else if (num > data[middle]) {
      left = middle + 1;
    }else{
      right = middle - 1;
    }
  }
  return -1;
}
