#ifndef __POINT_H_
#define __POINT_H_

// 4-1-1 정보은닉(Information Hiding)
//
// Point: TopLeft(0,0) ~ BottomRight(100,100)의 좌표
// Rectangle: TopLeft, BottomRight로 구성

// 정보은닉 X 경우
// x, y가 public이니 이를 외부에서도 접근 가능
// x, y가 범위에 안맞아도, Rectangle의 좌상단, 우하단 좌표가 바뀌어도
// 컴파일 상의 에러 없으므로 에러 핸들링을 못함
// --> 정보은닉 필요!! 
// - 제한된 방법으로의 접근만 허용해서 잘못된 값 저장되지 않게!
// - 실수했을 때 실수 발견할 수 있게!
// 
// 개발자가 실수는 할 수 있지만 실수에 대한 대책이 없는 건 문제다!!

// Access Function(엑세스 함수): Getter & Setter

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
  // 1. 이 함수 내에서는 멤버변수의 값을 변경하지 않겠다!(변경 시 컴파일 에러)
  // 2. const 함수 내에서는 const 함수만 호출 가능!
  //    실제로 값의 변경이 없었더라도 그냥 함수는 호출시 컴파일 에러(아예 가능성을 원천 차단)
  // 3. 함수가 const 참조자를 매개변수로 가질 시 해당 참조자의 함수도 const 함수여야 한다
  // ex)
  // void InitNum(const Point &pos1){
  //    num = pos1.GetX; --> GetX()가 const 함수가 아니면 컴파일 에러 
};

#endif