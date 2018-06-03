#include <iostream>
using namespace std;

void hanoiTower(char from, char end, char aux, int n){
  if (n == 1) {
    std::cout << "디스크 1을 " << from <<" 에서 " << end << " 로 옮김" << '\n';
  }else{
    hanoiTower(from, aux, end, n - 1);
    std::cout << "디스크 " << n << "을 " << from << " 에서 " << end << " 로 옮김" << '\n';
    hanoiTower(aux, end, from, n - 1);
  }
}

int main(int argc, char const *argv[]) {
  hanoiTower('A', 'B', 'C', 3);
  return 0;
}
