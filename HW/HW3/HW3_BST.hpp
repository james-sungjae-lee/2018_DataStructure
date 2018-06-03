// ******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW3_BST.hpp
// *
// * Description
// * : 헤더파일의 포함
// * : iostream : cin / cout 을 이용해 콘솔의 키보드로 입력받고 결과를 출력하기 위한 헤더파일입니다.
// *
// * Node 객체의 정의
// * : int data : 정수 형태의 데이터를 저장하기 위한 Node 객체 변수입니다.
//  * : Node *left : 왼쪽 노드의 위치를 가리키는 Node 포인터 변수입니다.
// * : Node *right : 오른쪽 노드의 위치를 가리키는 Node 포인터 변수입니다.
// * : friend class BST : BST 객체에서 Node 객체를 사용할 수 있도록 friend 처리를 합니다.
// *
// * BST 객체의 정의
// * : Node *root : Binary Search Tree 에서 가장 윗 노드인 root 노드를 가리키는 포인터 변수입니다.
// * : Node *insertBST(Node *p, int data) : BST 에 넣고자 하는 정수를 data 변수로 받아, 재귀 형태로 삽입하는 함수입니다.
// * : Node *findMin(Node *p) : BST 에서 가장 작은 값을 찾아 그 노드를 포인터로 반환하는 재귀 형태의 함수입니다.
// * : Node *deleteBST(Node *p, int key) : BST에서 삭제하고자 하는 정수를 key 변수로 받아, 재귀 형태로 탐색, 삭제하는 함수입니다.
// * : Node *searchBST(Node *p, int key) : BST에서 탐색하고자 하는 정수를 key 변수로 받아, 재귀 형태로 탐색하여 존재 여부를 출력하는 함수입니다.
// * : void drawTree(Node *p, int level) : BST의 전체 노드를 트리 형태로 출력하는 함수입니다.
// * : public 의 동일 이름 함수들 : 위의 private 함수를 받아와, root부터 시작하도록 호출하는 함수입니다. 정의와 함께 구현했습니다.
// ********************************************************************************************************************

#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  friend class BST;
};

class BST{
private:
  Node *root;
  Node *insertBST(Node *p, int data);
  Node *findMin(Node *p);
  Node *deleteBST(Node *p, int key);
  Node *searchBST(Node *p, int key);
  void drawTree(Node *p, int level);

public:
  void insertBST(int data){root = insertBST(root, data);}
  void deleteBST(int key){root = deleteBST(root, key);}
  void searchBST(int key){searchBST(root, key);}
  void drawTree(){drawTree(root, 1);}
};
