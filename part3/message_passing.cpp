// 3-3 Understanding of Object-Oriented Programming(OOP)

// ��ü���� ���α׷���: ���ǿ� �����ϴ� �繰�� ���, �׿� ���� �ൿ�� �״�� ��üȭ��Ű�� ������ ���α׷���
// ��ü: �ϳ� �̻��� ���� ����(������) + �ϳ� �̻��� �ൿ(���)
// ���� ���� by ���� & �ൿ by �Լ�

// ��������� ���ȭ�� ���Ͽ�...(���⼱ �Ұ���!)
// FruitSeller�� APPLE_PRICE
// �ǸŰ����� ���� -> ����� ����
// ���� 1.
// const int APPLE_PRICE = 1000;
// -> ���𹮿��� �ʱ�ȭ�� ���X
// ���� 2.
// InitMembers �ȿ���
// const int APPLE_PRICE;
// -> const ����� ����� ���ÿ� �ʱ�ȭ�Ǿ�� �ϱ� ������ ���X
// **********
// -----> constructor(������)���� �ٷ� ��!!!
// **********


// Class ����� ��ü���� ���
//    1. ClassName objName; -> �Ϲ� ���� ������
//    2. ClassName *ptrObj = new ClassName; -> ���� �Ҵ���(�� �Ҵ���)
// --> �⺻ �ڷ��� ������ �����İ� ����!!!

// Message Passing(��ü���� ��ȭ ���)
// �ϳ��� ��ü�� �ٸ� �ϳ��� ��ü���� �޼����� �����ϴ� ��� - �Լ�ȣ�� ���!!
// �� �Լ�ȣ���� Message Passing!


#include <iostream>
using namespace std;

class FruitSeller {
private:
  int APPLE_PRICE;
  int numOfApples;
  int myMoney;

public:
  void InitMembers(int price, int num, int money) {
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
  }
  int SaleApples(int money) {
    int num = money / APPLE_PRICE; // ���� �� ��ŭ�� ��� ����
    numOfApples -= num;
    myMoney += money;
    return num;
  }
  void ShowSalesResult() {
    cout << "remaining apples: " << numOfApples << endl;
    cout << "earning: " << myMoney << endl;
  }
};

class FruitBuyer {
  // Class������ �������� �������� ����Ʈ���� private�̹Ƿ�
  // �� �� ��������� private�̴�!
  int myMoney;
  int numOfApples;

public:
  void InitMembers(int money) {
    myMoney = money;
    numOfApples = 0;
  }
  void BuyApples(FruitSeller& seller, int money) {// Message Passing - FruitSeller�� ����!
    numOfApples += seller.SaleApples(money);
    myMoney -= money;
  }
  void ShowByResult() {
    cout << "remaining money: " << myMoney << endl;
    cout << "number of apples: " << numOfApples << endl;
  }
};

int main(void) {
  
  FruitSeller seller;
  //FruitSeller *seller = new FruitSeller; // ���� �Ҵ���
  seller.InitMembers(1000, 20, 0);
  FruitBuyer buyer;
  buyer.InitMembers(5000);

  cout << "Before Fruit Seller Status" << endl;
  seller.ShowSalesResult();
  cout << endl << "Before Fruit Buyer Status" << endl;
  buyer.ShowByResult();
  cout << endl << "------------------------------------------" << endl;

  buyer.BuyApples(seller, 2000); // ��ü ���� ���� ���� ���Ʈ!

  cout << endl << "After Fruit Seller Status" << endl;
  seller.ShowSalesResult();
  cout << endl<< "After Fruit Buyer Status" << endl;
  buyer.ShowByResult();

  return 0;
}