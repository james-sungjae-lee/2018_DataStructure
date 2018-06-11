#include "lab3.hpp"

int main(void){
  std::cout << "Write Calculate1 " << '\n';
  std::cout << "Input : " ;
  std::cin >> expr;
  std::cout << expr << '\n';
  postfix();
  std::cout << "Ouput : " << eval() ;
  return 0;
}
