#include <iostream>

using namespace std;

class TaxPayer
{
	TaxPayer() = delete;
	TaxPayer(const TaxPayer&) = delete;
	TaxPayer& operator=(const TaxPayer&) = delete;

public:
	TaxPayer(const char* name, const int iconome)
		: mIconome(iconome)
	{
		int len = strlen(name);
		strcpy_s(mName, len + 1, name);
	}
	virtual ~TaxPayer() = default;

public:
	virtual void CalculateTax() = 0;

protected:
	int GetIconome()const { return mIconome; }

private:
	char mName[100];
	int mIconome;
};

class Employee : public TaxPayer
{
	Employee() = delete;
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;

public:
	Employee(const char* name, const int iconome)
		: TaxPayer(name, iconome)
	{
	}
	~Employee() = default;

public:
	void CalculateTax()override
	{
		cout << "Employee Tax: " << GetIconome() * 0.3 << endl;
	}
};

class Freelancer : public TaxPayer
{
	Freelancer() = delete;
	Freelancer(const Freelancer&) = delete;
	Freelancer& operator=(const Freelancer&) = delete;

public:
	Freelancer(const char* name, const int iconome)
		: TaxPayer(name, iconome)
	{
	}
	virtual ~Freelancer() = default;

public:
	void CalculateTax()override
	{
		cout << "Freelancer Tax: " << GetIconome() * 0.1 << endl;
	}
};

int main(void)
{
	Employee emp("Kim", 5000); Freelancer fr("Lee", 3000);
	TaxPayer* people[] = { &emp, &fr };
	for (int i = 0; i < 2; ++i)
		people[i]->CalculateTax();


	return 0;
}