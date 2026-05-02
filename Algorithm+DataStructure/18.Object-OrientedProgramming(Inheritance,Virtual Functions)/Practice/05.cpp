#include <iostream>

using namespace std;

class Character
{
	Character() = delete;
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

public:
	Character(const char* name)
	{
		strcpy_s(mName, sizeof(mName), name);
	}
	virtual ~Character() = default;

public:
	virtual void Attack()const = 0;

private:
	char mName[100];
};

class Knight : public Character
{
	Knight() = delete;
	Knight(const Knight&) = delete;
	Knight& operator=(const Knight&) = delete;

public:
	Knight(const char* name)
		: Character(name)
	{
	}
	virtual ~Knight() = default;

public:
	void Attack()const override
	{
		cout << "slashes with sword" << endl;
	}
};

class Mage : public Character
{
	Mage() = delete;
	Mage(const Mage&) = delete;
	Mage& operator=(const Mage&) = delete;

public:
	Mage(const char* name)
		: Character(name)
	{
	}
	virtual ~Mage() = default;

public:
	void Attack()const override
	{
		cout << "casts a spell!" << endl;
	}
};

int main(void)
{
	Knight k("Arthur"); Mage m2("Merlin");
	Character* party[] = { &k, &m2 };
	for (int i = 0; i < 2; ++i)
		party[i]->Attack();


	return 0;
}