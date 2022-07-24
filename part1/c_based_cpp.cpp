#include <iostream> //== <stdio.h>
// namespace: 이름공간 - 함수 등의 이름 충돌 문제를 방지할 수 있다!
// ::는 범위지정 연산자(scope resolution operator)로 이름공간을 지정하는 연산자!
namespace Comet {
	void Who(void) {
		std::cout << "This Is Comet Speaking" << std::endl;
	}
}

namespace Hailey {
	void Who(void) {
		std::cout << "This Is Hailey Speaking" << std::endl;
	}
}
using namespace std;

void swap(int& num1, int& num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void swap(char& ch1, char& ch2) {
	char temp = ch1;
	ch1 = ch2;
	ch2 = temp;
}

void swap(double& db1, double& db2) {
	double temp = db1;
	db1 = db2;
	db2 = temp;
}

//inline function
//c언어에서의 메크로함수: 성능향상에 도움  but 정의가 복잡
// ex) #define SQUARE(x) ((x)*(x))
//c++의 inline함수: 성능향상에 도움 + 일반함수처럼 쉽게 정의 가능!
// 메크로함수의 인라인화는 전처리기로 처리 but inline 함수는 컴파일러로 처리
// 따라서 인라인화가 성능에 오히려 해가 될 경우 컴파일러가 inline 키워드를 무시하기도 함
// but inline함수는 메크로함수에 비해 자료형에 의존하게 돼서 아래 함수의 경우
// x가 실수형이면 데이터 손실 발생(int로 형변환되어...)
inline int SQUARE(int x) {
	return x * x;
}
// -> template으로 극복 가능(see u later...)
template <typename T>
inline T SQUARE2(T x) {
	return x * x;
}

int main(void) {
	//output
	int num = 20;
	cout << "Hello CPP!" << endl;
	cout << num << "is twenty" << endl;

	//input
	int num1, num2;
	cout << "enter num1: ";
	cin >> num1;
	cout << "enter num2: ";
	cin >> num2;

	int result = num1 + num2;

	cout << "num1+num2= " << result<< endl;

	//input in a row
	double num3, num4;
	cout << "Enter two floats: ";
	cin >> num3 >> num4;	//두 수의 경계는 Tab, Space, Enter 다 가능
	cout << "num3: " << num3 << " num4: " << num4 << endl;

	char ch1, ch2;
	cout << "Enter two characters: ";
	cin >> ch1 >> ch2;
	cout << "ch1: " << ch1 << " ch2: " << ch2 << endl;

	//string input
	char name[50];
	char yourName[30];

	cout << "two name: ";
	cin >> name>>yourName;
	cout << "name: " << name << " your name: " << yourName << endl;

	// Function Overloading
	// C에서는 함수명만으로 호출할 함수를 찾았지만 C++에서는 함수명+매개변수의 선언으로 
	// 찾기에 매개변수의 종류나 개수가 다르면 다르게 인식하여 오버로딩이 가능!

	swap(num1, num2);
	swap(ch1, ch2);
	swap(num3, num4);

	cout << num1 << ' ' << num2 << endl;
	cout << ch1 << ' ' << ch2 << endl;
	cout << num3 << ' ' << num4 << endl;
	
	//Default Value in Parameter
	//함수의 매개변수에 디폴트값을 넣을 수 있다
	//단 오른쪽 매개변수부터 채워줘야 함! 오른쪽은 비우고 왼쪽은 디폴트값 넣으면 안된다!
	//ex) void swap(int num1=3, int num2=5); -> swap(1) == swap(1, 5)

	// Inline Function
	cout << SQUARE(5) << endl; //인라인 함수이니 몸체부분이 호출문을 대체함

	// namespace
	Comet::Who();
	Hailey::Who();

	return 0;
}