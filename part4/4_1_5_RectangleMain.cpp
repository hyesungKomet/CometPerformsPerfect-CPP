#include <iostream>
#include "4_1_1_Point.h"
#include "4_1_3_Rectangle.h"
using namespace std;

//4-1-5

int main(void) {
  Point pos1;
  if (!pos1.InitMembers(-2, 4)) {
    cout << "Init Failed" << endl;
  }
  if (!pos1.InitMembers(2, 4)) {
    cout << "Init Failed" << endl;
  }

  Point pos2;
  if (!pos2.InitMembers(5,9)) {
    cout << "Init Failed" << endl;
  }
  
  Rectangle rec;
  if (!rec.InitMembers(pos2, pos1)) {
    cout << "Rectangle Init Failed" << endl;
  }
  if (!rec.InitMembers(pos1, pos2)) {
    cout << "Rectangle Init Failed" << endl;
  }

  rec.ShowRecInfo();
}