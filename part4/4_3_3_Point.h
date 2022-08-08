#ifndef __POINT_H_
#define __POINT_H_

// Part3 adding Constructor
class Point {
private:
	int x;
	int y;

public:
	Point(const int &xpos, const int &ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xPos);
	bool SetY(int yPos);

};

#endif