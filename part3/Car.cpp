// 3-2 Class & Object
// 3-2-2

#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(const char* ID, int fuel) {
  strcpy_s(gamerID, ID);
  fuelGauge = fuel;
  curSpeed = 0;
}

void Car::ShowCarState() {

  cout << "gamer ID: " << gamerID << endl;
  cout << "fuel gauge: " << fuelGauge <<"%"<< endl;
  cout << "current speed: " << curSpeed <<"km/s"<< endl << endl;
}

// Accel()은 inline 함수로 처리
/*
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
*/

void Car::Break() {
  if (curSpeed < CAR_CONST::BRK_STEP) {
    curSpeed = 0;
    return;
  }
  curSpeed -= CAR_CONST::BRK_STEP;
}