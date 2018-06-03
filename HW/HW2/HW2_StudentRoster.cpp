// *********************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW2_StudentRoster.cpp
// *
// * Algorithm Description
// * : Student Roster 의 데이터를 읽어, SLL 형태로 저장한 다음 성적별, 학과별 데이터를 출력하는 알고리즘입니다.
// * : 1. SLL 의 기본적인 형태인 Node 구조체와 List 객체를 정의합니다. Node에는 학생의 데이터가 들어가며,
// * : List에는 SLL에 노드를 저장하기 위한 head, insert함수, display함수 등이 정의됩니다.
// * : 2. 그 외에는 추가적으로 데이터 파일에서 학생 데이터를 읽기 위한 readData함수, 리스트를 합치기 위한 concatenateList함수가 정의됩니다.
// * : 3. 1번 문제를 해결하기 위해, 먼저 data1.txt파일을 readData1 함수를 이용해 student1 List에 저장합니다.
// * : 이 때 앞에서 정의한 List내의 insertByNameNode함수를 이용해 이름순으로 List에 저장합니다. 그 다음 List의 displayNode 함수로 출력합니다.
// * : 4. 2번 문제를 해결하기 위해, 1번 문제를 해결하기 위해 만들었던 student1 List를 사용합니다. List의 displayGradeNode 함수는 헤드부터 마지막 노드까지
// * : 하나씩 확인하며 우리가 선택한 selectGrade 와 동일한 grade 를 가진 노드인지 확인합니다. 동일할 경우 해당 노드의 데이터를 출력합니다.
// * : 5. 3번 문제를 해결하기 위해, data2.txt 파일을 readData2 함수를 이용해 student2 List에 저장합니다.
// * : 그 다음, student1 리스트의 마지막 next 포인터를 student2 리스트의 head로 옮겨주는 concatenateList 함수를 이용하여
// * : 두 개의 리스트를 합쳐줍니다. 마지막으로 위의 displayGradeNode 와 동일한 방식으로 구현한 displayMajorNode 함수를 이용하여
// * : 구하고자 하는 학과인 selectMajor string을 입력하여 결과값을 출력받습니다. 이상으로 1, 2, 3번 문제를 모두 해결합니다.
// *
// * Variables
// * : HW2_StudentRoster.cpp 파일에는 변수를 정의하지 않습니다. 모든 변수는 HW2_StudentRoster.hpp 파일에 정의됩니다.
// **********************************************************

#include "HW2_StudentRosterADT.cpp"

// **********************************************************
// * function: int main
// * description
// * : 1번 문제를 해결하기 위해, readData1 함수를 실행하고,
// * : 확인을 위해 student1 리스트를 displayNode 함수로 출력합니다.
// * : 2번 문제를 해결하기 위해, student1 리스트를 displayGradeNode 함수에
// * : 'A' 변수를 넣어 실행시킵니다.
// * : 3번 문제를 해결하기 위해, readData2 함수를 실행하고,
// * : 이어서 concatenateList함수를 이용해 student2 리스트를 student1 리스트에 이어붙입니다.
// * : 확인을 위해 이어붙인 student1 리스트를 출력합니다.
// * : 마지막으로 student1 리스트를 displayMajorNode 함수에
// * : "CS" 변수를 넣어 실행시킵니다.
// **********************************************************


int main(int argc, char const *argv[]) {
  std::cout << "Problem 1" << '\n' << '\n';
  readData1();
  student1.displayNode();
  std::cout << '\n';

  std::cout << "Problem 2" << '\n' << '\n';

  student1.displayGradeNode('A');
  std::cout << '\n';

  std::cout << "Problem 3" << '\n';

  readData2();
  student2.displayNode();
  std::cout << '\n';

  concatenateList();
  std::cout << '\n';

  student1.displayNode();
  std::cout << '\n';

  student1.displayMajorNode("CS");
  return 0;
}
