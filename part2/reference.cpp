#include <iostream>

using namespace std;

// 2-1 c review

// 1. meaning of const
const int num = 10;					//변수 num을 상수화
int val1 = 5, val2 = 10, val3 = 15;	
const int* ptr1 = &val1;		// 포인터 ptr1이 가르키는 val1의 주소의 값을 바꿀 수 X
int* const ptr2 = &val2;		// 포인터 ptr2이 가르키는 주소의 값은 바꿀 수 O but 주소값을 바꿀 순 X
const int* const ptr3 = &val3;	// 포인터 ptr3이 가르키는 주소와 그 주소에 해당하는 값 모두 바꿀 수 X

// 2. memory of running program
// 데이터: 전역변수가 저장되는 영역- 프로그램 시작할 때 할당, 종료할 때 메모리에서 소멸
// 스택: 지역변수, 매개변수 저장되는 영역(함수 호출 끝나면 사라지는 변수들) - compile 시에 크기 결정
// 힙: 함수 끝나도 계속 유지 - runtime에 크기 결정(프로그래머가 할당)
//		malloc 함수호출에 의해 메모리 할당, free를 통해서 소멸해야 함

// 3. Call-by-value vs. Call-by-reference
// void swap(int num1, int num2)로 하면 안바뀜
// void swap(int* ptr1, int* ptr2) 또는 void swap(int& ptr1, int& ptr2)로 해야 바뀜

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

