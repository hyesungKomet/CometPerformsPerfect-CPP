#include <iostream>
#include "4_3_5_Rectangle.h"
using namespace std;

//4-3-6

// Member Initializer (��� �̴ϼȶ�����)
// 
// - �̴ϼȶ������� ���� ��ü �ʱ�ȭ
// ��ü topLeft, bottomRight�� �����ϴ� �������� x, y�� ���ڷ� �޴� �����ڸ� ȣ���ض�!
// -> �̴ϼȶ������� �������(��ü) �ʱ�ȭ!

// <��ü�� ��������>
// 1. �޸� ������ �Ҵ�
// 2. �̴ϼȶ������� �̿��� �������(��ü)�� �ʱ�ȭ
// 3. �������� ��ü�κ� ����

// - �̴ϼȶ������� ���� ������� �ʱ�ȭ
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
// num1�� �̴ϼȶ�������, num2�� ������ ��ü���� �ʱ�ȭ��
// **��������� �̴ϼȶ��������� �ʱ�ȭ�� ������ ��ü �ʱ�ȭ���� ��ȣ��
// 1. �ʱ�ȭ ����� ��Ȯ�� �ν� ����
// 2. �ణ�� ���� ���� ����
//    int num1 = n1;    vs      int num2;, num2=n2; �� ����
//    (����� ���ÿ� �ʱ�ȭ�� ���̳ʸ� �ڵ带 ������)
// 
//      ����� ���ÿ� �ʱ�ȭ??? --> const ��������� �̴ϼȶ������� ����ϸ� �ʱ�ȭ ����!!
//      (FruitSalwSim.cpp ����)

//      ����� ���ÿ� �ʱ�ȭ??? --> �����ڵ� ��������� ����, �ʱ�ȭ ����!(�������� �ʤ�)

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
:topLeft(x1, y1), bottomRight(x2, y2){
    // TL, BR�� ��ǥ�� �ڹٲ��� �ʾҴ��� �˻�
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