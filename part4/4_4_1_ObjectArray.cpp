#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4-4-1 Object Array(��ü �迭)

// ClassName arr[10];
// ClassName *ptrArr = new ClassName[10];
// �̷������� ����
// -> �迭 ���� �ϳ��ϳ� ������ ȣ��� but �����ڿ� ���ڸ� �������� ����
// - ClassName() { } ������ ������ �ݵ�� ���ǵǾ��־�� ��
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