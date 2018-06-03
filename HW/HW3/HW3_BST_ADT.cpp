// ******************************************************************************************************************
// * Name : 이성재
// * Student ID : 20132651
// * Program ID : HW3_BST_ADT.cpp
// * description : HW3_BST.hpp 파일에서 정의한 priavte 영역의 프로토타입 함수의 구현입니다.
// ********************************************************************************************************************

#include "HW3_BST.hpp"

// ********************************************************************************************************************
// * function : Node *BST::insertBST(Node *p, int data)
// * description : BST에서 data 변수가 들어갈 자리를 찾고, 그 위치에 새로운 노드를 생성합니다.
// *
// * Variable
// * : Node *p : 처음에는 root 포인터로 시작하여, 재귀 함수가 작동하면 left 혹은 right 포인터가 들어갑니다.
// * : int data : 새롭게 넣고자 하는 정수형 데이터입니다.
// *
// * Algorithm description
// * : 1. 함수가 처음 호출되면, p는 root로 설정되어 시작됩니다. p는 현재 보고 있는 노드의 위치입니다.
// * : 2. 만약 현재 보고 있는 노드가 NULL이라면, data값을 삽입해야 하는 위치이며, 이곳에 새로운 노드를 만듭니다.
// * :    생성한 노드 객체의 p->data 변수에는 새롭게 받아온 data값을 넣습니다.
// * :    새롭게 노드를 생성했으므로, p->left 와 p->right는 NULL값으로 초기화합니다.
// * : 3. 만약 현재 보고 있는 노드가 NULL이 아니라면 해당 노드의 데이터와 새롭게 추가하려는 data값을 비교합니다.
// * : 3-1. 만약 새롭게 추가되는 data 값이 더 작다면, BST 규칙에 따라 왼쪽에 추가되어야 합니다.
// * :      왼쪽에 추가하기 위해 p->left 포인터를 재귀 형태로 호출된 insertBST함수로 대입합니다. 현재 보고 있는 노드는 left 노드로 변경합니다.
// * : 3-2. 만약 새롭게 추가되는 data 값이 더 크다면, BST 규칙에 따라 오른쪽에 추가되어야 합니다.
// * :      오른쪽에 추가하기 위해 p->right 포인터를 재귀 형태로 호출된 insertBST함수로 대입합니다. 현재 보고 있는 노드는 right 노드로 변경합니다.
// * : 4. 재귀함수가 작동하도록 새롭게 생성된 노드의 위치인 p를 반환합니다.
// ********************************************************************************************************************

Node *BST::insertBST(Node *p, int data){
  if (p == NULL) {
    p = new Node;
    p->data = data;
    p->left = NULL;
    p->right = NULL;
  }else if (data < p->data) {
    p->left = insertBST(p->left, data);
  }else if (data > p->data) {
    p->right = insertBST(p->right, data);
  }
  return p;
}

