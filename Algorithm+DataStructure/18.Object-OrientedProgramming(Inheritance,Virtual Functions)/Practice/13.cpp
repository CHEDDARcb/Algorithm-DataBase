#include <iostream>

using namespace std;

class Device
{
	Device() = delete;
	Device(const Device&) = delete;
	Device& operator=(const Device&) = delete;

public:
	Device(const char* name)
	{
		int len = strlen(name);
		strcpy_s(mName, len + 1, name);
	}
	virtual ~Device() = default;

public:
	virtual void PowerOn() = 0;

private:
	char mName[100];
};

class Laptop : public Device
{
	Laptop() = delete;
	Laptop(const Laptop&) = delete;
	Laptop& operator=(const Laptop&) = delete;

public:
	Laptop(const char* name)
		: Device(name)
	{
	}
	~Laptop() = default;

public:
	void PowerOn()
	{
		cout << "Laptop power on" << endl;
	}
};

class Tablet : public Device
{
	Tablet() = delete;
	Tablet(const Tablet&) = delete;
	Tablet& operator=(const Tablet&) = delete;

public:
	Tablet(const char* name)
		: Device(name)
	{
	}
	virtual ~Tablet() = default;

public:
	void PowerOn()
	{
		cout << "Tablet ower on" << endl;
	}
};

int main(void)
{
	Laptop l("Lenovo"); Tablet t("iPad");
	Device* gadgets[] = { &l, &t };
	for (int i = 0; i < 2; ++i)
		gadgets[i]->PowerOn();

	return 0;
}