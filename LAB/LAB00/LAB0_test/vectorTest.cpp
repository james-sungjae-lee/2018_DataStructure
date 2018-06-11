#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Create a vector containing integers
    std::vector<int> v(1);
    // Iterate and print values of vector
    for(int n : v) {
        std::cout << n << '\n';
    }
}
