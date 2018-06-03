#include "stack.hpp"

using namespace std;

int mazeSolve();

int main(int argc, char const *argv[]) {
  createStack();

  return 0;
}

int mazeSolve(){
  int maze[6][6]= {{1,1,1,1,1,1}, {1,0,1,1,1,1}, {1,0,0,0,0,1}, {1,1,0,1,1,1}, {1,0,1,0,0,1}, {1,1,1,1,1,1}};
  int mark[6][6]= {{0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}};
  typedef struct {int vert; int horiz; }offsets;
  offsets move[8];

  typedef struct {int row; int col; int dir;}element;
  element temp[10];

  move[0].vert = -1; move[0].horiz = 0; //n
  move[1].vert = -1; move[1].horiz = 1; //ne
  move[2].vert = 0; move[2].horiz = 1; //e
  move[3].vert = 1; move[3].horiz = 1; //se
  move[4].vert = 1; move[4].horiz = 0; //s
  move[5].vert = 1; move[5].horiz = -1; //sw
  move[6].vert = 0; move[6].horiz = -1; //w
  move[7].vert = -1; move[7].horiz = -1; //nw

  mark[1][1] = 1;
  push(mark[1][1]);

  int exitRow = 4;
  int exitCol = 4;
  bool found = false;

  int i = 1; // 처음 위치??
  int j = 1;  // 처음 위치??
  int d = 0;

  while (!isEmpty() && !found) { //스택이 비어있지 않으면서 길을 찾지 못함. =
    pop();
    while (d < 8 && !found) {
      int g = i + move[d].vert;
      int h = j + move[d].horiz;
      if ((g == exitRow)&&(h == exitCol)) {
        found = true;
        std::cout << "도착!" << '\n';
        return 0;
      }
      if ((!maze[g][h])&&(!mark[g][h])) {
        mark[g][h] = 1;
        temp.row = i;
        temp.col = j;
        temp.dir = d + 1;
        push()
      }else{
        d++;
      }
    }
    std::cout << "길이 없습니다." << '\n';
  }



















    return 0;
}
