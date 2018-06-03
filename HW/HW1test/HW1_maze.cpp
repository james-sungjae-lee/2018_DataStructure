#include "stack.hpp"
using namespace std;

void mazeSolve();
createStack();

int maze[6][6]= {{1,1,1,1,1,1}, {1,0,1,1,1,1}, {1,0,0,0,0,1}, {1,1,0,1,1,1}, {1,0,1,0,0,1}, {1,1,1,1,1,1}};
int mark[6][6]= {{0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}, {0,0,0,0,0,0}};
typedef struct {short int vert; short int horiz; }offsets;
offsets move[8];
move[0].vert = -1; move[0].horiz = 0; //n
move[1].vert = -1; move[1].horiz = 1; //ne
move[2].vert = 0; move[2].horiz = 1; //e
move[3].vert = 1; move[3].horiz = 1; //se
move[4].vert = 1; move[4].horiz = 0; //s
move[5].vert = 1; move[5].horiz = -1; //sw
move[6].vert = 0; move[6].horiz = -1; //w
move[7].vert = -1; move[7].horiz = -1; //nw

mark[1][1] = 1; // 첫 번째 출발 위치에 지나간 흔적을 표시함 = 0을 1로 바꿈.
push(mark[1][1]); // 출발 위치를 스택에 쌓음.

int exitRow = 4; // 종료 위치는 maze[exitRow][exitCol] 임.
int exitCol = 4;
bool found = false;

int main(int argc, char const *argv[]) {
  mazeSolve();
  return 0;
}



void mazeSolve(){
  int i = 0;
  int j = 0;
  int d = 0;
  element temp[10];

  while(!isEmpty() && !found){
    pop(); // 추가 필요

    while (d < 8 && !found) {
      int g = i + move[d].vert;
      int h = j + move[d].horiz;
      if ((g == exitRow)&&(h == exitCol)) {
        found = true;
        std::cout << "도착!" << '\n';
      }
      if ((!maze[g][h])&&(!mark[g][h])) {
        mark[g][h] = 1;
        temp.row = i;
        temp.col = j;
        temp.dir = d + 1;
        push(temp);

      }else{
        d++;
      }
    }
    std::cout << "길이 없습니다." << '\n';
  }























}
