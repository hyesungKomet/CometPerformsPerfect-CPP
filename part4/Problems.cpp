#include <iostream>
#pragma warning(disable:4996)
using namespace std;

// 문제 4-2 & 4-3 (1)
class Point {
private:
  int xpos, ypos;
public:
  Point(int x, int y) {
    xpos = x;
    ypos = y;
  }
  void ShowPointInfo() const {
    cout << "(" << xpos << ", " << ypos << ")" << endl;
  }
  
};

class Circle {
private:
  Point center;
  int radius;
public:
  Circle(int xPos,int yPos, int rad)
    :center(xPos, yPos), radius(rad) {}

  void ShowCircleInfo() {
    cout << "Center Point: ";
    center.ShowPointInfo();
    cout << "Radius: " << radius << endl;
  }
};

class Ring {
private:
  Circle innerC;
  Circle outC;
  
public:
  Ring(int x1, int y1, int x2, int y2, int inR, int outR)
    :innerC(x1, y1,inR), outC(x2, y2,outR) {}
  void ShowingInfo() {
    //intNoutCheck();
    cout << "Inner Circle Info..." << endl;
    innerC.ShowCircleInfo();
    cout << endl << "Outter Circle Info..." << endl;
    outC.ShowCircleInfo();

  }
private:
  /*void intNoutCheck() {
    if (innerC.GetRadius() >outC.GetRadius()) {
      int x1 = innerC.GetX();
      int y1 = innerC.GetY();
      int tempR = innerC.GetRadius;
      innerC.SetCenter(outC.GetX(), outC.GetY());
      outPoint.Init(x1, y1);
      inRadius = outRadius;
      outRadius = tempR;
    }*/
  
};
// main 지움ㅋ
//int main(void) {
//  Ring ring(1, 1, 4, 2, 2, 9);
//  ring.ShowingInfo();
//  return 0;
//}

// 문제 4-3 (2)

namespace COMP_POS {
  enum { CLERK, SENIOR, ASSIST, MANAGER };

  void ShowPositionInfo(int pos){
    switch (pos) {
    case CLERK:
      cout << "Clerk(사원)" << endl;
      break;
    case SENIOR:
      cout << "Senior(주임)" << endl;
      break;
    case ASSIST:
      cout << "Assist(대리)" << endl;
    case MANAGER:
      cout << "Manager(과장)" << endl;
    }
  }
}
class NameCard {
private:
  char* name;
  char* company;
  char* call;
  int position;
public:
  NameCard(const char* mingzi, const char* group, const char* num, int pos)
    :position(pos) {
    this->name = new char[strlen(mingzi) + 1];
    strcpy(name, mingzi);
    company = new char[strlen(group) + 1];
    strcpy(company, group);
    call = new char[strlen(num) + 1];
    strcpy(call, num);
  }
  void ShowNameCardInfo() {
    cout << "Name: " << name << endl;
    cout << "Company: " << company << endl;
    cout << "Call Number: " << call << endl;
    cout << "Position: ";
    COMP_POS::ShowPositionInfo(position);
    cout << endl;
  }

  ~NameCard() {
    delete[]name;
    delete[]company;
    delete[]call;
  }
};

int main(void) {
  NameCard manClerk("Jjun", "ROKAF", "010-1234-5678", COMP_POS::CLERK);
  NameCard womanSenior("Hailey", "TIMES", "010-1357-2468", COMP_POS::SENIOR);
  NameCard beautiManager("Komet", "CometFund", "no phone", COMP_POS::MANAGER);

  manClerk.ShowNameCardInfo();
  womanSenior.ShowNameCardInfo();
  beautiManager.ShowNameCardInfo();
}
