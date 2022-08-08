#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4-3-9
// Destructor(소멸자)
// 객체 생성시 반드시 생성되는 게 생성자, 
// 객체 소멸시 반드시 생성되는 게 소멸자

// 1. 클래스 앞에 ~가 붙은 형식
// 2. 반환형 선언X, 반환도 X
// 3. 매개변수는 void형이므로 오버로딩, 디폴트 값 설정 불가능
// 4. 생성자와 마찬가지로 디폴트 소멸자 존재
// ex) ~AAA() { }

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
	Person Comet("ComettheGenius", 20);
	Comet.ShowPersonInfo();
	return 0;
}