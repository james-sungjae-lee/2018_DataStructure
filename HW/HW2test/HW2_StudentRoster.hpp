#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

ifstream inStream;

struct Node{
public:
  char name;
  int idNum;
  string major;
  char grade;
  Node *next;
  friend class List;
};

class List{
public:
  Node *head;
public:
  List(){head = NULL;}
  void insertNode(char name, int idNum, string major, char grade);
  void displayNode();
  void insertByNameNode(char name, int idNum, string major, char grade);
  void displayGradeNode();
  void displayMajorNode();
  bool isEmpty();
};

int problem1();
int problem3();

char tempName, tempGrade;
string tempMajor;
int tempIdNum;
List student1;
List student2;
int concatenateList();
