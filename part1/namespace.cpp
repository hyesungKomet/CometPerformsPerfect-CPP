#include <iostream>
//namespace ��� �Լ��� ����� ���� ����

// ����
namespace Comet {
	void Who(void);
	void Where(void);

	namespace Kim {		// namespace �ȿ� namespace ��ø ����!
		void When(void);
	}
}

namespace Hailey {
	void Who(void);
}

namespace khs = Comet::Kim; // namespace�� ���ϰ� ��ø�� �� ��Ī �� �� �ִ�!

using namespace std; //cout, cin, endl, etc ���� std::�������̵� ��� ����!!

int variable = 9; // global variable

int main(void) {
	using Hailey::Who;

	Comet::Who();
	Hailey::Who();
	Who(); //using���� �̸����� Hailey�� ���ǵ� �͵��� ȣ���� ���� �̸����� ���� �������̵� ����!
	khs::When();

	// ���������� �������� �̸��� ������ �� ���������� �����ϴ� ���: ::varName
	int variable = 20; // local variable
	variable += 3; // 20+3
	::variable += 3; // 9+3
	
	cout << "local variable: " << variable << endl;
	cout << "global variable: " << ::variable << endl;

	return 0;
}

// ����
void Comet::Who(void) {
	std::cout << "This Is Comet Speaking" << std::endl;
	Where(); //���� namespace���� �Լ��� ������ ���� namespace���� ����ȣ�� ����
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