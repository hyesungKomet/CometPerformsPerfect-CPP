#ifndef __POINT_H_
#define __POINT_H_

// 4-1-1 ��������(Information Hiding)
//
// Point: TopLeft(0,0) ~ BottomRight(100,100)�� ��ǥ
// Rectangle: TopLeft, BottomRight�� ����

// �������� X ���
// x, y�� public�̴� �̸� �ܺο����� ���� ����
// x, y�� ������ �ȸ¾Ƶ�, Rectangle�� �»��, ���ϴ� ��ǥ�� �ٲ�
// ������ ���� ���� �����Ƿ� ���� �ڵ鸵�� ����
// --> �������� �ʿ�!! 
// - ���ѵ� ��������� ���ٸ� ����ؼ� �߸��� �� ������� �ʰ�!
// - �Ǽ����� �� �Ǽ� �߰��� �� �ְ�!
// 
// �����ڰ� �Ǽ��� �� �� ������ �Ǽ��� ���� ��å�� ���� �� ������!!

// Access Function(������ �Լ�): Getter & Setter

class Point {
private:
  int x;
  int y;

public:
  bool InitMembers(int xpos, int ypos);
  int GetX() const;
  int GetY() const;
  bool SetX(int xPos);
  bool SetY(int yPos);

  // const function
  // 1. �� �Լ� �������� ��������� ���� �������� �ʰڴ�!(���� �� ������ ����)
  // 2. const �Լ� �������� const �Լ��� ȣ�� ����!
  //    ������ ���� ������ �������� �׳� �Լ��� ȣ��� ������ ����(�ƿ� ���ɼ��� ��õ ����)
  // 3. �Լ��� const �����ڸ� �Ű������� ���� �� �ش� �������� �Լ��� const �Լ����� �Ѵ�
  // ex)
  // void InitNum(const Point &pos1){
  //    num = pos1.GetX; --> GetX()�� const �Լ��� �ƴϸ� ������ ���� 
};

#endif