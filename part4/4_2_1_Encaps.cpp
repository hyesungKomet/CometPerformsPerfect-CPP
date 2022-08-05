#include <iostream>
using namespace std;

// 4-2-1 Encapsulation(캡슐화)

// 만약 콧물, 재채기, 코막힘용 캡슐이 따로따로 나누어져 있다면
// 총 세 개를 따로따로 복용해야 함
// "코감기는 항상 콧물, 재채기, 코막힘을 동반한다"
// "캡슐은 콧물, 재채기, 코막힘 순서로 복용해야만 한다"
// 와 같은 가정이 깔리면 더더욱 문제 발생확률 높아진다
// --> 저 기능들을 한 데 묶는 캡슐화 필요!!

// Information Hiding은 쉽고 Encapsulation은 어렵다
// 캡슐화는 프로그램 성격, 특성에 따라 적용범위가 달라진다
// ex) 목감기, 몸살감기, 코감기는 캡슐화 해야되나...?

// Encapsulation에는 Information Hiding이 동반됨
// 이왕 감쌀거면 안전하게 감싸야지

class SinivelCap {
public:
  void Take() const {
    cout << "콧물 처치용 캡슐 복용중..." << endl;
  }
};

class SneezeCap {
public:
  void Take() const {
    cout << "재채기 처치용 캡슐 복용중..." << endl;
  }
};

class SnuffleCap {
public:
  void Take() const {
    cout << "코막힘 처치용 캡슐 복용중..." << endl;
  }
};

class CONTAC600 {
  // 외부에서 접근 못하게 하고
  // 내부적으로 각 캡슐의 복용 순서를 맞추었다
private:
  SinivelCap snv;
  SneezeCap snz;
  SnuffleCap snf;

public:
  void Take() const {
    snv.Take();
    snz.Take();
    snf.Take();
  }
};

class ColdPatient {
public:
  void TakeCONTAC(CONTAC600& cap) const{
    cap.Take();
  }
};

int main(void) {
  CONTAC600 cap;
  ColdPatient patient;
  patient.TakeCONTAC(cap);
  return 0;
}