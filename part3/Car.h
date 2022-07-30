// 3-2 Class & Object
// 3-2-1

// <Class와 Struct의 차이점>
//    클래스는 Car run99 = {"run99", 100, 0};처럼 선언 불가
//    멤버변수나 멤버함수의 디폴트 접근제어 지시자가 private이기 때문
//    --> 접근제어 지시자의 default값이 Class는 private, Struct는 public이다

// 멤버함수의 정의를 클래스 밖에서 해도 클래스 일부이기에 클래스 내의 private 변수 접근 가능
// why??? 왜 접근 불편하게 해?? --> 정보은닉, 무결성 보장!!!

// <용어정리>
// 객체: main의 run99는 "객체"이다 (변수아님 - 구조체와 클래스는 변수의 성격만 지니는게 아님!!)
// 멤버변수: 클래스 내에 선언된 변수
// 멤버함수: 클래스 내에 정의된 함수

// <파일분할>
// 헤더파일) 클래스의 선언(declaration)
//    클래스 관련 문장의 오류 잡는데 필요한 최소한의 정보 / 외형적인 틀
// ex)
// int main(void){
//   Car run99;
//   run99.fuelGauge = 100; // fuelGauge가 private임을 헤더에서 확인하여 에러 발생
//   run99.Accel(20); // Accel의 매개변수가 void형임을 헤더에서 확인하여 에러 발생
//        
// 소스파일) 클래스의 정의(definition)
//   컴파일 이후에 링커에 의해 하나의 실행파일로 묶임

// 인라인 함수는 헤더파일에 함께 넣어야 함!
// 인라인 함수: 컴파일 과정에서 함수의 호출 문이 있는 곳에 함수의 몸체 부분이 삽입되어야 함!
// 컴파일 과정 -> 헤더파일!!!
// 만약 헤더파일 말고 소스파일에만 인라인함수로 정의하면 컴파일러는 헤더파일을 보기에 이를 참조할 수 읎다!!

// 헤더파일의 중복포함 문제 해결을 위한 매크로 선언
#ifndef __CAR_H__
#define __CAR_H__

namespace CAR_CONST {
  enum {
    ID_LEN = 20,
    MAX_SPD = 200,
    FUEL_STEP = 2,
    ACC_STEP = 10,
    BRK_STEP = 10
  };
}
class Car { // Struct말고 Class로! 안에는 접근제어 지시자(접근제어 레이블) 있음
private:
  char gamerID[CAR_CONST::ID_LEN];
  int fuelGauge;
  int curSpeed;
  // 구조체 안에 들어가서 매개변수였던 것들에 직접접근이 가능해짐
  // -> 매개변수 필요X

  // 구조체 내에는 {선언되어 있는 변수 정보, 정의되어 있는 함수 정보}
  // 만 눈에 들어오도록!
public:
  void InitMembers(const char* ID, int fuel);
  void ShowCarState();
  void Accel();
  void Break();
};

// 인라인 함수라 헤더파일에 포함!
inline void Car::Accel() {
  if (fuelGauge <= 0) {
    return;
  }
  else {
    fuelGauge -= CAR_CONST::FUEL_STEP;
  }
  if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
    curSpeed = CAR_CONST::MAX_SPD;
    return;
  }
  curSpeed += CAR_CONST::ACC_STEP;
}
#endif