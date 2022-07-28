#include <iostream>

using namespace std;

// 2-1 문제 3 - main함수의 ptr1, ptr2이 각각 num1, num2를 가르킬 때
// SwapPointer(ptr1, ptr2)로 호출하면 ptr1, ptr2가 가르키는 대상 바뀌도록 정의하자
void SwapPointer(int* (&fptr1), int* (&fptr2)) {
	int* temp = fptr1;
	fptr1 = fptr2;
	fptr2 = temp;
}

// 2-3
typedef struct __Point {
	int xPos;
	int yPos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	Point *sum = new Point;
	sum->xPos = p1.xPos + p2.xPos;
	sum->yPos = p1.yPos + p2.yPos;
	return *sum;
}

int main(void) {
	// 2-1
	int num5 = 5;
	int num6 = 10;
	int* rptr1 = &num5;
	int* rptr2 = &num6;
	SwapPointer(rptr1, rptr2);
	cout << "\n문제3\nptr1: " << *rptr1 << "\nptr2: " << *rptr2 << endl;

	// 2-2
	const int num = 12;
	const int* ptr = &num;
	const int*& ref = ptr;

	cout << *ptr << endl;
	cout << *ref << endl;

	// 2-3
	Point *p1 = new Point;
	Point* p2 = new Point;
	p1->xPos = 2;
	p1->yPos = 3;
	p2->xPos = 4;
	p2->yPos = 5;
	Point& pref= PntAdder(*p1, *p2);
	
	cout << pref.xPos << ", " << pref.yPos << endl;
	delete p1;
	delete p2;
	delete& pref;

	return 0;
}