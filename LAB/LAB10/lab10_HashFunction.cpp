#include <iostream>
using namespace std;

#define TABLE_SIZE 7

typedef struct{
  int key;
  int empty = true;
}hashtable;

hashtable htable[TABLE_SIZE];

int Hash(int key){
    return key % TABLE_SIZE;
}

bool findKey(int key){
  bool found = false;
  int index;
  index = Hash(key);
  if (htable[index].key == key) {
    found = true;
  }
  return found;
}

int findKeyLinear(int key){
  bool found = false;
  int index = Hash(key);
  bool loop = false;

  while (htable[index].empty && found == false && loop == false) {
    if (htable[index].key == key) {
      found = true;
    }else{
      index = (index + 1) % TABLE_SIZE;
      if (index == TABLE_SIZE) {
        loop = true;
      }
    }
  }
  return found;
}

bool insertKey(int key){
  bool check = findKey(key);
  int index = Hash(key);

  if (check == true) {
    return false;
  }else{
    htable[index].key = key;
    htable[index].empty = false;
    return true;
  }
}

bool deleteKey(int key){
  bool check = findKey(key);
  int index = Hash(key);

  if (check == false) {
    return false;
  }else{
    htable[index].empty = true;
    return true;
  }
}

bool deleteKeyLinear(int key){
  bool check = findKey(key);
  int index = Hash(key);

  if (check == false) {
    while (index != TABLE_SIZE) {
      index ++;
      if (htable[index].key == key) {
        htable[index].empty = true;
        return true;
      }
    }
  }else{
    htable[index].empty = true;
    return true;
  }
}

void printTable(){
  for (size_t i = 0; i < TABLE_SIZE; i++) {
    if (htable[i].empty == false) {
      std::cout << htable[i].key << ' ';
    }
  }
}

bool insertKeyLinear(int key){
  bool check = findKey(key);
  int index = Hash(key);

  if (check == true) {
    return true;
    }else{
      if (htable[index].empty == true) {
        htable[index].key = key;
        htable[index].empty = false;
        return true;
      }else{
        while (index != TABLE_SIZE) {
          index ++;
          if (htable[index].empty == true) {
            htable[index].key = key;
            htable[index].empty = false;
            return true;
          }
        }
        return false;
      }
  }
}

int main(int argc, char const *argv[]) {
  int select = 0;
  int key = 0;


  while (select != 4) {
    std::cout << "Enter Command : 1) Find 2) Insert 3) Delete 4) Quit" << '\n';
    std::cin >> select;
    switch (select) {
      case 1:
      std::cout << "find Key : ";
      std::cin >> key;
      {
        if (findKey(key)) {
          std::cout << "Found " << key << '\n';
        }else{
          std::cout << "Not Found!" << '\n';
        }
      }
      printTable();
      std::cout << '\n';
      break;

      case 2:
      std::cout << "Insert Key : ";
      std::cin >> key;
      {
        insertKeyLinear(key);
      }
      printTable();
      std::cout << '\n';

      break;

      case 3:
      std::cout << "Delete Key : ";
      std::cin >> key;
      {
        deleteKeyLinear(key);
      }
      printTable();
      std::cout << '\n';

      break;

      case 4:
      return 0;
      break;
    }
  }

  // insertKeyLinear(7);
  // insertKeyLinear(36);
  // printTable();
  // if (findKey(7)) {
  //   std::cout << '\n';
  //   std::cout << "find 7" << '\n';
  // }else{
  //   std::cout << "not found 7" << '\n';
  // }
  // insertKeyLinear(29);
  // insertKeyLinear(22);
  // printTable();
  // if (findKey(25)) {
  //   std::cout << '\n';
  //   std::cout << "find25" << '\n';
  // }else{
  //   std::cout << '\n';
  //   std::cout << "not found 25" << '\n';
  // }
  // deleteKeyLinear(22);
  // printTable();

  return 0;
}
