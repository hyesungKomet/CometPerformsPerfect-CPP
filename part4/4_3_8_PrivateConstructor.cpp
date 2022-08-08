#include <iostream>
using namespace std;

// 4-3-8

// Default Constructor
// ��ü�� �Ǳ� ���ؼ� �޸� ���� �Ҵ� �� �������� ȣ���� �ݵ�� �Ǿ�� ��!
// ���� �����ڰ� ���ǵ��� ���� Ŭ�������� ����Ʈ Ŭ������ �����Ϸ��� ���� �ڵ� ���Ե�!
// �����ڰ� �ϳ��� ������ ����Ʈ �����ڴ� �������� X
// ex)
//class ABC {
//private:
//	int num;
//public:
//	ABC() { } --> �̰� �ڵ����� ��!
//  ABC(int n): num(n) {} --> �̷��� �����ڸ� ���������� ����Ʈ �����ڴ� ������X
//	int getNum{
//		return num;
//	}
//};
// ���� ABC k;�� ��ü ������ ���� �߻�!(������ ����ġ)
// ���� �����ڴ� �μ� �ϳ��� ������ ��. �׷��ٰ� ����Ʈ �����ڴ� �� ����(�̹� �����ڸ� ����)

// Private Constructor
// ��ü�� ���� ����� �����ϰ��� �ϴ� ��� ����
// �Ʒ� �ڵ�� �� ������ ������ ��ü�� ������ ���·� ��ȯ��
// "���� �Ҵ�� �޸� ������ ������ �����Ͽ�, �����ڸ� ���� ������ �����ϴ�"(�� �ܿ� ����)

class AAA {
private:
	int num;

public:
	AAA() : num(0) {}
	AAA& CreateInitObj(int n) const {
		AAA* ptr = new AAA(n);
		return *ptr;
	}
	void ShowNum() const {
		cout << num << endl;
	}
private:
	AAA(int n) :num(n) {}
};

int main(void) {
	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3);
	obj1.ShowNum();

	delete& obj1;
	return 0;
}