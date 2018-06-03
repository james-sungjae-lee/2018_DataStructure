#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
ofstream output("data.dat", ios::out | ios::binary);

int arr1[5] = {1, 2, 3, 4, 5};
output.write((char*)arr1, sizeof(arr1));
output.close();

ifstream input("data.dat", ios::in | ios::binary);

int arr2[5];
input.read((char*)arr2, sizeof(arr2));
input.close();

std::cout << arr1[0] << '\n';
std::cout << arr2[0] << '\n';
return 0;

}
