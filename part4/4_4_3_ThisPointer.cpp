#include <iostream>
using namespace std;

// 4-4-3 this 포인터
// this: 객체 자신의 주소 값 + 자료형이 정해지지 않은 포인터

class TwoNumber {
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2) {
		// 이처럼 지역변수와 객체의 멤버변수를 쉽게 구분할 수 있다!
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