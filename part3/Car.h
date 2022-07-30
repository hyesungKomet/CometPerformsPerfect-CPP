// 3-2 Class & Object
// 3-2-1

// <Class�� Struct�� ������>
//    Ŭ������ Car run99 = {"run99", 100, 0};ó�� ���� �Ұ�
//    ��������� ����Լ��� ����Ʈ �������� �����ڰ� private�̱� ����
//    --> �������� �������� default���� Class�� private, Struct�� public�̴�

// ����Լ��� ���Ǹ� Ŭ���� �ۿ��� �ص� Ŭ���� �Ϻ��̱⿡ Ŭ���� ���� private ���� ���� ����
// why??? �� ���� �����ϰ� ��?? --> ��������, ���Ἲ ����!!!

// <�������>
// ��ü: main�� run99�� "��ü"�̴� (�����ƴ� - ����ü�� Ŭ������ ������ ���ݸ� ���ϴ°� �ƴ�!!)
// �������: Ŭ���� ���� ����� ����
// ����Լ�: Ŭ���� ���� ���ǵ� �Լ�

// <���Ϻ���>
// �������) Ŭ������ ����(declaration)
//    Ŭ���� ���� ������ ���� ��µ� �ʿ��� �ּ����� ���� / �������� Ʋ
// ex)
// int main(void){
//   Car run99;
//   run99.fuelGauge = 100; // fuelGauge�� private���� ������� Ȯ���Ͽ� ���� �߻�
//   run99.Accel(20); // Accel�� �Ű������� void������ ������� Ȯ���Ͽ� ���� �߻�
//        
// �ҽ�����) Ŭ������ ����(definition)
//   ������ ���Ŀ� ��Ŀ�� ���� �ϳ��� �������Ϸ� ����

// �ζ��� �Լ��� ������Ͽ� �Բ� �־�� ��!
// �ζ��� �Լ�: ������ �������� �Լ��� ȣ�� ���� �ִ� ���� �Լ��� ��ü �κ��� ���ԵǾ�� ��!
// ������ ���� -> �������!!!
// ���� ������� ���� �ҽ����Ͽ��� �ζ����Լ��� �����ϸ� �����Ϸ��� ��������� ���⿡ �̸� ������ �� ����!!

// ��������� �ߺ����� ���� �ذ��� ���� ��ũ�� ����
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
class Car { // Struct���� Class��! �ȿ��� �������� ������(�������� ���̺�) ����
private:
  char gamerID[CAR_CONST::ID_LEN];
  int fuelGauge;
  int curSpeed;
  // ����ü �ȿ� ���� �Ű��������� �͵鿡 ���������� ��������
  // -> �Ű����� �ʿ�X

  // ����ü ������ {����Ǿ� �ִ� ���� ����, ���ǵǾ� �ִ� �Լ� ����}
  // �� ���� ��������!
public:
  void InitMembers(const char* ID, int fuel);
  void ShowCarState();
  void Accel();
  void Break();
};

// �ζ��� �Լ��� ������Ͽ� ����!
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