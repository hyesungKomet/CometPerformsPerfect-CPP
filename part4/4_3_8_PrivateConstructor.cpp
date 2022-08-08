#include <iostream>
using namespace std;

// 4-3-8

// Default Constructor
// 객체가 되기 위해선 메모리 공간 할당 후 생성자의 호출이 반드시 되어야 함!
// 따라서 생성자가 정의되지 않은 클래스에는 디폴트 클래스가 컴파일러에 의해 자동 삽입됨!
// 생성자가 하나라도 있으면 디폴트 생성자는 생성되지 X
// ex)
//class ABC {
//private:
//	int num;
//public:
//	ABC() { } --> 이게 자동으로 들어감!
//  ABC(int n): num(n) {} --> 이렇게 생성자를 만들어놓으면 디폴트 생성자는 생기지X
//	int getNum{
//		return num;
//	}
//};
// 만약 ABC k;로 객체 넣으면 에러 발생!(생성자 불일치)
// 만든 생성자는 인수 하나를 가져야 함. 그렇다고 디폴트 생성자는 또 없음(이미 생성자를 만들어서)

// Private Constructor
// 객체의 생성 방법을 제한하고자 하는 경우 사용됨
// 아래 코드는 힙 영역에 생성된 객체를 참조의 형태로 반환함
// "힙에 할당된 메모리 공간은 변수로 간주하여, 참조자를 통한 참조가 가능하다"(앞 단원 참고)

class AAA {
private:
	int num;

public:
	AAA() : num(0) {}
	AAA& CreateInitObj(int n) const {
		AAA* ptr = new AAA(n);
		return *ptr;
	}
	void ShowNum() const {
		cout << num << endl;
	}
private:
	AAA(int n) :num(n) {}
};

int main(void) {
	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	delete& obj1;
	return 0;
}