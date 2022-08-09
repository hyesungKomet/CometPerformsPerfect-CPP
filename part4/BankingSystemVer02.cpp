/*
	Banking System Ver 0.2
	by Komet
	내용: Account 클래스 정의, 객체 포인터 배열 적용*/

#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

void ShowMenu(void);
void CreateAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum { CREATE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT }; //순서대로 1~5


class Account {
private:
	int accountID;
	char* name;
	int balance;

public:
	// constructor
	Account(int ID, char* name, int money)
	: accountID(ID), balance(money){
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	int GetAccountID() {
		return accountID;
	}
	void Deposit(int money) {
		balance += money;
	}
	int Withdraw(int money) {
		if (balance < money) {
			return 0;
		}
		balance -= money;
		return money;
	}
	void ShowAccInfo() {
		cout << "Account ID: " << accountID << endl;
		cout << "Customer Name: " << name << endl;
		cout << "Remainder: " << balance << endl;
	}
	~Account() { //소멸자로 힙에 할당된 name 메모리에서 소멸
		delete[]name;
	}

};

Account *accArr[100]; //Account 저장위한 배열
int clientNum = 0;

int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cout << "SELECT MENU: ";
		cin >> choice;

		switch (choice) {
		case CREATE:
			CreateAccount();
			break;

		case DEPOSIT:
			DepositMoney();
			break;

		case WITHDRAW:
			WithdrawMoney();
			break;

		case INQUIRE:
			ShowAllAccInfo();
			break;

		case EXIT:
			return 0;

		default:
			cout << "SELECT PROPER OPTION" << endl;
		}


	}
	return 0;
}

void ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. Create Account" << endl;
	cout << "2. Deposit Money" << endl;
	cout << "3. Withdraw Money" << endl;
	cout << "4. Show All Account Info" << endl;
	cout << "5. Quit\n\n" << endl;
}

void CreateAccount(void) {
	int accID;
	int money;
	char name[20];

	cout << "[Create Account]" << endl;
	cout << "Account ID: ";
	cin >> accID;
	cout << "Name: ";
	cin >> name;
	cout << "Input Money: ";
	cin >> money;
	// 인덱스 내에서 바로 ++붙이는거 좋은듯..?
	accArr[clientNum++] = new Account(accID, name, money);
}

void DepositMoney(void) {
	int accID, money;
	cout << "[Deposit Money]" << endl;
	cout << "Account ID: ";
	cin >> accID;
	cout << "Deposit: ";
	cin >> money;

	for (int i = 0; i <= clientNum; i++) {
		if (accArr[i]->GetAccountID() == accID) {
			accArr[i]->Deposit(money);
			cout << "Deposit Successful" << endl;
			return;
		}
	}
	cout << "ID is Incorrect!" << endl;		
}

void WithdrawMoney(void) {
	int accID, money;
	cout << "[Withdraw Money]" << endl;
	cout << "Account ID: ";
	cin >> accID;
	cout << "Withdraw: ";
	cin >> money;

	for (int i = 0; i <= clientNum; i++) {
		if (accArr[i]->GetAccountID() == accID) {
			if (accArr[i]->Withdraw(money)) {
				cout << "Withdraw Successful" << endl;
			}
			else {
				cout << "Negative Account Balance" << endl;
			}
			return;
		}
	cout << "ID is Incorrect!" << endl;		
	}
}

void ShowAllAccInfo(void) {
	for (int i = 0; i <= clientNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}