#include <iostream>

using namespace std;

class BankAccount
{
	BankAccount(const BankAccount&) = delete;
	BankAccount& operator=(const BankAccount&) = delete;

	struct BNKLog
	{
		char act[256];
		int actAmount;
		int CrrtAmount;
	};

public:
	BankAccount()
		: mBank{}
		, mAccount{}
		, mType{}
		, mBalance(0)
		, mLog{}
		, mLogIdx(0)
	{
		mLog[0] = { "", 0, 0 };
	}
	BankAccount(const char* bank, const char* account, const char* type
		, const int balance = 0)
		: mBank{}
		, mAccount{}
		, mType{}
		, mBalance(balance)
		, mLog{}
		, mLogIdx(0)
	{
		int len = strlen(bank);
		strncpy_s(mBank, len + 1, bank, len);

		len = strlen(account);
		strncpy_s(mAccount, len + 1, account, len);

		len = strlen(type);
		strncpy_s(mType, len + 1, type, len);

		mLog[0] = { "", 0, balance };
	}
	~BankAccount() = default;

public:
	void			SetBank(const char* bank)
	{
		if (strlen(mBank))
			memset(mBank, 0, sizeof(mBank));
		int len = strlen(bank);
		strncpy_s(mBank, len + 1, bank, len);
	}
	void			SetAccount(const char* account)
	{
		if (strlen(mAccount))
			memset(mAccount, 0, sizeof(mAccount));
		int len = strlen(account);
		strncpy_s(mAccount, len + 1, account, len);
	}
	void			SetType(const char* type)
	{
		if (strlen(mType))
			memset(mType, 0, sizeof(mType));
		int len = strlen(type);
		strncpy_s(mType, len + 1, type, len);
	}
	void			SetBalance(const int balance)
	{
		mBalance = balance;
		mLog[0] = { "", 0, balance };
	}

public:
	const char* GetBank()const { return mBank; }
	const char* GetAccount()const { return mAccount; }
	const char* GetType()const { return mType; }
	const int		GetBalance()const { return mBalance; }

public:
	void			Deposit(const int dpsAmount)
	{
		mBalance += dpsAmount;

		++mLogIdx;
		mLog[mLogIdx] = { "Deposit", dpsAmount, mBalance };
	}
	void			PrintAccountInfo()const
	{
		cout << "Account: " << mAccount << " | ";
		cout << "Bank: " << mBank << " | ";
		cout << "Type: " << mType << endl;

		cout << "Balance: " << "$" << mLog[0].CrrtAmount << " -> ";
		for (int i = 1; i <= mLogIdx; ++i)
		{
			cout << mLog[i].act << " " << "$" << mLog[i].actAmount << " -> ";
			cout << "Balance: " << "$" << mLog[i].CrrtAmount << endl;
		}
	}
private:
	char	mBank[256];
	char	mAccount[256];
	char	mType[256];
	int		mBalance;
	BNKLog	mLog[30];
	int		mLogIdx;
};

class Customer
{
	Customer() = delete;
	Customer(const Customer&) = delete;
	Customer& operator=(const Customer&) = delete;
public:
	Customer(const char* name, const char* phone,
		const char* adress, const int age)
		: mName{}
		, mPhone{}
		, mAdress{}
		, mAge(age)
		, mBankAccount()
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		len = strlen(phone);
		strncpy_s(mPhone, len + 1, phone, len);

		len = strlen(adress);
		strncpy_s(mAdress, len + 1, adress, len);
	}
	~Customer() = default;

public:
	void			SetName(const char* name)
	{
		if (strlen(mName))
			memset(mName, 0, sizeof(mName));
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);
	}

	void			SetPhone(const char* phone)
	{
		if (strlen(mPhone))
			memset(mPhone, 0, sizeof(mPhone));
		int len = strlen(phone);
		strncpy_s(mPhone, len + 1, phone, len);
	}

	void			SetAdress(const char* adress)
	{
		if (strlen(mAdress))
			memset(mAdress, 0, sizeof(mAdress));
		int len = strlen(adress);
		strncpy_s(mAdress, len + 1, adress, len);
	}

	void			SetAge(const int age) { mAge = age; }

public:
	const char* GetName()const { return mName; }
	const char* GetPhone()const { return mPhone; }
	const char* GetAdress()const { return mAdress; }
	const int		GetAge()const { return mAge; }

public:
	void			CreateBankAccount_Ver_Default()
	{
		cout << "Setting Defulat.." << endl;

		SetBankName("Hana");
		SetBankAccount("123-456");
		SetBankType("Saving");
		SetBankBalance(1500);
	}

	void			CreateBankAccount()
	{
		char str[256];

		cout << "Input Bank Name: ";
		cin >> str;
		SetBankName(str);

		cout << "Input Bank Account: ";
		cin >> str;
		SetBankAccount(str);

		cout << "Input Account Type: ";
		cin >> str;
		SetBankType(str);

		int n;
		cout << "Input Balance: ";
		cin >> n;
		SetBankBalance(n);
	}

	void			Deposit()
	{
		int dpsAmount;
		cout << "Input withdrawal amount: ";
		cin >> dpsAmount;

		mBankAccount.Deposit(dpsAmount);
	}

	void			PrintAccountInfo()const
	{
		cout << "Customer: " << mName << " | ";
		cout << "Phone: " << mPhone << " | ";
		cout << "Age: " << mAge << endl;
		mBankAccount.PrintAccountInfo();
	}

private:
	void			SetBankName(const char* bankName) { mBankAccount.SetBank(bankName); }
	void			SetBankAccount(const char* account) { mBankAccount.SetAccount(account); }
	void			SetBankType(const char* type) { mBankAccount.SetType(type); }
	void			SetBankBalance(const int balance) { mBankAccount.SetBalance(balance); }

private:
	char			mName[256];
	char			mPhone[256];
	char			mAdress[256];
	int				mAge;
	BankAccount		mBankAccount;
};

int main()
{
	Customer alice("Alice", "010-1234-5678", "Seoul", 27);
	alice.CreateBankAccount_Ver_Default();
	alice.Deposit();
	alice.PrintAccountInfo();

	return 0;
}