// ********************************************************************************************************************
// * function : Node *BST::deleteBST(Node *p, int key)
// * description : BST에서 삭제할 key의 위치를 찾고, 그 위치의 노드를 삭제합니다.
// *
// * Variable
// * : Node *p : 처음에는 root 포인터로 시작하여, 재귀 함수가 작동하면 left 혹은 right 포인터가 들어갑니다.
// * : int key : 삭제하고자 하는 정수형 변수입니다.
// *
// * Algorithm description
// * : 1. 함수가 처음 호출되면 현재 바라보는 노드의 위치인 p는 root로 설정됩니다.
// * : 2. root 에서 시작해 삭제하려는 key가 현재 바라보는 p보다 작다면 왼쪽으로, 크다면 오른쪽으로 재귀호출합니다.
// * : 3. 삭제하려는 노드를 찾았을 때, 해당 노드에 대해 3가지의 경우가 존재합니다. 각각에 대해 설명하겠습니다.
// * : 3-1. 삭제하려는 노드의 left / right 가 모두 NULL 값을 가지고 있을 경우 = leaf 노드일 경우
// * :      이 경우에는 if( p->left = NULL ) 조건문에서 먼저 걸리게 됩니다. 따라서 p를 p->right로 대입해 주면,
// * :      해당 경우에서 p 는 NULL 값을 갖게 되고, 상위 level 의 p 는 다음 노드의 값으로 NULL 을 갖게 됩니다.
// * :      이에 자연스럽게 p는 사라지게 됩니다. 이 때 메모리 누수가 일어나지 않도록 p를 temp에 저장한 뒤 delete해줍니다.
// * : 3-2. 다음은 삭제하려는 노드의 left 나 right 둘 중 하나가 NULL 값을 가지고 있을 경우입니다.
// * :      이 경우는 위의 상황과 동일하지만, left와 right 중 어느 쪽이 NULL값인가에 따라 걸리는 조건문이 다릅니다.
// * :      left 가 NULL일 경우에는 p 를 right 노드로 설정하고, right 가 NULL 일 때는 그 반대로 p를 left 노드로 설정합니다.
// * :      마찬가지로 상위 level의 p 의 다음 노드의 값으로 left / right로 변경된 p값이 저장되면서, 변경되기 이전의 p값은 자연스럽게 삭제됩니다.
// * : 3-3. 마지막으로 삭제하려는 노드의 left 와 right 노드 모두 NULL값이 아닌, 특정 값이 들어있는 경우입니다.
// * :      이 경우에는 else if(p->left && p->right) 조건문에 걸려 작동하게 됩니다.
// * :      우선 임시로 만들어둔 temp 노드 포인터에 findMin 함수를 p->right 노드부터 찾아내어 호출한 값을 저장합니다.
// * :      이 과정은 오른쪽 노드에서 가장 작은 값을 찾아내어 현재 위치인 p의 데이터로 설정하기 위함이며, p->left 에서 findMax 함수로 노드를 저장하는 것도 가능합니다.
// * :      findMin 함수는 특정한 노드를 기준으로 가장 작은 값, 즉 가장 왼쪽에 있는 노드를 찾아내는 함수이며, 아래에 함께 구현되어 있습니다.
// * :      이렇게 최솟값을 가진 노드를 찾아낸 다음, 해당 노드의 데이터를 p에 저장합니다.
// * :      마지막으로 찾아냈던 노드를 삭제해 주는 과정을 거치면 모든 과정이 완료됩니다.
// ********************************************************************************************************************

Node *BST::deleteBST(Node *p, int key){
  Node *temp;
  if (p == NULL) {
    std::cout << key <<" is not found!" << '\n';
    return NULL;
  }else if (key < p->data) {
    p->left = deleteBST(p->left, key);
  }else if (key > p->data) {
    p->right = deleteBST(p->right, key);
  }else if (p->left && p->right) {
    temp = findMin(p->right);
    p->data = temp->data;
    p->right = deleteBST(p->right, p->data);
  }else{
    temp = p;
    if (p->left == NULL) {
      p = p->right;
    }else if(p->right == NULL) {
      p = p->left;
    }
    delete temp;
  }
  return p;
}

// ********************************************************************************************************************
// * function : Node *BST::findMin(Node *p)
// * description : 노드 포인터를 받아, 해당 노드를 root로 보았을 때 가장 작은 값을 가진 노드를 반환하는 함수입니다.
// *
// * Variable
// * : Node *p : 탐색을 시작하기 위한 노드 포인터입니다.
// *
// * Algorithm description
// * : 1. 가장 먼저 들어온 노드 p가 NULL값인지 검사합니다. 만약 NULL이라면 더 이상 탐색할 필요가 없으므로 NULL을 반환합니다.
// * : 2. 만약 p->left, 왼쪽 노드가 NULL이라면 더 이상 왼쪽으로 진행할 곳이 없으므로 p를 반환합니다.
// * : 3. p->left 가 NULL이 아니라면, 즉 왼쪽으로 진행 가능한 노드가 존재한다면 재귀 호출을 이용해 계속해서 진행합니다.
// ********************************************************************************************************************

Node *BST::findMin(Node *p){
  if (p == NULL) {
    return NULL;
  }else if (p->left == NULL) {
    return p;
  }else{
    return findMin(p->left);
  }
}

