#include <iostream>
#include "4_1_3_Rectangle.h"
using namespace std;

//4-1-4

bool Rectangle::InitMembers(const Point& ul, const Point& br) {
  // TL, BR�� ��ǥ�� �ڹٲ��� �ʾҴ��� �˻�
  if (ul.GetX() > br.GetX() || ul.GetY() > br.GetY()) {
    return false;
  }
  topLeft = ul;
  bottomRight = br;
  return true;
}

void Rectangle::ShowRecInfo() const{
  cout << "Top Left: " << '(' << topLeft.GetX() << ',' << topLeft.GetY() << ')'<<endl;
  cout << "Bottom Right: " << '(' << bottomRight.GetX() << ',' << bottomRight.GetY() << ')' << endl;
}