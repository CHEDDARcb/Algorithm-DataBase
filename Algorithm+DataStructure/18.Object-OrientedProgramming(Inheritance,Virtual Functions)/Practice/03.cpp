#include <iostream>

using namespace std;

class Employee
{
	Employee() = delete;
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;

public:
	Employee(const char* name, const int salary)
		: mSalary(salary)
	{
		strcpy_s(mName, sizeof(mName), name);
	}
	virtual ~Employee() = default;

public:
	virtual float CalculateSalary()const = 0;

protected:
	int GetBaseSalary()const { return mSalary; }

private:
	char mName[100];
	int mSalary;
};

class Manager : public Employee
{
	Manager() = delete;
	Manager(const Manager&) = delete;
	Manager& operator=(const Manager&) = delete;

public:
	Manager(const char* name, const int salary)
		: Employee(name, salary)
	{
	}
	~Manager() = default;

public:
	float CalculateSalary()const override
	{
		return GetBaseSalary() + (GetBaseSalary() * 0.5);
	}
};

class Developer : public Employee
{
	Developer() = delete;
	Developer(const Developer&) = delete;
	Developer& operator=(const Developer&) = delete;

public:
	Developer(const char* name, const int salary)
		: Employee(name, salary)
	{
	}
	~Developer() = default;

public:
	float CalculateSalary()const override
	{
		return GetBaseSalary() + (GetBaseSalary() * 0.1);
	}
};

int main(void)
{
	Manager m("Kim", 5000); Developer d("Lee", 3000);
	Employee* staff[] = { &m, &d };
	for (int i = 0; i < 2; ++i)
		std::cout << staff[i]->CalculateSalary() << std::endl;

	return 0;
}