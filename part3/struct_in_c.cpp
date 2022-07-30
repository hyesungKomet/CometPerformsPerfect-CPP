// 3-1 C++에서의 구조체
// 3-1-1
#include <iostream>

#define ID_LEN  20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP  10
#define BRK_STEP  10

using namespace std;

// 구조체 선언
struct Car {
  char gamerID[ID_LEN];
  int fuelGauge;
  int curSpeed;
};

// 구조체에 종속되는 함수들
void ShowCarState(const Car& car) {
  cout << "gamer ID: " << car.gamerID << endl;
  cout << "fuel gauge: " << car.fuelGauge << endl;
  cout << "current speed: " << car.curSpeed << endl << endl;
}

void Accel(Car& car) {
  if (car.fuelGauge <= 0) {
    return;
  }
  else {
    car.fuelGauge -= FUEL_STEP;
  }
  if (car.curSpeed + ACC_STEP >= MAX_SPD) {
    car.curSpeed = MAX_SPD;
    return;
  }
  car.curSpeed += ACC_STEP;
}

void Break(Car& car) {
  if (car.curSpeed < BRK_STEP) {
    car.curSpeed = 0;
    return;
  }
  car.curSpeed -= BRK_STEP;
}

int main(void) {
  Car run99 = { "run99", 100, 0 };
  Accel(run99);
  Accel(run99);
  ShowCarState(run99);
  Break(run99);
  ShowCarState(run99);
  
  Car sped77 = { "sped77", 100, 0 };
  Accel(sped77);
  Break(sped77);
  ShowCarState(sped77);
  
  return 0;
}