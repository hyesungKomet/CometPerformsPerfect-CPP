#include <iostream>
using namespace std;

// 4-4-3 this ������
// this: ��ü �ڽ��� �ּ� �� + �ڷ����� �������� ���� ������

class TwoNumber {
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2) {
		// ��ó�� ���������� ��ü�� ��������� ���� ������ �� �ִ�!
		this->num1 = num1;
		this->num2 = num2;
	}
	void ShowTwoNumber() {
		cout << "this(address): " << this << endl;
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void) {
	TwoNumber two(7, 8);
	two.ShowTwoNumber();
	return 0;
}