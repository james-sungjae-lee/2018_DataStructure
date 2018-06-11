#include <fstream>
#include <iostream>
#include <vector>

// Run by script 는 cmd + I 이다. 이 때는 오류발생 x
// Run by gpp-compileer 는 F5 이다. 이 때는 오류발생 O
// script 로 실행 시 입력이 불가하기 때문에 다음에서 문제 발생
// gpp-compiler 에서는 왜 정상 작동하지 않는가?

using namespace std;

int main(int argc, char const *argv[]) {
  fstream file(
    "highscore2.txt",
    ios::in | ios::out
  );
  if (!file.is_open()) {
    std::cout << "Could not open file!" << '\n';
    return 0;
  }
  int new_high_score;
  std::cout << "Enter a new high score: " ;
  std::cin >> new_high_score;

  streampos pre_score_pos = file.tellg();
  int cur_score;
  while (file >> cur_score) {
    if (cur_score < new_high_score) {
      break;
    }
    pre_score_pos = file.tellg();
  }

  if (file.fail() && !file.eof()) {
    std::cout << "Bad score/read--exiting" << '\n';
    return 0;
  }
  file.clear();

  file.seekg(pre_score_pos);

  std::vector<int> scores;
  while (file >> cur_score) {
    scores.push_back(cur_score);
  }
  if (!file.eof()) {
    std::cout << "Bad score/read--exiting" << '\n';
    return 0;
  }
  file.clear();
  file.seekg(pre_score_pos);
  if (pre_score_pos != streampos(0)) {
    file << endl;
  }
  file << new_high_score << endl;
  for(vector<int>::iterator itr = scores.begin(); itr != scores.end(); ++itr){
    file << *itr << endl;
  }
}
