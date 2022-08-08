#include <iostream>
using namespace std;

// 4-3-2
// Part3 messagePassing�� Constructor �߰�
class FruitSeller {
private:
    const int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    // const int�� APPLE_PRICE�� �̴ϼȶ������θ� �ʱ�ȭ ����!(���� �ٸ� �͵鵵 �̴ϼȶ������� �ϸ� �� ����)
    FruitSeller(int price, int num, int money)
    :APPLE_PRICE(price){
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
    FruitBuyer(int money) {
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

    FruitSeller seller(1000, 20, 0);
    //FruitSeller *seller = new FruitSeller; // ���� �Ҵ���
    //seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer(5000);
    //buyer.InitMembers(5000);

    cout << "Before Fruit Seller Status" << endl;
    seller.ShowSalesResult();
    cout << endl << "Before Fruit Buyer Status" << endl;
    buyer.ShowByResult();
    cout << endl << "------------------------------------------" << endl;

    buyer.BuyApples(seller, 2000); // ��ü ���� ���� ���� ���Ʈ!

    cout << endl << "After Fruit Seller Status" << endl;
    seller.ShowSalesResult();
    cout << endl << "After Fruit Buyer Status" << endl;
    buyer.ShowByResult();

    return 0;
}