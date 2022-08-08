#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4-4-1 Object Array(객체 배열)

// ClassName arr[10];
// ClassName *ptrArr = new ClassName[10];
// 이런식으로 선언
// -> 배열 인자 하나하나 생성자 호출됨 but 생성자에 인자를 전달하지 못함
// - ClassName() { } 형식의 생성자 반드시 정의되어있어야 함
class Person {
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	// Object Array 생성 시 초기화 위한 생성자
	Person() {
		name = NULL;
		age = 0;
		cout << "Person() is called" << endl;
	}
	void SetPersonInfo(char* myname, int myage) {
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person() {
		// 할당한 메모리 공간을 delete를 통해 소멸
		delete[]name;
		cout << "destructor is called" << endl;
	}
};

int main(void) {
	Person soldiers[3];
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++) {
		cout << "name: ";
		cin >> namestr;
		cout << "age: ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		soldiers[i].SetPersonInfo(strptr, age);
	}

	for (int i = 0; i < 3; i++) {
		soldiers[i].ShowPersonInfo();
	}
	return 0;
}