#include <iostream> //== <stdio.h>
// namespace: �̸����� - �Լ� ���� �̸� �浹 ������ ������ �� �ִ�!
// ::�� �������� ������(scope resolution operator)�� �̸������� �����ϴ� ������!
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
//c������ ��ũ���Լ�: ������� ����  but ���ǰ� ����
// ex) #define SQUARE(x) ((x)*(x))
//c++�� inline�Լ�: ������� ���� + �Ϲ��Լ�ó�� ���� ���� ����!
// ��ũ���Լ��� �ζ���ȭ�� ��ó����� ó�� but inline �Լ��� �����Ϸ��� ó��
// ���� �ζ���ȭ�� ���ɿ� ������ �ذ� �� ��� �����Ϸ��� inline Ű���带 �����ϱ⵵ ��
// but inline�Լ��� ��ũ���Լ��� ���� �ڷ����� �����ϰ� �ż� �Ʒ� �Լ��� ���
// x�� �Ǽ����̸� ������ �ս� �߻�(int�� ����ȯ�Ǿ�...)
inline int SQUARE(int x) {
	return x * x;
}
// -> template���� �غ� ����(see u later...)
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
	cin >> num3 >> num4;	//�� ���� ���� Tab, Space, Enter �� ����
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
	// C������ �Լ������� ȣ���� �Լ��� ã������ C++������ �Լ���+�Ű������� �������� 
	// ã�⿡ �Ű������� ������ ������ �ٸ��� �ٸ��� �ν��Ͽ� �����ε��� ����!

	swap(num1, num2);
	swap(ch1, ch2);
	swap(num3, num4);

	cout << num1 << ' ' << num2 << endl;
	cout << ch1 << ' ' << ch2 << endl;
	cout << num3 << ' ' << num4 << endl;
	
	//Default Value in Parameter
	//�Լ��� �Ű������� ����Ʈ���� ���� �� �ִ�
	//�� ������ �Ű��������� ä����� ��! �������� ���� ������ ����Ʈ�� ������ �ȵȴ�!
	//ex) void swap(int num1=3, int num2=5); -> swap(1) == swap(1, 5)

	// Inline Function
	cout << SQUARE(5) << endl; //�ζ��� �Լ��̴� ��ü�κ��� ȣ�⹮�� ��ü��

	// namespace
	Comet::Who();
	Hailey::Who();

	return 0;
}