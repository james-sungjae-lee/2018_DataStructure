#include <iostream>

using namespace std;

void hanoi(char from, char to, char aux, int n){

  if (n == 1) {
    std::cout << "move disk 1 from peg " << from << " to peg " << to << '\n';
  }else{
    hanoi(from, aux, to, n-1);
    std::cout << "move disk " << n << " from peg " << from << " to peg " << to << '\n';
    hanoi(aux, to, from, n-1);
  }
}

int main(int argc, char const *argv[]) {
  int num;
  std::cout << "몇 층짜리 하노이 타워인가요? : " << '\n';
  std::cin >> num;
  std::cout << num << "층 하노이 타워" << '\n';
  hanoi('A', 'B', 'C', num);
  return 0;
}
