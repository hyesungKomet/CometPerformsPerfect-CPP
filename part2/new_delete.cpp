#include <iostream>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

// 2-5 malloc & free -> new & delete
// before(C) -> malloc & free
//		����: ����Ʈ ũ������θ� ���� ���� / ��ȯ���� void�� �������̱⿡ ������ ����ȯ �ʿ�...
// after(C++) -> new & delete - ���� ���� �ذ�!!

// malloc�� new�� ���۹���� �ٸ���! ������ �˰� �Ѿ��(Ŭ����, ��ü �� �ٽ�...)

// ���� ���� �޾Ƽ� �׸�ŭ�� �迭 ���� �� �� �ּ� �� ��ȯ
char* MakeStrAdr(int len) {
	char* str = (char*)malloc(sizeof(char) * len); // �迭 �� ������ �Ҵ�
	return str;
}

char* MakeStrAdrCpp(int len) {
	char* str = new char[len];
	return str;
}

// 2-6 C++���� C��� ǥ���Լ� ȣ���ϱ�
//		"c�� ���ϰ� .h�� ����"
// #include <stdio.h> -> <cstdio>
// #include <math.h> -> <cmath>
// ... etc
// �� namespace std�� ����Ǿ� �ִ�!!


int main(void) {
	// 2-5
	char* str = MakeStrAdr(30);
	strcpy(str, "I am so happy cuz of Hailey");
	cout << str << endl;
	free(str);	// ���� �Ҵ��� �޸� ���� �Ҹ�

	char* str2 = MakeStrAdrCpp(20);
	strcpy(str2, "I had a best day!");
	cout << str2 << endl;
	delete[]str2;

	// ������ ���� �����ڷθ� ���� �Ҵ�� ������ ���� ����
	int* ptr = new int;
	int& ref = *ptr;
	ref = 20;
	cout << *ptr << endl;

	// 2-6


	return 0;
}