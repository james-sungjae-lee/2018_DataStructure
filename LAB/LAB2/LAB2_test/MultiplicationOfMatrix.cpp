#include <iostream>
using namespace std;
#define MAX_TERMS 101

typedef struct{
  int row;
  int col;
  int value;
}term;

void storesum(term d[ ], int *totald, int row, int column, int *sum);

void mmult(term a[], term b[], term d[]) {
int i, j, column, totalB = b[0].value, totalD = 0;
int rowsA = a[0].row, colsA = a[0].col,
totalA = a[0].value, colsB = b[0].col;
int rowBegin = 1, row = a[1].row, sum = 0;
int newB[MAX_TERMS][3];
if (colsA != b[0].row) {
fprintf(stderr,"Incompatible matrices\n");
exit(EXIT_FAILURE); }
fasttranspose(b,newB);
a[totalA+1].row = rowsA;
newB[totalB+1].row = colsB;
newB[totalB+1].col = 0;
for (i = 1; i <= totalA; ) {
column = newB[1].row;
for (j = 1; j <= totalB+1; ) {
if (a[i].row != row) {
storesum(d,&totalD,row,column,&sum);
i = rowBegin;
for (;newB[j].row == column; j++);
column = newB[j].row;
}
else if (newB[j].row != column) {
storesum(d,&totalD,row,column,&sum);
i = rowBegin;
column = newB[j].row;
}else switch (COMPARE(a[i].col, newB[j].col)) {
case -1: /* go to next term in a */
i++; break;
case 0: /* add terms, go to next term in a and b */
sum += ( a[i++].value * newB[j++].value);
break;
case 1: /* advance to next term in b */
j++;
}
}
for (; a[i].row ==row; i++);
rowBegin = i, row = a[i].row;
}
d[0].row = rowsA;
d [0].col = colsB;
d [0].value = totalD;
}

void storesum(term d[ ], int *totald, int row, int column, int *sum) {
/* if *sum != 0, then it along with its row and column
position is stored as the *totald+1 entry in d */
if (*sum)
if (*totald < MAX_TERMS) {
d[++*totald].row = row;
d[*totald].col = column;
d[*totald].value = *sum;
}
else{
std::cout << "Error" << '\n';
exit(1);
}
}
