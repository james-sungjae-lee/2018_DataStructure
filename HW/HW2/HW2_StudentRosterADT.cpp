// *********************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW2_StudentRosterADT.cpp
// * description : .hpp 파일에서 정의한 프로토타입 함수의 구현입니다.
// **********************************************************

#include "HW2_StudentRoster.hpp"

// **********************************************************
// * function : List::displayNode
// * description : 리스트의 전체 노드를 차례로 출력합니다.
// * Node 하나를 가리키는 포인터 변수 p를 정의하고, head를 가리키도록 합니다.
// * p가 참일 동안 반복하는 while반복문을 사용합니다. p가 NULL을 가리키게 되면 반복을 중단합니다.
// * head 노드부터 노드의 name, idNum, major, grade를 차례로 출력하고
// * 다음 노드로 넘어갑니다. 마지막 노드로 넘어가 p가 NULL을 가리키게 되어 반복을 중단합니다.
// **********************************************************
void List::displayNode(){
  Node *p;
  p = head;
  while (p) {
    std::cout << p->name<< " " << p->idNum << " " << p->major << " " << p->grade << '\n';
    p = p->next;
  }
}

// **********************************************************
// * function : List::insertByNameNode
// * description : 리스트에 새로운 노드를 name변수의 알파벳 순으로 넣습니다.
// *
// * Variable
// * inName : 데이터로부터 읽어온 학생의 이름입니다.
// * inIdNum : 데이터로부터 읽어온 학생의 학번입니다.
// * inMajor : 데이터로부터 읽어온 학생의 전공입니다.
// * inGrade : 데이터로부터 읽어온 학생의 성적입니다.
// * Node *temp : 새로운 노드입니다.
// * Node *p : 현재 노드의 위치를 저장해놓기 위한 포인터입니다.
// * Node *q : 현재 노드 이전의 노드 위치를 저장해놓기 위한 포인터입니다.
// *
// * Algorithm description
// * 1. temp 노드의 name, idNum, major, grade에
// * 데이터로 받아온 inName, inIdNum, inMajor, inGrade 변수를 저장합니다.
// * 2. 만약 head 값이 0이라면, 즉 현재 비어있는 리스트라면,
// * 새 노드인 temp를 head 로 지정하고 함수를 마칩니다.
// * 3. 만약 head 값이 0이 아니라면, temp 의 name과 head의 name값을 비교합니다.
// * temp의 name값이 더 작다면, 즉 알파벳에서 temp가 더 앞에 있다면
// * temp 노드는 head 앞에 와야 하므로 temp의 다음 노드의 포인터인 next가 head를 가리키게 하고 마칩니다.
// * 4. 만약 head의 값이 0이 아니고, temp의 name값이 head의 name값보다 크다면,
// * 먼저 앞에서 정의한 p 와 q가 head를 가리키도록 합니다.
// * 그 다음, p 가 NULL 이 아니고, 동시에 p의 name이 temp 의 name보다 작을 때까지 반복하는 while 반복문을 작성합니다.
// * 조건이 참이 아니라면 q 에 p가 이동하기 전의 값을 저장하고, p는 다음 노드로 한 번 이동합니다.
// * 5. 위의 반복문이 끝난 다음, p는 temp의 next가 들어가야 할 위치를 가리키고 있으며, q는 temp이전의 노드를 가리킵니다.
// * 만약 p가 리스트 중간의 노드를 가리키고 있다면, temp의 다음 노드는 p가 되며, q의 다음 노드는 temp가 됩니다.
// * 그렇지 않고 p가 리스트의 마지막 다음값인 NULL을 가리킨다면, 리스트의 마지막 값인 q의 다음 노드가 temp가 됩니다.
// **********************************************************
void List::insertByNameNode(char inName, int inIdNum, string inMajor, char inGrade){
  Node *temp = new Node;
  Node *p;
  Node *q;


  temp -> name = inName;
  temp -> idNum = inIdNum;
  temp -> major = inMajor;
  temp -> grade = inGrade;
  temp -> next = NULL;

  if (head == 0) {
    head = temp;
  }else if (temp -> name < head -> name) {
    temp -> next = head;
    head = temp;
  }else{
    p = head;
    q = head;
    while ((p != 0) && (p -> name < temp -> name)) {
      q = p;
      p = p -> next;
    }
    if (p != 0) {
      temp -> next = p;
      q -> next = temp;
    }else{
      q -> next = temp;
    }
  }
}

// **********************************************************
// * function : List::displayGradeNode
// * description : 리스트의 특정 Grade를 가진 노드만 출력합니다.
// * Variable
// * Node *p : 현재 노드의 위치를 저장해놓기 위한 포인터입니다.
// *
// * Algorithm description
// * 1. 먼저, head 가 NULL값이라면 리스트가 비어있는 상태이므로 에러 메세지를 출력하고 종료합니다.
// * head가 NULL값이 아니라면, p 를 head를 가리키도록 합니다.
// * 2. p가 NULL값이 아닐 동안 반복하는 while 반복문을 작성합니다.
// * 만약 현재 노드 p의 grade 값이 입력받은 selectGrade 와 같다면 해당 노드를 출력합니다.
// * 3. while문을 반복할 동안 p는 p의 next로 이동합니다.
// * p가 모든 노드를 지나  NULL값이 된다면 반복문을 종료합니다.
// **********************************************************
void List::displayGradeNode(char selectGrade) {
  Node *p;

  if (head != NULL) {
    p = head;
    while (p != NULL) {
      if (p -> grade == selectGrade) {
        std::cout << p->name << " " << p->idNum << " " << p-> major << " "<< p->grade << '\n';
      }
      p = p -> next;
    }
  }else{
    std::cerr << "Node Head is not Exist!" << '\n';
  }
}

