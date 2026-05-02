#include <iostream>

using namespace std;

class Vehicle
{
	Vehicle(const Vehicle&) = delete;
	Vehicle& operator=(const Vehicle&) = delete;

public:
	Vehicle() = default;
	virtual ~Vehicle() = default;

public:
	virtual void Move() = 0;
};

class Bus : public Vehicle
{
	Bus(const Bus&) = delete;
	Bus& operator=(const Bus&) = delete;

public:
	Bus() = default;
	~Bus() = default;

public:
	void Move()
	{
		cout << "Bus Move" << endl;
	}
};

class Train : public Vehicle
{
	Train(const Train&) = delete;
	Train& operator=(const Train&) = delete;

public:
	Train() = default;
	virtual ~Train() = default;

public:
	void Move()
	{
		cout << "Train Move" << endl;
	}
};

int main(void)
{
	Bus bus; Train train;
	Vehicle* vehicles[] = { &bus, &train };
	for (int i = 0; i < 2; ++i)
		vehicles[i]->Move();

	return 0;
}