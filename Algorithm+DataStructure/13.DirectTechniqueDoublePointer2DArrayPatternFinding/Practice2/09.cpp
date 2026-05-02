#include <iostream>

using namespace std;

class CoffeeMachine
{
public:
	CoffeeMachine(const int _coffee, const int _watter, const int _sugar)
		: mCoffee(_coffee)
		, mWatter(_watter)
		, mSugar(_sugar)
	{
	}

public:
	void drinkEspresso()
	{
		if (mCoffee >= 1 && mWatter >= 1)
		{
			mCoffee -= 1;
			mWatter -= 1;
		}
		else
			cout << "Failed drinking";
	}
	void drinkAmericano()
	{
		if (mCoffee >= 1 && mWatter >= 2)
		{
			mCoffee -= 1;
			mWatter -= 2;
		}
		else
			cout << "Failed drinking";
	}
	void drinkSugarCoffee()
	{
		if (mCoffee >= 1 && mWatter >= 2 && mSugar >= 1)
		{
			mCoffee -= 1;
			mWatter -= 2;
			mSugar -= 1;
		}
		else
			cout << "Failed drinking";
	}
	void show()const
	{
		cout << "Ä¿ÇÇ: " << mCoffee << endl;
		cout << "¹°: " << mWatter << endl;
		cout << "¼³ÅÁ: " << mSugar << endl;
		cout << endl;
	}
	void fill()
	{
		mCoffee += 1;
		mWatter += 1;
		mSugar += 1;
	}

private:
	int mCoffee;
	int mWatter;
	int mSugar;
};

int main()
{
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();

	return 0;
}