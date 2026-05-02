#include <iostream>

using namespace std;

class PaymentMethod
{
	PaymentMethod(const PaymentMethod&) = delete;
	PaymentMethod& operator=(const PaymentMethod&) = delete;

public:
	PaymentMethod() = default;
	virtual ~PaymentMethod() = default;

public:
	virtual void Pay(int amount) = 0;
};

class CreditCard : public PaymentMethod
{
	CreditCard() = delete;
	CreditCard(const CreditCard&) = delete;
	CreditCard& operator=(const CreditCard&) = delete;

public:
	CreditCard(const char* name, const char* num)
	{
		int len = strlen(name);
		strcpy_s(mName, len + 1, name);

		len = strlen(num);
		strcpy_s(mNum, len + 1, num);
	}
	~CreditCard() = default;

public:
	void Pay(int amount)override
	{
		cout << "CreditCard: 10000$Paid" << endl;
	}

private:
	char mName[100];
	char mNum[100];
};

class PayPal : public PaymentMethod
{
	PayPal() = delete;
	PayPal(const PayPal&) = delete;
	PayPal& operator=(const PayPal&) = delete;

public:
	PayPal(const char* email)
	{
		int len = strlen(email);
		strcpy_s(mEmail, len + 1, email);
	}
	virtual ~PayPal() = default;

public:
	void Pay(int amount)override
	{
		cout << "PayPal: 10000$Paid" << endl;
	}

private:
	char mEmail[100];
};

int main(void)
{
	CreditCard cc("Kim", "1234"); PayPal pp("lee@mail.com");
	PaymentMethod* pay[] = { &cc, &pp };
	for (int i = 0; i < 2; ++i)
		pay[i]->Pay(10000);


	return 0;
}