// ********************************************************************************************************************
// * function : Node *BST::searchBST(Node *p, int key)
// * description : BST에서 탐색하려는 key값이 들어있는 노드를 찾고, 반환합니다.
// *
// * Variable
// * : Node *p : 처음에는 root 포인터로 시작하여, 재귀 함수가 작동하면 left 혹은 right 포인터가 들어갑니다.
// * : int key : 찾고자 하는 정수형 변수 key값입니다.
// *
// * Algorithm description
// * : 1. 가장 먼저 들어온 노드 p가 NULL값인지 검사합니다. 만약 NULL이라면 해당 key값을 찾지 못한 것이므로
// * :    key is not found 를 출력하고, NULL을 반환합니다.
// * : 2. 만약 key 값이 현재의 노드 p보다 작다면 왼쪽으로, 크다면 오른쪽으로 이동하여 찾아야 하므로
// * :    재귀 형태로 각각 p->left 와 p->right 를 p에 대입하여 호출합니다.
// * : 3. 현재 p의 data보다 작지도, 크지도 않다면 p의 data 와 동일한 값이므로 key가 찾아졌다고 출력합니다.
// ********************************************************************************************************************

Node *BST::searchBST(Node *p, int key){
  if (p == NULL) {
    std::cout << key << " is not found" << '\n';
    return NULL;
  }else if (key < p->data) {
    return searchBST(p->left, key);
  }else if (key > p->data) {
    return searchBST(p->right, key);
  }else{
    std::cout << key << " is found!" << '\n';
    return p;
  }
}

// ********************************************************************************************************************
// * function : void BST::drawTree(Node *p, int level)
// * description : 현재 존재하는 BST의 모든 노드와 그 관계를 level에 따라 형태를 그립니다.
// *
// * Variable
// * : Node *p : 처음에는 root 포인터로 시작하여, 재귀 함수가 작동하면 left 혹은 right 포인터가 들어갑니다.
// * : int level : 처음에는 가장 상위 level인 1부터 시작하여, 재귀 함수가 작동할 때 마다 1씩 증가합니다.
// *
// * Algorithm description
// * : 1. 가장 먼저 현재의 노드인 p가 NULL이 아니고, level이 7 이하일 때 출력을 진행합니다. 이 때 level의 깊이는
// * :    자신이 출력하고자 하는 깊이에 따라 더 증가시키거나 감소시킬 수 있습니다.
// * : 2. 가로로 Tree를 그려야 하기 때문에 가장 윗줄에는 가장 오른쪽의 노드가 출력되어야 합니다.
// * :    그렇기 때문에 가장 먼저 p->right를 기준으로 함수를 재귀호출 합니다. 이 때 level을 증가시켜 깊이를 표시합니다.
// * : 3. 현재 레벨이 높을수록 (깊이가 깊을수록 ) 노드가 그려지는 위치가 오른쪽에 있어야 하기 때문에
// * :    레벨의 갯수만큼 공백을 출력합니다. 공백이 출력된 다음, 해당 위치인 p의 data를 출력합니다.
// * : 4. 다음으로는 현재 출력하려는 데이터에 연결된 left / right 노드가 NULL인지 아닌지에 따라 트리 구조를 표시합니다.
// * :    만약 노드가 둘 다 존재한다면 " < " 노드가 오른쪽에만 존재한다면 " / " 왼쪽에만 존재한다면 " \ " 를 출력합니다.
// * : 5. 이상 오른쪽으로의 재귀 이후에는, 왼쪽으로 재귀하여 출력합니다. 이를 위해 p->left를 기준으로 재귀호출합니다.
// ********************************************************************************************************************

void BST::drawTree(Node *p, int level){
  if (p != 0 && level <= 7) {
    drawTree(p->right, level + 1);
    for (size_t i = 1; i <= (level-1); i++) {
      std::cout << "      ";
    }
    std::cout << p->data;
    if (p->left != 0 && p->right != 0)
      std::cout << "  <" << '\n';
    else if (p->right != 0)
      std::cout << "   /" << '\n';
    else if (p->left != 0)
      std::cout << "   \\" << '\n';
    else
      std::cout << '\n';
    drawTree(p->left, level+1);
  }
}
