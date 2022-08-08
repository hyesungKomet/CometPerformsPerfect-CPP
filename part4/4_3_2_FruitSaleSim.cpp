#include <iostream>
using namespace std;

// 4-3-2
// Part3 messagePassing에 Constructor 추가
class FruitSeller {
private:
    const int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    // const int인 APPLE_PRICE는 이니셜라이저로만 초기화 가능!(물론 다른 것들도 이니셜라이저로 하면 더 좋다)
    FruitSeller(int price, int num, int money)
    :APPLE_PRICE(price){
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
    FruitBuyer(int money) {
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

    FruitSeller seller(1000, 20, 0);
    //FruitSeller *seller = new FruitSeller; // 동적 할당방식
    //seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer(5000);
    //buyer.InitMembers(5000);

    cout << "Before Fruit Seller Status" << endl;
    seller.ShowSalesResult();
    cout << endl << "Before Fruit Buyer Status" << endl;
    buyer.ShowByResult();
    cout << endl << "------------------------------------------" << endl;

    buyer.BuyApples(seller, 2000); // 객체 간의 관계 형성 모먼트!

    cout << endl << "After Fruit Seller Status" << endl;
    seller.ShowSalesResult();
    cout << endl << "After Fruit Buyer Status" << endl;
    buyer.ShowByResult();

    return 0;
}