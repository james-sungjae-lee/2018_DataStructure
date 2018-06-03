#include <iostream>
#include <cstdio>

#define N 5
#define swap(a,b){char t = a; a = b; b = t;}

using namespace std;

void permutation(int index, char *input)
{
    if(index == N)
    {
        cout << input << endl;
        return;
    }

    for (int i = index; i < N; i++)
    {
        swap(input[index], input[i]);
        permutation(index + 1, input);
        swap(input[index], input[i]);
    }
}
int main()
{
    char str[8] = "1234567";
    permutation(0, str);
    return 0;
}
