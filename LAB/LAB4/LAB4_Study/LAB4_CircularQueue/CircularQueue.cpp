#include "CircularQueueHeader.hpp"

int main(int argc, char const *argv[]) {

  createQueue();

  enQueue('a');
  enQueue('b');
  enQueue('c');
  displayQueue();
    deQueue();
  enQueue('a');

  displayQueue();
  deQueue();

  return 0;
}
