#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4-4-2 Object Pointer Array(객체 포인터 배열)
// 4-4-1과 클래스는 동일!

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
	// 포인터 배열 선언
	Person *soldiers[3];
	char namestr[100];
	char* strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++) {
		cout << "name: ";
		cin >> namestr;
		cout << "age: ";
		cin >> age;
		// 객체를 생성해서 이 객체의 주소값을 배열에 저장
		soldiers[i] = new Person(namestr, age);
	}

	for (int i = 0; i < 3; i++) {
		soldiers[i]->ShowPersonInfo();
	}
	// 총 3번 new로 객체를 생성했으니 3번 delete로 메모리를 소멸시켜준다
	delete soldiers[0];
	delete soldiers[1];
	delete soldiers[2];
	return 0;
}