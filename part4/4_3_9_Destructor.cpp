#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// 4-3-9
// Destructor(�Ҹ���)
// ��ü ������ �ݵ�� �����Ǵ� �� ������, 
// ��ü �Ҹ�� �ݵ�� �����Ǵ� �� �Ҹ���

// 1. Ŭ���� �տ� ~�� ���� ����
// 2. ��ȯ�� ����X, ��ȯ�� X
// 3. �Ű������� void���̹Ƿ� �����ε�, ����Ʈ �� ���� �Ұ���
// 4. �����ڿ� ���������� ����Ʈ �Ҹ��� ����
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
	Person Comet("ComettheGenius", 20);
	Comet.ShowPersonInfo();
	return 0;
}