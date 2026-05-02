#include <iostream>

using namespace std;

class Unit
{
	Unit() = delete;
	Unit(const Unit&) = delete;
	Unit& operator=(const Unit&) = delete;

public:
	Unit(const char* name)
	{
		strcpy_s(mName, sizeof(mName), name);
	}
	virtual ~Unit() = default;

public:
	virtual void Move()const = 0;

private:
	char mName[100];
};

class Knight : public Unit
{
	Knight() = delete;
	Knight(const Knight&) = delete;
	Knight& operator=(const Knight&) = delete;

public:
	Knight(const char* name)
		: Unit(name)
	{
	}
	virtual ~Knight() = default;

public:
	void Move()const override
	{
		cout << "Walk!" << endl;
	}
};

class Mage : public Unit
{
	Mage() = delete;
	Mage(const Mage&) = delete;
	Mage& operator=(const Mage&) = delete;

public:
	Mage(const char* name)
		: Unit(name)
	{
	}
	virtual ~Mage() = default;

public:
	void Move()const override
	{
		cout << "Ride!" << endl;
	}
};

int main(void)
{
	Knight k("Arthur"); Mage m2("Merlin");
	Unit* party[] = { &k, &m2 };
	for (int i = 0; i < 2; ++i)
		party[i]->Move();


	return 0;
}