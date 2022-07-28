#include <iostream>

using namespace std;

// 2-1 c review

// 1. meaning of const
const int num = 10;					//���� num�� ���ȭ
int val1 = 5, val2 = 10, val3 = 15;	
const int* ptr1 = &val1;		// ������ ptr1�� ����Ű�� val1�� �ּ��� ���� �ٲ� �� X
int* const ptr2 = &val2;		// ������ ptr2�� ����Ű�� �ּ��� ���� �ٲ� �� O but �ּҰ��� �ٲ� �� X
const int* const ptr3 = &val3;	// ������ ptr3�� ����Ű�� �ּҿ� �� �ּҿ� �ش��ϴ� �� ��� �ٲ� �� X

// 2. memory of running program
// ������: ���������� ����Ǵ� ����- ���α׷� ������ �� �Ҵ�, ������ �� �޸𸮿��� �Ҹ�
// ����: ��������, �Ű����� ����Ǵ� ����(�Լ� ȣ�� ������ ������� ������) - compile �ÿ� ũ�� ����
// ��: �Լ� ������ ��� ���� - runtime�� ũ�� ����(���α׷��Ӱ� �Ҵ�)
//		malloc �Լ�ȣ�⿡ ���� �޸� �Ҵ�, free�� ���ؼ� �Ҹ��ؾ� ��

// 3. Call-by-value vs. Call-by-reference
// void swap(int num1, int num2)�� �ϸ� �ȹٲ�
// void swap(int* ptr1, int* ptr2) �Ǵ� void swap(int& ptr1, int& ptr2)�� �ؾ� �ٲ�

bool IsPositive(int num) {
	if (num < 0)
		return false;
	else
		return true;
}