// Call-by-reference 기존 C using 주소:
void SwapRefC(int* ptr1, int* ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

// Call-by-reference using 참조자
void SwapRefCpp(int& ref1, int& ref2) { // 참조나는 선언과 동시에 변수를 참조해야 함!
	// 매개변수로 들어오는 경우 초기화가 안된 게 아니라 함수호출 시 전달되는 인지로 초기화하겠다는 뜻
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

// 문제 3 - main함수의 ptr1, ptr2이 각각 num1, num2를 가르킬 때
// SwapPointer(ptr1, ptr2)로 호출하면 ptr1, ptr2가 가르키는 대상 바뀌도록 정의하자
void SwapPointer(int* (&fptr1), int* (&fptr2)) {
	int* temp = fptr1;
	fptr1 = fptr2;
	fptr2 = temp;
}

// 참조자 이용 시 단점 & 해결방안
	// C에서는 함수의 호출문장만 봐도 포인터없으면 값변경X임을 안다
	// but C++에서는 모른다 함수 매개변수, 몸체 확인 필요
	// -> void SwapInLocal(const int &ref){...}와 같이 내부에서 
	// 참조자 ref를 이용해서 값을 안바꾼다면 const로 선언해서 몸체 다 안봐도 되도록 한다!

	// 반환형이 참조형인 경우
int& RefRetFuncOne(int& ref) {
	ref++;
	return ref;
}

int RefRetFuncTwo(int& ref) {
	ref++;
	return ref;
}

// 잘못된 참조의 반환
int& ReturnRefWrong(int n) {
	int num = 20;
	num += n;
	return num;
}	// int &ref = ReturnRefWrong(10);처럼 작성할 경우에 문제 발생
	// ref는 num을 참조하는데 num은 지역변수라 정작 소멸됨;;
int main(void) {

	// 2-2 bool
	cout << "true: " << true << endl;
	cout << "false: " << false << endl;
	cout << "size of 1: " << sizeof(1) << endl;
	cout << "size of 0: " << sizeof(0) << endl;
	cout << "size of true: " << sizeof(true) << endl;
	cout << "size of false: " << sizeof(false) << endl;
	// -> true==1, false==0이 아니다! 참, 거짓을 표현하기 위한 1바이트 크기의 데이터이다
	// 출력, 정수로 형변환 등의 경우 1, 0으로 변환되는 것.

	bool isPos;
	int num;
	cout << "Input Number: ";
	cin >> num;
	isPos = IsPositive(num);
	if (isPos)
		cout << "Positive Number" << endl;
	else
		cout << "Negative Number" << endl;

	// 2-3 Reference - " 변수에 별명을 붙여주는 것입니다."
	int num1 = 2010;	// 2010으로 초기화된 메모리 공간의 이름이 num1이 됨

	int& num2 = num1;	// 2010으로 초기화된 메모리 공간에 num2라는 이름이 추가됨
	int *ptr1 = &num1;
	// <&의 두 가지 기능>
	// & : 이미 선언된 변수 앞에 오면 주소값 반환
	// & : 새로 선언되는 변수 앞에 오면 참조자 선언

	int& num3 = num2; // 참조자를 대상으로 참조자 선언도 가능!

	// 참조자는 변수에 대해서만 선언 가능, 선언과 동시에 변수 참조해야 함!
	// int &ref = 20;
	// int &ref;
	// int &ref; -> NULL - 초기화 X

	num2 = 9999;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	cout << "num1 address: " << &num1 << endl;
	cout << "num2 address: " << &num2 << endl;

	// 배열요소 참조 가능
	int arr[3] = { 1,2,3 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	cout << "\nref1: " << ref1 << "\nref2: " << ref2 << "\nref3: " << ref3 << endl;

	// 포인터 변수 참조 가능
	int num4 = 40;
	int* ptr2 = &num4;
	int** dptr = &ptr2;

	int& ref4 = num4;
	int* (&pref) = ptr2;	//int*까지를 데이터 형으로 보면 좀 더 이해가 잘된다!
	int** (&dpref) = dptr;

	cout << "\nref4: " << ref4 << "\npref: " << *pref << "\ndpref: " << **dpref<<endl;

	// 2-4 Reference & Function
	// Call-by-value: 값을 인자로 전달하는 함수의 호출방식
	// Call-by-reference: 주소 값을 인자로 전달하는 함수의 호출방식
	int refnum1 = 10;
	int refnum2 = 20;
	cout << "\nrefnum1: " << refnum1 << "\nrefnum2: " << refnum2 << endl;
	SwapValue(refnum1, refnum2); // 지역변수는 함수호출 끝난 후 사라져서 바뀌지X
	SwapRefCpp(refnum1, refnum2); // ref1은 refnum1의 별명이, ref2는 refnum2의 별명이 된다!
	// 실제 refnum1, refnum2의 값들의 변경을 의미
	cout << "\nrefnum1: " << refnum1 << "\nrefnum2: " << refnum2 << endl;

	int num5 = 5;
	int num6 = 10;
	int* rptr1 = &num5;
	int *rptr2 = &num6;
	SwapPointer(rptr1, rptr2);
	cout << "\n문제3\nptr1: " << *rptr1 << "\nptr2: " << *rptr2 << endl;

	// 반환형이 참조형일 때 비교

	// #1. ref, ref_num1, ref_num2가 모두 참조 but ref는 지역변수이니 사라짐
	int ref_num1 = 1;
	int& ref_num2 = RefRetFuncOne(ref_num1); //num1, num2 = 2
	ref_num1++; //num1, num2 = 3
	ref_num2++; //num1, num2 = 4
	cout << "\nref_num1: " << ref_num1 << "\nref_num2: " << ref_num2 << endl;

	// #2. ref, ref_num5이 참조, ref_num6은 그냥 정수, ref는 지역변수이니 사라짐
	int ref_num5 = 1;
	int ref_num6 = RefRetFuncOne(ref_num5); //num5, num6 = 2
	ref_num5++; //num5 = 3, num6 = 2
	ref_num6++; //num5 = 3, num6 = 3
	cout << "\nref_num5: " << ref_num5 << "\nref_num6: " << ref_num6 << endl;

	// #3. 참조자를 반환하지만 반환형이 int여서 참조자가 참조하는 변수 값이 반환됨
	int ref_num3 = 1;
	int ref_num4 = RefRetFuncTwo(ref_num3); //num3, num4 = 2
	ref_num3++; //num3=3, num4=2
	ref_num4++; //num3=3, num4=3
	cout << "\nref_num3: " << ref_num3 << "\nref_num4: " << ref_num4 << endl;

	// 참조자의 상수 참조
	const int number = 20;
	const int& refer = number; // int& refer = number로 했으면 컴파일에러 발생(상수값을 참조해서 변경할 수 없어서)
	const int& refer2 = 50; // const 참조자는 상수도 참조 가능
	// HOW?? -> 상수를 참조할 때 임시변수를 만들어 거기에 상수를 저장하여 참조자가 참조하게끔 한다
	// -> int Adder(const int& num1, const int& num2){return num1+num2}같은 함수로
	//변수 둘을 만들지 않고도 Adder(5, 10)으로 함수호출이 가능해진다!

	

	
	return 0;
}