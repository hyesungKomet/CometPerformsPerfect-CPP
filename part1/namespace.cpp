#include <iostream>
//namespace 기반 함수의 선언과 정의 구분

// 선언
namespace Comet {
	void Who(void);
	void Where(void);

	namespace Kim {		// namespace 안에 namespace 중첩 가능!
		void When(void);
	}
}

namespace Hailey {
	void Who(void);
}

namespace khs = Comet::Kim; // namespace가 과하게 중첩될 시 별칭 줄 수 있다!

using namespace std; //cout, cin, endl, etc 등을 std::지정없이도 사용 가능!!

int variable = 9; // global variable

int main(void) {
	using Hailey::Who;

	Comet::Who();
	Hailey::Who();
	Who(); //using으로 이름공간 Hailey에 정의된 것들을 호출할 때는 이름공간 따로 지정없이도 가능!
	khs::When();

	// 지역변수와 전역변수 이름이 동일할 때 전역변수에 접근하는 방법: ::varName
	int variable = 20; // local variable
	variable += 3; // 20+3
	::variable += 3; // 9+3
	
	cout << "local variable: " << variable << endl;
	cout << "global variable: " << ::variable << endl;

	return 0;
}

// 정의
void Comet::Who(void) {
	std::cout << "This Is Comet Speaking" << std::endl;
	Where(); //같은 namespace안의 함수나 변수는 따로 namespace안찍어도 직접호출 가능
	Kim::When();
}

void Comet::Where(void) {
	std::cout << "In Osan" << std::endl;
}

void Comet::Kim::When(void) {
	std::cout << "On March 2022" << std::endl;
}

void Hailey::Who(void) {
	std::cout << "This Is Hailey Speaking" << std::endl;
}