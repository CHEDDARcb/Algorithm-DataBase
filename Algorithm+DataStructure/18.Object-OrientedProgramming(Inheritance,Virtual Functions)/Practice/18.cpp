#include <iostream>

using namespace std;

class MenuItem
{
	MenuItem() = delete;
	MenuItem(const MenuItem&) = delete;
	MenuItem& operator=(const MenuItem&) = delete;

public:
	MenuItem(const int price)
		: mPrice(price)
	{
	}
	virtual ~MenuItem() = default;

public:
	virtual void PrintPrice() = 0;

protected:
	int GetPrice()const { return mPrice; }

private:
	int mPrice;
};

class Burger : public MenuItem
{
	Burger() = delete;
	Burger(const Burger&) = delete;
	Burger& operator=(const Burger&) = delete;

public:
	Burger(const int price)
		: MenuItem(price)
	{
	}
	~Burger() = default;

public:
	void PrintPrice()override
	{
		cout << "Bugger: " << GetPrice() << "$" << endl;
	}
};

class Pizza : public MenuItem
{
	Pizza() = delete;
	Pizza(const Pizza&) = delete;
	Pizza& operator=(const Pizza&) = delete;

public:
	Pizza(const int price)
		: MenuItem(price)
	{
	}
	virtual ~Pizza() = default;

public:
	void PrintPrice()override
	{
		cout << "Pizza: " << GetPrice() << "$" << endl;
	}
};

int main(void)
{
	Burger bur(5000); Pizza piz(8000);
	MenuItem* order[] = { &bur, &piz };
	for (int i = 0; i < 2; ++i)
		order[i]->PrintPrice();

	return 0;
}