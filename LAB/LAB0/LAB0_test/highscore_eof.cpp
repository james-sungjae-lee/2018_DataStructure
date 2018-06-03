#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream file_reader("highscore.txt");
  if (! file_reader.is_open()) {
    std::cout << "Could not open file! " << '\n';
  }
  vector<int> scores;
  for (size_t i = 0; i < 10; i++) {
    int score;
    if (!(file_reader >> score)) {
      break;
    }
    scores.push_back(score);
  }
  return 0;
}
