#include <iostream>

using namespace std;

class Employee
{
	Employee() = delete;
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;
public:
	Employee(const char* name, const int baseSalary, const char* department = nullptr, const int years = 0, const int bonusRate = 0)
		: mName{}
		, mDepartment{}
		, mBaseSalary(baseSalary)
		, mYears(years)
		, mBonusRate(bonusRate)
		, mTotalSalary(0)
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		if (department != nullptr)
			strncpy_s(mDepartment, len + 1, department, len);

		mTotalSalary = mBaseSalary + mBaseSalary * mBonusRate / 100;
	}
	~Employee() = default;

public:
	void			SetDepartment(const char* department)
	{
		if (strlen(mDepartment))
			memset(mDepartment, 0, sizeof(mDepartment));

		int len = strlen(department);
		strncpy_s(mDepartment, len + 1, department, len);
	}
	void			SetYears(const int years) { mYears = years; }
	void			SetBonusRate(const int rate)
	{
		mBonusRate = rate;
		CalcTotalSalary();
	}

public:
	const char* GetName()const { return mName; }
	const char* GetDepartment()const { return mDepartment; }
	const int		GetBaseSalary()const { return mBaseSalary; }
	const int		GetYears()const { return mYears; }
	const int		GetBonusRate()const { return mBonusRate; }
	const int		GetTotalSalary()const { return mTotalSalary; }

public:
	void			PrintEmployeeInfo()const
	{
		cout << "Product: " << mName << " | ";
		cout << "Department: " << mDepartment << " | ";
		cout << "Years: " << mYears << endl;
		cout << "Base: " << mBaseSalary << ", ";
		cout << "Bonus: " << mBonusRate << "%" << endl;
		cout << "Total Salary: " << mTotalSalary << endl;
	}

private:
	void			CalcTotalSalary()
	{
		mTotalSalary = mBaseSalary + mBaseSalary * mBonusRate / 100;
	}

private:
	char		mName[256];
	char		mDepartment[256];
	int			mBaseSalary;
	int			mYears;
	float		mBonusRate;
	int			mTotalSalary;
};

int main()
{
	Employee jane("Jane", 3000);
	jane.SetDepartment("HR");
	jane.SetYears(5);
	jane.SetBonusRate(15);

	jane.PrintEmployeeInfo();

	return 0;
}