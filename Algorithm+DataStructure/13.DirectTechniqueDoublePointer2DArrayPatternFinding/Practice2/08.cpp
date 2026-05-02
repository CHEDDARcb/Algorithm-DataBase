#include <iostream>

using namespace std;

class Account
{
public:
	Account()
		: mName(nullptr)
		, mAccNum(0)
		, mBalance(0)
	{
	}
	Account(const char* _name, const int _accNum, const int _balance)
		: mName(nullptr)
		, mAccNum(_accNum)
		, mBalance(_balance)
	{
		int len = strlen(_name);
		mName = new char[len + 1];
		strncpy_s(mName, len + 1, _name, len);
	}
	Account(const Account& _acc)
		: mName(nullptr)
		, mAccNum(_acc.mAccNum)
		, mBalance(_acc.mBalance)
	{
		int len = strlen(_acc.mName);
		mName = new char[len + 1];
		strncpy_s(mName, len + 1, _acc.mName, len);
	}
	Account& operator=(const Account& _acc)
	{
		if (mName != nullptr) delete[] mName;
		int len = strlen(_acc.mName);
		mName = new char[len + 1];
		strncpy_s(mName, len + 1, _acc.mName, len);

		mAccNum = _acc.mAccNum;
		mBalance = _acc.mBalance;
	}
	~Account()
	{
		delete[] mName;
	}

public:
	const char* getOwner()const { return mName; }
	const int inquiry()const { return mBalance; }

public:
	void deposit(const int _deposit) { mBalance += _deposit; }
	int withdraw(const int _withdraw)
	{
		if (_withdraw > mBalance)
			return 0;
		mBalance -= _withdraw;

		return mBalance;
	}


private:
	char* mName;
	int mAccNum;
	int mBalance;
};

int main()
{
	Account a("kitae", 1, 5000);

	a.deposit(50000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;

	return 0;
}