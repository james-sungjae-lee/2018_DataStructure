#include <iostream>

using namespace std;

int ncr(int n,int r)
{
    if(r==0)
        return 1;
    return ncr(n-1,r-1)*n;
}

int main(int argc, char const *argv[]) {
  std::cout << ncr(3,2) << '\n';
  return 0;
}
