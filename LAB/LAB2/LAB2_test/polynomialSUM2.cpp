#include <iostream>
#define MAX_TERMS  100
using namespace std;

void padd(int, int, int, int, int*, int*);
void attach(float, int);
int COMPARE(int, int);

typedef struct{
  float coef;
  int expon;
}Polynomial;

Polynomial terms[MAX_TERMS];
int avail;

int main(int argc, char const *argv[]) {
  int starta, finisha, startb, finishb, startd, finishd;

  terms[0].coef = 2;
  terms[0].expon = 1000;
  terms[1].coef = 1;
  terms[1].expon = 0;
  starta = 0, finisha = 2; // 2x^1000 + 1 // 시작점 0, 끝점 2

  terms[2].coef = 1;
  terms[2].expon = 4;
  terms[3].coef = 10;
  terms[3].expon = 3;
  terms[4].coef = 3;
  terms[4].expon = 2;
  terms[5].coef = 1;
  terms[5].expon = 0;
  startb = 2, finishb = 5; // 1x^4 + 10x^3 + 3x^2 + 1 // 시작점 3, 끝점 5
  avail = 6;

  padd(starta, finisha, startb, finishb, &startd ,&finishd );

  for (size_t i = startd; i < finishd; i++) {
    std::cout << terms[i].coef << "x^" ;
    std::cout << terms[i].expon ;
    if (i == finishd - 1) {
      break;
    }
    std::cout << " + " ;
  }


  return 0;
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd){
  float coefficient;
  *startd = avail;

  while (starta <= finisha && startb <= finishb) {
    switch (COMPARE(terms[starta].expon, terms[startb].expon)) {
      case -1:
        attach(terms[startb].coef, terms[startb].expon);
        startb ++;
        break;
      case 0:
        coefficient = terms[starta].coef + terms[startb].coef;
        if (coefficient) {
          attach(coefficient, terms[starta].expon);
          starta ++;
          startb ++;
          break;
        }
      case 1:
        attach(terms[starta].coef, terms[starta].expon);
        starta ++;
    }
  }

  for(; starta <= finisha ; starta++){
    attach(terms[starta].coef, terms[starta].expon);
  }
  for(; startb <= finishb ; startb++){
    attach(terms[startb].coef, terms[startb].expon);
  }
  *finishd = avail - 1;
}

void attach(float coefficient, int exponent){
  if (avail >= MAX_TERMS) {
    std::cout << "too many elements.. " << '\n';
    exit(1);
  }
  terms[avail].coef = coefficient;
  terms[avail].expon = exponent;
  avail ++;
}

int COMPARE(int x, int y){
  if (x < y) {
    return -1;
  }else if(x == y){
    return 0;
  }else{
    return 1;
  }
}
