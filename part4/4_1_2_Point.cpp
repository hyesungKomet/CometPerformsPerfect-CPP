#include <iostream>>
#include "4_1_1_Point.h"
using namespace std;

// 4-1-2

bool Point::InitMembers(int xPos, int yPos) {
  if (xPos < 0 || yPos < 0) {
    return false;
  }
  x = xPos;
  y = yPos;
  return true;
}

int Point::GetX()const {
  return x;
}

int Point::GetY() const {
  return y;
}

bool Point::SetX(int xPos) {
  if (xPos < 0 || xPos>100) {
    return false;
  }
  x = xPos;
  return true;
}

bool Point::SetY(int yPos) {
  if (yPos < 0 || yPos>100) {
    return false;
  }
  y = yPos;
  return true;
}