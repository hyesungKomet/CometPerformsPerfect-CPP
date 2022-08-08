#include <iostream>
#include "4_3_5_Rectangle.h"
using namespace std;

//4-3-6

// Member Initializer (멤버 이니셜라이저)
// 
// - 이니셜라이저를 통한 객체 초기화
// 객체 topLeft, bottomRight를 생성하는 과정에서 x, y를 인자로 받는 생성자를 호출해라!
// -> 이니셜라이저로 멤버변수(객체) 초기화!

// <객체의 생성과정>
// 1. 메모리 공간의 할당
// 2. 이니셜라이저를 이용한 멤버변수(객체)의 초기화
// 3. 생성자의 몸체부분 실행

// - 이니셜라이저를 통한 멤버변수 초기화
// ex)
/*
class Simple{
private:
    int num1;
    int num2;
public:
    Simple(int n1, int n2): num1(n1){
        num2 = n2;
    }
};
*/
// num1은 이니셜라이저로, num2는 생성자 몸체에서 초기화됨
// **멤버변수는 이니셜라이저로의 초기화가 생성자 몸체 초기화보다 선호됨
// 1. 초기화 대상을 명확히 인식 가능
// 2. 약간의 성능 상의 이점
//    int num1 = n1;    vs      int num2;, num2=n2; 의 느낌
//    (선언과 동시에 초기화의 바이너리 코드를 구성함)
// 
//      선언과 동시에 초기화??? --> const 멤버변수도 이니셜라이저를 사용하면 초기화 가능!!
//      (FruitSalwSim.cpp 참고)

//      선언과 동시에 초기화??? --> 참조자도 멤버변수로 선언, 초기화 가능!(흔하지는 않ㅇ)

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
:topLeft(x1, y1), bottomRight(x2, y2){
    // TL, BR의 좌표가 뒤바뀌진 않았는지 검사
    /*if (topLeft.GetX() > bottomRight.GetX() || topLeft.GetY() > bottomRight.GetY()) {
        return false;
    }
    topLeft = ul;
    bottomRight = br;
    return true;*/
}

void Rectangle::ShowRecInfo() const {
    cout << "Top Left: " << '(' << topLeft.GetX() << ',' << topLeft.GetY() << ')' << endl;
    cout << "Bottom Right: " << '(' << bottomRight.GetX() << ',' << bottomRight.GetY() << ')' << endl;
}