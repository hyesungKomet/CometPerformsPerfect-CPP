#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_
#include "4_1_1_Point.h";

//4-1-3

class Rectangle {
private:
  Point topLeft;
  Point bottomRight;

public:
  bool InitMembers(const Point& tl, const Point& br);
  void ShowRecInfo() const;
};

#endif