// Call-by-value
void SwapValue(int num1, int num2) {
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

// Call-by-reference ���� C using �ּ�:
void SwapRefC(int* ptr1, int* ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

// Call-by-reference using ������
void SwapRefCpp(int& ref1, int& ref2) { // �������� ����� ���ÿ� ������ �����ؾ� ��!
	// �Ű������� ������ ��� �ʱ�ȭ�� �ȵ� �� �ƴ϶� �Լ�ȣ�� �� ���޵Ǵ� ������ �ʱ�ȭ�ϰڴٴ� ��
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

// ���� 3 - main�Լ��� ptr1, ptr2�� ���� num1, num2�� ����ų ��
// SwapPointer(ptr1, ptr2)�� ȣ���ϸ� ptr1, ptr2�� ����Ű�� ��� �ٲ�� ��������
void SwapPointer(int* (&fptr1), int* (&fptr2)) {
	int* temp = fptr1;
	fptr1 = fptr2;
	fptr2 = temp;
}

// ������ �̿� �� ���� & �ذ���
	// C������ �Լ��� ȣ�⹮�常 ���� �����;����� ������X���� �ȴ�
	// but C++������ �𸥴� �Լ� �Ű�����, ��ü Ȯ�� �ʿ�
	// -> void SwapInLocal(const int &ref){...}�� ���� ���ο��� 
	// ������ ref�� �̿��ؼ� ���� �ȹٲ۴ٸ� const�� �����ؼ� ��ü �� �Ⱥ��� �ǵ��� �Ѵ�!

	// ��ȯ���� �������� ���
int& RefRetFuncOne(int& ref) {
	ref++;
	return ref;
}

int RefRetFuncTwo(int& ref) {
	ref++;
	return ref;
}

// �߸��� ������ ��ȯ
int& ReturnRefWrong(int n) {
	int num = 20;
	num += n;
	return num;
}	// int &ref = ReturnRefWrong(10);ó�� �ۼ��� ��쿡 ���� �߻�
	// ref�� num�� �����ϴµ� num�� ���������� ���� �Ҹ��;;
int main(void) {

	// 2-2 bool
	cout << "true: " << true << endl;
	cout << "false: " << false << endl;
	cout << "size of 1: " << sizeof(1) << endl;
	cout << "size of 0: " << sizeof(0) << endl;
	cout << "size of true: " << sizeof(true) << endl;
	cout << "size of false: " << sizeof(false) << endl;
	// -> true==1, false==0�� �ƴϴ�! ��, ������ ǥ���ϱ� ���� 1����Ʈ ũ���� �������̴�
	// ���, ������ ����ȯ ���� ��� 1, 0���� ��ȯ�Ǵ� ��.

	bool isPos;
	int num;
	cout << "Input Number: ";
	cin >> num;
	isPos = IsPositive(num);
	if (isPos)
		cout << "Positive Number" << endl;
	else
		cout << "Negative Number" << endl;

	// 2-3 Reference - " ������ ������ �ٿ��ִ� ���Դϴ�."
	int num1 = 2010;	// 2010���� �ʱ�ȭ�� �޸� ������ �̸��� num1�� ��

	int& num2 = num1;	// 2010���� �ʱ�ȭ�� �޸� ������ num2��� �̸��� �߰���
	int *ptr1 = &num1;
	// <&�� �� ���� ���>
	// & : �̹� ����� ���� �տ� ���� �ּҰ� ��ȯ
	// & : ���� ����Ǵ� ���� �տ� ���� ������ ����

	int& num3 = num2; // �����ڸ� ������� ������ ���� ����!

	// �����ڴ� ������ ���ؼ��� ���� ����, ����� ���ÿ� ���� �����ؾ� ��!
	// int &ref = 20;
	// int &ref;
	// int &ref; -> NULL - �ʱ�ȭ X

	num2 = 9999;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	cout << "num1 address: " << &num1 << endl;
	cout << "num2 address: " << &num2 << endl;

	// �迭��� ���� ����
	int arr[3] = { 1,2,3 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	cout << "\nref1: " << ref1 << "\nref2: " << ref2 << "\nref3: " << ref3 << endl;

	// ������ ���� ���� ����
	int num4 = 40;
	int* ptr2 = &num4;
	int** dptr = &ptr2;

	int& ref4 = num4;
	int* (&pref) = ptr2;	//int*������ ������ ������ ���� �� �� ���ذ� �ߵȴ�!
	int** (&dpref) = dptr;

	cout << "\nref4: " << ref4 << "\npref: " << *pref << "\ndpref: " << **dpref<<endl;

	// 2-4 Reference & Function
	// Call-by-value: ���� ���ڷ� �����ϴ� �Լ��� ȣ����
	// Call-by-reference: �ּ� ���� ���ڷ� �����ϴ� �Լ��� ȣ����
	int refnum1 = 10;
	int refnum2 = 20;
	cout << "\nrefnum1: " << refnum1 << "\nrefnum2: " << refnum2 << endl;
	SwapValue(refnum1, refnum2); // ���������� �Լ�ȣ�� ���� �� ������� �ٲ���X
	SwapRefCpp(refnum1, refnum2); // ref1�� refnum1�� ������, ref2�� refnum2�� ������ �ȴ�!
	// ���� refnum1, refnum2�� ������ ������ �ǹ�
	cout << "\nrefnum1: " << refnum1 << "\nrefnum2: " << refnum2 << endl;

	int num5 = 5;
	int num6 = 10;
	int* rptr1 = &num5;
	int *rptr2 = &num6;
	SwapPointer(rptr1, rptr2);
	cout << "\n����3\nptr1: " << *rptr1 << "\nptr2: " << *rptr2 << endl;

	// ��ȯ���� �������� �� ��

	// #1. ref, ref_num1, ref_num2�� ��� ���� but ref�� ���������̴� �����
	int ref_num1 = 1;
	int& ref_num2 = RefRetFuncOne(ref_num1); //num1, num2 = 2
	ref_num1++; //num1, num2 = 3
	ref_num2++; //num1, num2 = 4
	cout << "\nref_num1: " << ref_num1 << "\nref_num2: " << ref_num2 << endl;

	// #2. ref, ref_num5�� ����, ref_num6�� �׳� ����, ref�� ���������̴� �����
	int ref_num5 = 1;
	int ref_num6 = RefRetFuncOne(ref_num5); //num5, num6 = 2
	ref_num5++; //num5 = 3, num6 = 2
	ref_num6++; //num5 = 3, num6 = 3
	cout << "\nref_num5: " << ref_num5 << "\nref_num6: " << ref_num6 << endl;

	// #3. �����ڸ� ��ȯ������ ��ȯ���� int���� �����ڰ� �����ϴ� ���� ���� ��ȯ��
	int ref_num3 = 1;
	int ref_num4 = RefRetFuncTwo(ref_num3); //num3, num4 = 2
	ref_num3++; //num3=3, num4=2
	ref_num4++; //num3=3, num4=3
	cout << "\nref_num3: " << ref_num3 << "\nref_num4: " << ref_num4 << endl;

	// �������� ��� ����
	const int number = 20;
	const int& refer = number; // int& refer = number�� ������ �����Ͽ��� �߻�(������� �����ؼ� ������ �� ���)
	const int& refer2 = 50; // const �����ڴ� ����� ���� ����
	// HOW?? -> ����� ������ �� �ӽú����� ����� �ű⿡ ����� �����Ͽ� �����ڰ� �����ϰԲ� �Ѵ�
	// -> int Adder(const int& num1, const int& num2){return num1+num2}���� �Լ���
	//���� ���� ������ �ʰ� Adder(5, 10)���� �Լ�ȣ���� ����������!

	

	
	return 0;
}