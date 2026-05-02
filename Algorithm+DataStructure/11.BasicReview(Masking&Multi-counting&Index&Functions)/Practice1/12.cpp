#include<iostream>

using namespace std;

class Warrior
{
	Warrior() = delete;
	Warrior(const Warrior&) = delete;
	Warrior& operator=(const Warrior&) = delete;
public:
	Warrior(const int hp, const int attackPoint)
		: mHP(hp)
		, mAttackPoint(attackPoint)
	{

	}

public:
	const int		GetHP()const { return mHP; }
	const int		GetAttackPoint()const { return mAttackPoint; }
private:
	int mHP;
	int mAttackPoint;
};

class Magicion
{
	Magicion() = delete;
	Magicion(const Magicion&) = delete;
	Magicion& operator=(const Magicion&) = delete;
public:
	Magicion(const int hp, const int attackPoint)
		: mHP(hp)
		, mAttackPoint(attackPoint)
	{

	}

public:
	const int		GetHP()const { return mHP; }
	const int		GetAttackPoint()const { return mAttackPoint; }

private:
	int mHP;
	int mAttackPoint;
};

class Archer
{
	Archer() = delete;
	Archer(const Archer&) = delete;
	Archer& operator=(const Archer&) = delete;
public:
	Archer(const int hp, const int attackPoint)
		: mHP(hp)
		, mAttackPoint(attackPoint)
	{

	}

public:
	const int		GetHP()const { return mHP; }
	const int		GetAttackPoint()const { return mAttackPoint; }

private:
	int mHP;
	int mAttackPoint;
};

class Party
{
	Party(const Party&) = delete;
	Party& operator=(const Party&) = delete;
public:
	Party()
		: mWarrior(nullptr)
		, mMagicion(nullptr)
		, mArcher(nullptr)
	{
	}
	~Party() = default;

public:
	void		SetParty(Warrior* _Warrior, Archer* _Archer, Magicion* _Magicion)
	{
		mWarrior = _Warrior;
		mArcher = _Archer;
		mMagicion = _Magicion;
	}

public:
	void		PrintPartyInfo()const
	{
		cout << "Warrior: " << "HP(" << mWarrior->GetHP() << ") Att(" << mWarrior->GetAttackPoint() << ")" << endl;
		cout << "Magicion: " << "HP(" << mMagicion->GetHP() << ") Att(" << mMagicion->GetAttackPoint() << ")" << endl;
		cout << "Archer: " << "HP(" << mArcher->GetHP() << ") Att(" << mArcher->GetAttackPoint() << ")" << endl;
	}

private:
	Warrior* mWarrior;
	Magicion* mMagicion;
	Archer* mArcher;
};

int main()
{
	Warrior warrior(100, 20);
	Archer archer(100, 30);
	Magicion magicion(100, 10);
	Party party;

	party.SetParty(&warrior, &archer, &magicion);

	party.PrintPartyInfo();

	return 0;
}