#include <iostream>
using namespace std;

// 4-3-1 Constructor & Destructor
// 이전엔 InitMembers라는 함수 호출해서 private인 멤버변수를 초기화했다
// "생성자"선에서 정리 가능ㅋ
// - 클래스의 이름과 동일한 함수 이름
// - 반환형 선언X, 반환하지 않음
// - 객체 생성시 딱 한번 호출
// - 생성자도 함수니 오버로딩, 매개변수의 디폴트 값 설정 가능
// - 생성자에서 함수 호출해서 초기화하기도 함
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
	// SimpleClass sc1(); 로는 선언하면 안됨! 뒤에 나오는
	// void sc1()라는 함수의 원형 선언과 객체생성문 중 무엇인지 알 수 없게 됨!
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
