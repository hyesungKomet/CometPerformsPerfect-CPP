#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_
#include "4_3_3_Point.h";

//4-1-3

class Rectangle {
private:
	Point topLeft;
	Point bottomRight;

public:
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	void ShowRecInfo() const;
};

#endif