#include <iostream>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

// 2-5 malloc & free -> new & delete
// before(C) -> malloc & free
//		단점: 바이트 크기단위로만 전달 가능 / 반환형이 void형 포인터이기에 적절한 형변환 필요...
// after(C++) -> new & delete - 위의 단점 해결!!

// malloc과 new의 동작방식이 다르다! 정도만 알고 넘어가기(클래스, 객체 때 다시...)

// 길이 인자 받아서 그만큼의 배열 생성 후 그 주소 값 반환
char* MakeStrAdr(int len) {
	char* str = (char*)malloc(sizeof(char) * len); // 배열 힙 영역에 할당
	return str;
}

char* MakeStrAdrCpp(int len) {
	char* str = new char[len];
	return str;
}

// 2-6 C++에서 C언어 표준함수 호출하기
//		"c를 더하고 .h를 빼라"
// #include <stdio.h> -> <cstdio>
// #include <math.h> -> <cmath>
// ... etc
// 다 namespace std에 선언되어 있다!!


int main(void) {
	// 2-5
	char* str = MakeStrAdr(30);
	strcpy(str, "I am so happy cuz of Hailey");
	cout << str << endl;
	free(str);	// 힙에 할당한 메모리 공간 소멸

	char* str2 = MakeStrAdrCpp(20);
	strcpy(str2, "I had a best day!");
	cout << str2 << endl;
	delete[]str2;

	// 포인터 없이 참조자로만 힙에 할당된 변수에 접근 가능
	int* ptr = new int;
	int& ref = *ptr;
	ref = 20;
	cout << *ptr << endl;

	// 2-6


	return 0;
}