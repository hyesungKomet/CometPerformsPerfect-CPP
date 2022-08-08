#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4-4-2 Object Pointer Array(��ü ������ �迭)
// 4-4-1�� Ŭ������ ����!

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
	// Object Array ���� �� �ʱ�ȭ ���� ������
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
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~Person() {
		// �Ҵ��� �޸� ������ delete�� ���� �Ҹ�
		delete[]name;
		cout << "destructor is called" << endl;
	}
};

int main(void) {
	// ������ �迭 ����
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
		// ��ü�� �����ؼ� �� ��ü�� �ּҰ��� �迭�� ����
		soldiers[i] = new Person(namestr, age);
	}

	for (int i = 0; i < 3; i++) {
		soldiers[i]->ShowPersonInfo();
	}
	// �� 3�� new�� ��ü�� ���������� 3�� delete�� �޸𸮸� �Ҹ�����ش�
	delete soldiers[0];
	delete soldiers[1];
	delete soldiers[2];
	return 0;
}