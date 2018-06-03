#include <iostream>
using namespace std;

//1번

float abc(float a, float b, float c)
{
return a + b + b * c + ( a + b - c ) / ( a + b ) + 4.0;
}

//2번

float sum(float list[], int n)
{
float tsum = 0; int i;
for (i = 0; i < n; i++) tsum += list[i];
return tsum;
}

//3번

float rsum(float list[], int n)
{
if (n) return rsum(list, n-1) + list[n-1];
return 0;
}
