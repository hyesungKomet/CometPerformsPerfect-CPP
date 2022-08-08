#include <iostream>
using namespace std;

// 4-4-4 this를 통한 Self-Reference 반환

// 객체 자신의 참조에 사용할 수 있는 참조자의 반환문
// 참조 값에 대한 이해
// ex) int num = 7;, int &ref = num;
// 이 때 num의 참조의 정보(참조값)가 전달됨(변수값은 확실히 아님!)
// 변수 num을 참조할 수 있는 참조 값이 참조자 ref에 전달되어 ref가 num을 참조함!

class SelfRef {
private:
	int num;
public:
	SelfRef(int n) :num(n) {
		cout << "Object created" << endl;
	}
	// 반환형이 SelfRef&, 반환은 *this
	// -> 객체 자신을 참조할 수 있는 참조 값(참조의 정보)이 반환됨
	SelfRef& Adder(int n) {
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber() {
		cout << num << endl;
		return *this; //이것도 *this를 반환해서 main의 맨 아래처럼 이어갈 수 없는 것!
		// ShowTwoNumber().Adder(15)부분!
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