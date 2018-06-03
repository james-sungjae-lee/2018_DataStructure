#include <iostream>
using namespace std;

void towerHanoi (char from, char to, char aux, int n)
{
if (n==1)
std::cout << "move disk 1 from peg "<< from << " to peg " << to << '\n';
else {
towerHanoi(from, aux, to , n-1);
std::cout << "move disk " << n << " from peg "<< from << " to peg " << to << '\n';
towerHanoi(aux, to, from, n-1);
}
}

int main(int argc, char const *argv[]) {
  int num;
  std::cin >> num;
  towerHanoi('A', 'B', 'C', num);
  return 0;
}
