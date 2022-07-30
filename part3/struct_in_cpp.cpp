// 3-1 C++������ ����ü
// 3-1-2

#include <iostream>


using namespace std;

// 
// ����ü ����
// struct_in_c������ ������
// 1. Car ����ü�� �������� �Լ����� �����Լ��� ���¸� ��⿡ ���������� 
//    ��Ÿ���� ���� - �ٸ� ������ �� �Լ����� ȣ��� ���ɼ�
// --> ����ü �ȿ� �Լ� ����(C++������ �̸� ���)
// 
// 2. ��ũ�� ����� ���� Car ����ü���� �ǹ��ִ� ������̴�
// --> ����ü ���� ������ enum���� �����Ѵ�
// or namespace�� ������� ���Ǵ� ������ ����Ѵ�!

// 3. �Լ��� ���� �� ���Ǹ� �� ����ü�� ���ųִٺ��� �������� ������
// --> �Լ��� ���� ����ü ������, ���Ǵ� �ܺη� ����!

// 4. ����ü �ȿ� �Լ��� ���ǵǾ� ������ "�Լ��� �ζ������� ó��" �� ������
//    but �Լ� ���Ǹ� ��ó�� ������ ���� �ζ��� ó�� �ȵ� - inline Ű����� ����ؾ� ��

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
  // ����ü �ȿ� ���� �Ű��������� �͵鿡 ���������� ��������
  // -> �Ű����� �ʿ�X

  // ����ü ������ {����Ǿ� �ִ� ���� ����, ���ǵǾ� �ִ� �Լ� ����}
  // �� ���� ��������!
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

// ����ü�� ���ӵǴ� �Լ���


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