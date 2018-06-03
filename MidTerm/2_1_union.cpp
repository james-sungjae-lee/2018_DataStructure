#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  struct sexType{
	enum tagField{
		female, male
	} sex;

	union{
		int children;
		int beard;
	} u;
};

struct person{
	char name[10];
	int age;
	float salary;
	sexType sexInfo;
};

person person1;

person1.sexInfo.u.beard = 1;

person person2;
person2.sexInfo.u.children = 4;

std::cout << person2.sexInfo.u.beard << '\n';
  return 0;
}
