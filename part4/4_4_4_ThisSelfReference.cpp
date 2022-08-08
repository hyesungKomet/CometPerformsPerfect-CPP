#include <iostream>
using namespace std;

// 4-4-4 this�� ���� Self-Reference ��ȯ

// ��ü �ڽ��� ������ ����� �� �ִ� �������� ��ȯ��
// ���� ���� ���� ����
// ex) int num = 7;, int &ref = num;
// �� �� num�� ������ ����(������)�� ���޵�(�������� Ȯ���� �ƴ�!)
// ���� num�� ������ �� �ִ� ���� ���� ������ ref�� ���޵Ǿ� ref�� num�� ������!

class SelfRef {
private:
	int num;
public:
	SelfRef(int n) :num(n) {
		cout << "Object created" << endl;
	}
	// ��ȯ���� SelfRef&, ��ȯ�� *this
	// -> ��ü �ڽ��� ������ �� �ִ� ���� ��(������ ����)�� ��ȯ��
	SelfRef& Adder(int n) {
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber() {
		cout << num << endl;
		return *this; //�̰͵� *this�� ��ȯ�ؼ� main�� �� �Ʒ�ó�� �̾ �� ���� ��!
		// ShowTwoNumber().Adder(15)�κ�!
	}
};

int main(void) {
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(7);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(5).ShowTwoNumber().Adder(15).ShowTwoNumber();
	return 0;
}