// **********************************************************
// * function : List::displayMajorNode
// * description : 리스트의 특정 Major 값을 가진 노드만 출력합니다.
// * Variable
// * Node *p : 현재 노드의 위치를 저장해놓기 위한 포인터입니다.
// *
// * Algorithm description
// * 1. 먼저, head 가 NULL값이라면 리스트가 비어있는 상태이므로 에러 메세지를 출력하고 종료합니다.
// * head가 NULL값이 아니라면, p 를 head를 가리키도록 합니다.
// * 2. p가 NULL값이 아닐 동안 반복하는 while 반복문을 작성합니다.
// * 만약 현재 노드 p의 grade 값이 입력받은 selectMajor 와 같다면 해당 노드를 출력합니다.
// * 3. while문을 반복할 동안 p는 p의 next로 이동합니다.
// * p가 모든 노드를 지나  NULL값이 된다면 반복문을 종료합니다.
// **********************************************************
void List::displayMajorNode(string selectMajor) {
  Node *p;

  if (head != NULL) {
    p = head;
    while (p != NULL) {
      if (p -> major == selectMajor) {
        std::cout << p->name << " " << p->idNum << " " << p-> major << " "<< p->grade << '\n';
      }
      p = p -> next;
    }
  }else{
    std::cerr << "Node Head is not Exist!" << '\n';
  }
}

// **********************************************************
// * function : List::readData1
// * description : data1.txt 파일에서 데이터를 순차적으로 읽어와 student1 리스트에 저장합니다.
// *
// * Algorithm description
// * 1. 앞에서 정의한 inStream 의 open 메소드를 활용하여 data1.txt 파일을 활성화시킵니다.
// * 2. 8개의 데이터가 있으므로, 8번 반복하는 반복문을 작성합니다.
// * 3. 데이터 파일에서 값을 순차적으로 읽어와 tempName, tempIdNum, tempMajor, tempGrade 에 저장합니다.
// * 4. 저장된 temp 데이터들을 student1 에 insertByNameNode 함수를 이용하여 이름 알파벳 순으로 입력합니다.
// * 5. inStream 의 close 메소드를 활용해 파일을 닫습니다.
// **********************************************************
int readData1(){
  inStream.open("data1.txt");
  for (size_t i = 0; i < 8; i++) {
    inStream >> tempName >> tempIdNum >> tempMajor >> tempGrade;
    student1.insertByNameNode(tempName, tempIdNum, tempMajor, tempGrade);
  }
  inStream.close();
  return 0;
}

// **********************************************************
// * function : List::readData2
// * description : data2.txt 파일에서 데이터를 순차적으로 읽어와 student2 리스트에 저장합니다.
// *
// * Algorithm description
// * 1. 앞에서 정의한 inStream 의 open 메소드를 활용하여 data2.txt 파일을 활성화시킵니다.
// * 2. 8개의 데이터가 있으므로, 8번 반복하는 반복문을 작성합니다.
// * 3. 데이터 파일에서 값을 순차적으로 읽어와 tempName, tempIdNum, tempMajor, tempGrade 에 저장합니다.
// * 4. 저장된 temp 데이터들을 student2 에 insertByNameNode 함수를 이용하여 이름 알파벳 순으로 입력합니다.
// * 5. inStream 의 close 메소드를 활용해 파일을 닫습니다.
// **********************************************************
int readData2(){
  inStream.open("data2.txt");
  for (size_t i = 0; i < 3; i++) {
    inStream >> tempName >> tempIdNum >> tempMajor >> tempGrade;
    student1.insertByNameNode(tempName, tempIdNum, tempMajor, tempGrade);
  }
  inStream.close();
  return 0;
}

// **********************************************************
// * function : concatenateList
// * description : student2 리스트를 student1 리스트에 이어붙입니다.
// * Variable
// * Node *p : 현재 노드의 위치를 저장해놓기 위한 포인터입니다.
// *
// * Algorithm description
// * 1. p의 위치를 student1 의 헤드로 지정합니다.
// * 2. p가 student1 의 마지막 노드를 가리킬 때 까지 p를 다음 노드로 이동시키는 반복문을 작성합니다.
// * 3. p가 마지막 노드를 가리킬 때, 그 다음 노드가 student2의 head가 되도록 합니다.
// * 4. concatenate 완료 문구를 출력합니다.
// **********************************************************
int concatenateList(){
  Node *p;
  p = student1.head;
  while (p -> next != NULL) {
    p = p -> next;
  }
  p -> next = student2.head;
  std::cout << "concatenate List student2 to student1 Complete" << '\n';
  return 0;
}
