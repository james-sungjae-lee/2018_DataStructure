// *******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW3_BST.cpp
// *
// * Algorithm Description
// * :
// * : 정수 데이터를 Binary Search Tree 구조로 Insert(저장) Delete(삭제) Search(탐색) Print(출력) 하는 알고리즘입니다
// * : 1. Binary Search Tree의 기본적인 형태인 Node 와 Tree 구조를 나타내는 BST객체를 정의합니다.
// * :    Node 객체 내부에는 정수 데이터와 Tree 구조를 위한 left / right 라는 이름의 Node 포인터를 정의합니다.
// * : 2. Tree 구조를 만들기 위한 BST 객체에는 Tree의 루트 노드를 표시하는 포인터 root 와
// * :    Tree 구조를 구현하는 insertBST / deleteBST 함수가 정의되어 있습니다.
// * :    추가적으로 Tree 구조에서 원하는 데이터를 찾기 위한 searchBST 함수와 Tree 구조 전체를 출력하는 drawTree 함수가 정의되어 있습니다.
// * : 3. BST 객체는 private 영역과 public 영역으로 구분되어 있으며, 모든 함수의 실제 작동 부분은 private 영역에,
// * :    함수 호출 부분은 public 영역에 구현되어 있습니다. root 포인터 또한 외부에서 접근하지 못하도록 private 영역에 정의됩니다.
// * : 4. 현재 위치인 HW3_BST.cpp 파일의 main 함수에서는 BST 객체에서 public 으로 정의된 함수들을 메뉴 선택으로 불러와 작동시킵니다.
// * :    헤더 파일인 HW3_BST.hpp 파일에서는 Node 객체와 BST 객체가 정의됩니다. BST 객체의 함수 프로토타입이 이곳에서 정의됩니다.
// * :    ADT 파일인 HW3_BST_ADT.cpp 파일에서는 private 영역에서 정의되었던 프로토타입 함수의 구체 내용이 작성되어 있습니다.
// * Variables
// * :    BST 를 구현하기 위한 변수들은 모두 헤더 파일과 ADT 파일에 정의되어 있습니다.
// * :    외부의 키보드 입력을 통해 메뉴의 선택하기 위한 정수형 select 변수가 정의되어 있습니다.
// * :    외부의 키보드 입력을 통해 Tree에 자료를 저장 / 삭제 / 탐색하기 위한 정수형 num 변수가 정의되어 있습니다.
// ********************************************************************************************************************

#include "HW3_BST_ADT.cpp"

// ********************************************************************************************************************
// * function: int main
// * description
// * : 1. BST 를 메뉴 형태로 작동시키기 위한 함수입니다.
// * : 2. 메뉴를 선택하기 위한 select 변수를 정의합니다.
// * : 3. 1번 insert / 2번 delete / 3번 search / 4번 print / 5번 종료 메뉴를 통해
// * :    각각의 숫자를 입력하여 select에 저장되면 해당 기능이 작동하도록 switch 문을 작성합니다.
// * : 4. 메뉴를 반복해서 사용 가능하도록 while문을 작성하며, 종료를 선택해 select 에 5가 저장되면 반복이 종료되도록 합니다.
// * : 5. 각각의 케이스에서는 num 변수를 정의하여 insert / delete / search 의 key로 사용될 수 있도록 입력받습니다.
// * : 6. 여러 개의 숫자를 insert / delete / search 할 수 있도록 while문을 작성하며, num 변수에 0이 저장될 시 반복이 종료되도록 합니다.
// ********************************************************************************************************************

int main(int argc, char const *argv[]) {
  BST test;
  int select = 6;
  while (select != 5) {
    std::cout << "MENU : 1) Insert 2) Delete 3) Search 4) Print 5) Quit" << '\n';
    std::cout << "Enter the menu : ";
    std::cin >> select;
    std::cout << "------------------------" << '\n';
    switch (select) {
      case 1: {
        int num = 1;
        std::cout << "0 is quit to insert" << '\n';
        while (1) {
          std::cout << "Enter number to insert : ";
          std::cin >> num;
          if (num == 0) {
            break;
          }
          test.insertBST(num);
        }
        std::cout << "------------------------" << '\n';
        break;
      }
      case 2:{
        int num = 1;
        std::cout << "0 is quit to delete" << '\n';
        while (1) {
          std::cout << "Enter number to delete : ";
          std::cin >> num;
          if (num == 0) {
            break;
          }
          test.deleteBST(num);
        }
        std::cout << "------------------------" << '\n';
        break;
      }
      case 3:{
        int num = 1;
        std::cout << "0 is quit to search" << '\n';
        while (1) {
          std::cout << "Enter number to search : ";
          std::cin >> num;
          if (num == 0) {
            break;
          }
          test.searchBST(num);
        }
        std::cout << "------------------------" << '\n';
        break;
      }
      case 4:{
        test.drawTree();
        std::cout << "------------------------" << '\n';
        break;
      }
      case 5:{
        break;
      }
    }
  }
  return 0;
}
