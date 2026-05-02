#include <iostream>

using namespace std;

class Fighter
{
	Fighter() = delete;
	Fighter(const Fighter&) = delete;
	Fighter& operator=(const Fighter&) = delete;

public:
	Fighter(const int hp, const int att)
		: mHP(hp)
		, mAttack(att)
	{

	}
	virtual ~Fighter() = default;

public:
	virtual void DealDamage() = 0;

private:
	int mHP;
	int mAttack;
};

class Swordman : public Fighter
{
	Swordman() = delete;
	Swordman(const Swordman&) = delete;
	Swordman& operator=(const Swordman&) = delete;

public:
	Swordman(const int hp, const int att)
		: Fighter(hp, att)
	{
	}
	~Swordman() = default;

public:
	void DealDamage()override
	{
		cout << "SwardMan Damge" << endl;
	}
};

class Mage : public Fighter
{
	Mage() = delete;
	Mage(const Mage&) = delete;
	Mage& operator=(const Mage&) = delete;

public:
	Mage(const int hp, const int att)
		: Fighter(hp, att)
	{
	}
	virtual ~Mage() = default;

public:
	void DealDamage()override
	{
		cout << "Mage Damge" << endl;
	}
};

int main(void)
{
	Swordman sw(100, 20); Mage mg(100, 30);
	Fighter* fighters[] = { &sw, &mg };
	for (int i = 0; i < 2; ++i)
		fighters[i]->DealDamage();


	return 0;
}