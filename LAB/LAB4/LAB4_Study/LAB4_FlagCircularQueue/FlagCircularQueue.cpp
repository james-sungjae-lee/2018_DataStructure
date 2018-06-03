#include "CircularQueueHeader.hpp"

int main(int argc, char const *argv[]) {

  createQueue();

  for (size_t i = 1; i < 11; i++) {
    enQueue(i);
  }
  displayQueue();
  
  std::cout << '\n';
  for (size_t i = 0; i < 4; i++) {
    deQueue();
  }
  displayQueue();

  std::cout << '\n';
  for (size_t i = 1; i < 4; i++) {
    enQueue(i);
  }
  displayQueue();
  return 0;
}
