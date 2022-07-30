// 3-1 C++에서의 구조체
// 3-1-2

#include <iostream>


using namespace std;

// 
// 구조체 선언
// struct_in_c에서의 문제점
// 1. Car 구조체에 종속적인 함수들이 전역함수의 형태를 띄기에 종속적임이 
//    나타나지 않음 - 다른 곳에서 이 함수들이 호출될 가능성
// --> 구조체 안에 함수 삽입(C++에서는 이를 허용)
// 
// 2. 메크로 상수들 역시 Car 구조체에만 의미있는 상수들이다
// --> 구조체 내에 열거형 enum으로 정의한다
// or namespace로 상수들이 사용되는 영역을 명시한다!

// 3. 함수의 선언 및 정의를 다 구조체에 쑤셔넣다보니 가독성이 나빠짐
// --> 함수의 선언만 구조체 내에서, 정의는 외부로 뺀다!

// 4. 구조체 안에 함수가 정의되어 있으면 "함수를 인라인으로 처리" 가 내포됨
//    but 함수 정의를 이처럼 밖으로 빼면 인라인 처리 안됨 - inline 키워드로 명시해야 함

namespace CAR_CONST {
  enum {
    ID_LEN = 20,
    MAX_SPD = 200,
    FUEL_STEP = 2,
    ACC_STEP = 10,
    BRK_STEP = 10
  };
}
struct Car {
  /*
  enum {
    ID_LEN = 20,
    MAX_SPD = 200,
    FUEL_STEP = 2,
    ACC_STEP = 10,
    BRK_STEP = 10
  };
  */
  char gamerID[CAR_CONST::ID_LEN];
  int fuelGauge;
  int curSpeed;
  // 구조체 안에 들어가서 매개변수였던 것들에 직접접근이 가능해짐
  // -> 매개변수 필요X

  // 구조체 내에는 {선언되어 있는 변수 정보, 정의되어 있는 함수 정보}
  // 만 눈에 들어오도록!
  void ShowCarState();
  void Accel();
  void Break();
};

void Car::ShowCarState() {

  cout << "gamer ID: " << gamerID << endl;
  cout << "fuel gauge: " << fuelGauge << endl;
  cout << "current speed: " << curSpeed << endl << endl;
}

void Car::Accel() {
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

void Car::Break() {
  if (curSpeed < CAR_CONST::BRK_STEP) {
    curSpeed = 0;
    return;
  }
  curSpeed -= CAR_CONST::BRK_STEP;
}

// 구조체에 종속되는 함수들


int main(void) {
  Car run99 = { "run99", 100, 0 };
  run99.Accel();
  run99.Accel();
  run99.ShowCarState();
  run99.Break();
  run99.ShowCarState();

  Car sped77 = { "sped77", 100, 0 };
  sped77.Accel();
  sped77.Break();
  sped77.ShowCarState();

  return 0;
}