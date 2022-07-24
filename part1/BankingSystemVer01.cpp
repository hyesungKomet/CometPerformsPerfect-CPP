/*
	Banking System Ver 0.1
	by Komet
	내용: OOP 단계별 프로젝트의 기본 틀 구성*/

#include <iostream>
#include <cstring>

using namespace std;

void ShowMenu(void);
void CreateAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {CREATE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT}; //순서대로 1~5

typedef struct{
	int accountID;
	char name[20];
	int balance;

}Account;

Account accArr[100]; //Account 저장위한 배열
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

	accArr[clientNum].accountID = accID;
	accArr[clientNum].balance = money;
	strcpy_s(accArr[clientNum].name, name);
	//accArr[clientNum].name = name;


}

void DepositMoney(void) {
	int accID, money;
	cout << "[Deposit Money]" << endl;
	cout << "Account ID: ";
	cin >> accID;
	cout << "Deposit: ";
	cin >> money;

	for (int i = 0; i <= clientNum; i++) {
		if (accArr[i].accountID == accID){
			accArr[i].balance += money;
			cout << "Deposit Successful" << endl;
		}
		else {
			cout << "ID is Incorrect!" << endl;
		}
	}

}

void WithdrawMoney(void) {
	int accID, money;
	cout << "[Withdraw Money]" << endl;
	cout << "Account ID: ";
	cin >> accID;
	cout << "Withdraw: ";
	cin >> money;

	for (int i = 0; i <= clientNum; i++) {
		if (accArr[i].accountID == accID) {
			if(accArr[i].balance>=money){
				accArr[i].balance -= money;
				cout << "Withdraw Successful" << endl;
			}
			else {
				cout << "Negative Account Balance" << endl;
			}
		}
		else {
			cout << "ID is Incorrect!" << endl;
		}
	}
}

void ShowAllAccInfo(void) {
	for (int i = 0; i <= clientNum; i++) {
		cout << "Client Number " << i + 1 << endl;
		cout << "Account ID: " << accArr[i].accountID << endl;
		cout << "Name: " << accArr[i].name << endl;
		cout << "Balance: " << accArr[i].balance << "\n\n"<<endl;
	}
}