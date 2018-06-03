#include "HW2_StudentRoster.hpp"

bool List::isEmpty(){
  if (head == NULL) {
    return true;
  }else{
    return false;
  }
}

void List::insertNode(char name, int idNum, string major, char grade) {
  Node *temp = new Node;

  temp -> name = name;
  temp -> idNum = idNum;
  temp -> major = major;
  temp -> grade = grade;
  temp -> next = NULL;

  if (head != NULL) {
    temp -> next = head;
    head = temp;
  }else{
    head = temp;
  }
}
void List::displayNode(){
  Node *p;
  p = head;
  while (p) {
    std::cout << p->name<< " " << p->idNum << " " << p->major << " " << p->grade << '\n';
    p = p->next;
  }
}
  void List::insertByNameNode(char name, int idNum, string major, char grade) {
    Node *temp = new Node;
    Node *p;
    Node *q;
    p = head;
    q = head;


    temp -> name = name;
    temp -> idNum = idNum;
    temp -> major = major;
    temp -> grade = grade;
    temp -> next = NULL;

    if (head == 0) {
      head = temp;
    }else if (temp->name < head->name) {
      temp->next = head;
      head = temp;
    }else{
      p = head;
      while ((p!=0)&&(p->name < temp->name)) {
        q = p;
        p = p->next;
      }
      if (p!=0) {
        temp -> next = p;
        q -> next = temp;
      }else{
        q -> next = temp;
      }
    }
}

void List::displayGradeNode(){
  Node *p;

  if (head != NULL) {
    p = head;
    while (p != NULL) {
      if (p->grade == 'A') {
      std::cout << p->name << " " << p->idNum << " " << p-> major << " "<< p->grade << '\n';
      }
      p = p->next;
    }
  }else{
    std::cout << "Error!" << '\n';
  }
}

void List::displayMajorNode(){
  Node *p;

  if (head != NULL) {
    p = head;
    while (p != NULL) {
      if (p->major == "EE") {
      std::cout << p->name << " " << p->idNum << " " << p-> major << " "<< p->grade << '\n';
      }
      p = p->next;
    }
  }else{
    std::cout << "Error!" << '\n';
  }
}

int problem1(){
  inStream.open("data1.txt");
  for (size_t i = 0; i < 8; i++) {
    inStream >> tempName >> tempIdNum >> tempMajor >> tempGrade;
    student1.insertByNameNode(tempName, tempIdNum, tempMajor, tempGrade);
  }

  inStream.close();
  return 0;
}

int problem3(){
  inStream.open("data2.txt");
  for (size_t i = 0; i < 3; i++) {
    inStream >> tempName >> tempIdNum >> tempMajor >> tempGrade;
    student2.insertByNameNode(tempName, tempIdNum, tempMajor, tempGrade);
  }
  inStream.close();
  return 0;
}

int concatenateList(){
  Node *p;
  p = student1.head;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = student2.head;
  std::cout << "concatenate List student2 to student1" << '\n';
  return 0;
}
