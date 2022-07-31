#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

// ¹®Á¦ 3-1
struct Point {
  int xpos;
  int ypos;
  void MovePos(int x, int y);
  void AddPoint(const Point& pos);
  void ShowPosition();
};

void Point::MovePos(int x, int y) {
  xpos += x;
  ypos += y;
}

void Point::AddPoint(const Point& pos) {
  xpos += pos.xpos;
  ypos += pos.ypos;
}

void Point::ShowPosition() {
  cout << "[" << xpos << ", " << ypos << "]" << endl;
}

// ¹®Á¦ 3-2-1
class Calculator {
private:
  int count[4];

public:
  void Init();
  double Add(double num1, double num2);
  double Min(double num1, double num2);
  double Mul(double num1, double num2);
  double Div(double num1, double num2);
  void ShowOpCount();
};

void Calculator::Init() {
  for (int i = 0; i < 4; i++) {
    count[i] = 0;
  }
}
double Calculator::Add(double num1, double num2) {
  count[0] += 1;
  return num1 + num2;
}
double Calculator::Min(double num1, double num2) {
  count[1] += 1;
  return num1 - num2;
}
double Calculator::Mul(double num1, double num2) {
  count[2] += 1;
  return num1 * num2;
}
double Calculator::Div(double num1, double num2) {
  if (num2 == 0)
    return 99999;
  count[3] += 1;
  return num1 / num2;
}
void Calculator::ShowOpCount() {
  cout << "µ¡¼À: " << count[0] << " »¬¼À: " << count[1] << " °ö¼À: " << count[2] << " ³ª´°¼À: " << count[3] << endl;
}

// 3-2-2
class Printer {
private:
  //char chptr[20];
  char* chptr = new char;
  
public:
  void SetString(const char* ptr);
  void ShowString();
};

void Printer::SetString(const char* ptr) {
  strcpy(chptr, ptr);
}
void Printer::ShowString() {
  cout << chptr << endl;
}

int main(void) {
  // 3-1
  Point pos1 = { 12, 4 };
  Point pos2 = { 20, 30 };

  pos1.MovePos(-7, 10);
  pos1.ShowPosition();

  pos1.AddPoint(pos2);
  pos1.ShowPosition();

  // 3-2-1
  Calculator cal;
  cal.Init();
  cout << "4.8 + 5.2 = " << cal.Add(4.8, 5.2) << endl;
  cout << "4.8 - 5.2 = " << cal.Min(4.8, 5.2) << endl;
  cout << "1.2 x 1.2 = " << cal.Mul(1.2, 1.2) << endl;
  cout << "6.5 / 0.3 = " << cal.Div(6.5, 0.3) << endl;
  cal.ShowOpCount();

  // 3-2-2
  Printer pnt;
  pnt.SetString("Hello There!");
  pnt.ShowString();

  pnt.SetString("I'm Hailey's Comet!");
  pnt.ShowString();
  return 0;
}