#include <iostream>
using namespace std;

// 4-3-1 Constructor & Destructor
// ������ InitMembers��� �Լ� ȣ���ؼ� private�� ��������� �ʱ�ȭ�ߴ�
// "������"������ ���� ���ɤ�
// - Ŭ������ �̸��� ������ �Լ� �̸�
// - ��ȯ�� ����X, ��ȯ���� ����
// - ��ü ������ �� �ѹ� ȣ��
// - �����ڵ� �Լ��� �����ε�, �Ű������� ����Ʈ �� ���� ����
// - �����ڿ��� �Լ� ȣ���ؼ� �ʱ�ȭ�ϱ⵵ ��
class SimpleClass {
private:
	int num1;
	int num2;
public:
	/*
	SimpleClass() {
		num1 = 0;
		num2 = 0;
	}
	SimpleClass(int n) {
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2) {
		num1 = n1;
		num2 = n2;
	}
	*/
	SimpleClass(int n1 = 0, int n2 = 0) {
		num1 = n1;
		num2 = n2;
	}

	void ShowData() const {
		cout << num1 << " " << num2 << endl;
	}
};

int main(void) {
	// SimpleClass sc1(); �δ� �����ϸ� �ȵ�! �ڿ� ������
	// void sc1()��� �Լ��� ���� ����� ��ü������ �� �������� �� �� ���� ��!
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass *sc3 = new SimpleClass(10, 20);
	sc3->ShowData();

	return 0;
}

SimpleClass sc1() {
	SimpleClass sc(20, 30);
	return sc;
}
