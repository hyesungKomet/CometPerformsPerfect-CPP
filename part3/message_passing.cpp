// 3-3 Understanding of Object-Oriented Programming(OOP)

// 객체지향 프로그래밍: 현실에 존재하는 사물과 대상, 그에 따른 행동을 그대로 실체화시키는 형태의 프로그래밍
// 객체: 하나 이상의 상태 정보(데이터) + 하나 이상의 행동(기능)
// 상태 정보 by 변수 & 행동 by 함수

// 멤버변수의 상수화에 대하여...(여기선 불가능!)
// FruitSeller의 APPLE_PRICE
// 판매가격은 일정 -> 상수로 가정
// 가정 1.
// const int APPLE_PRICE = 1000;
// -> 선언문에서 초기화는 허용X
// 가정 2.
// InitMembers 안에서
// const int APPLE_PRICE;
// -> const 상수는 선언과 동시에 초기화되어야 하기 때문에 허용X
// **********
// -----> constructor(생성자)에서 다룰 것!!!
// **********


// Class 기반의 객체생성 방법
//    1. ClassName objName; -> 일반 변수 선언방식
//    2. ClassName *ptrObj = new ClassName; -> 동적 할당방식(힙 할당방식)
// --> 기본 자료형 변수의 선언방식과 동일!!!

// Message Passing(객체간의 대화 방법)
// 하나의 객체가 다른 하나의 객체에게 메세지를 전달하는 방법 - 함수호출 기반!!
// 이 함수호출이 Message Passing!


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
    int num = money / APPLE_PRICE; // 받은 돈 만큼의 사과 개수
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
  // Class에서는 접근제어 지시자의 디폴트값이 private이므로
  // 이 두 멤버변수는 private이다!
  int myMoney;
  int numOfApples;

public:
  void InitMembers(int money) {
    myMoney = money;
    numOfApples = 0;
  }
  void BuyApples(FruitSeller& seller, int money) {// Message Passing - FruitSeller와 소통!
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
  //FruitSeller *seller = new FruitSeller; // 동적 할당방식
  seller.InitMembers(1000, 20, 0);
  FruitBuyer buyer;
  buyer.InitMembers(5000);

  cout << "Before Fruit Seller Status" << endl;
  seller.ShowSalesResult();
  cout << endl << "Before Fruit Buyer Status" << endl;
  buyer.ShowByResult();
  cout << endl << "------------------------------------------" << endl;

  buyer.BuyApples(seller, 2000); // 객체 간의 관계 형성 모먼트!

  cout << endl << "After Fruit Seller Status" << endl;
  seller.ShowSalesResult();
  cout << endl<< "After Fruit Buyer Status" << endl;
  buyer.ShowByResult();

  return 0;
}