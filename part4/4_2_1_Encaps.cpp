#include <iostream>
using namespace std;

// 4-2-1 Encapsulation(ĸ��ȭ)

// ���� �๰, ��ä��, �ڸ����� ĸ���� ���ε��� �������� �ִٸ�
// �� �� ���� ���ε��� �����ؾ� ��
// "�ڰ���� �׻� �๰, ��ä��, �ڸ����� �����Ѵ�"
// "ĸ���� �๰, ��ä��, �ڸ��� ������ �����ؾ߸� �Ѵ�"
// �� ���� ������ �򸮸� ������ ���� �߻�Ȯ�� ��������
// --> �� ��ɵ��� �� �� ���� ĸ��ȭ �ʿ�!!

// Information Hiding�� ���� Encapsulation�� ��ƴ�
// ĸ��ȭ�� ���α׷� ����, Ư���� ���� ��������� �޶�����
// ex) �񰨱�, ���차��, �ڰ���� ĸ��ȭ �ؾߵǳ�...?

// Encapsulation���� Information Hiding�� ���ݵ�
// �̿� ���ҰŸ� �����ϰ� ���ξ���

class SinivelCap {
public:
  void Take() const {
    cout << "�๰ óġ�� ĸ�� ������..." << endl;
  }
};

class SneezeCap {
public:
  void Take() const {
    cout << "��ä�� óġ�� ĸ�� ������..." << endl;
  }
};

class SnuffleCap {
public:
  void Take() const {
    cout << "�ڸ��� óġ�� ĸ�� ������..." << endl;
  }
};

class CONTAC600 {
  // �ܺο��� ���� ���ϰ� �ϰ�
  // ���������� �� ĸ���� ���� ������ ���߾���
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