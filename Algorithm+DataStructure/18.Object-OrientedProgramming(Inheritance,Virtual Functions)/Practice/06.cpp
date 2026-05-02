#include <iostream>

using namespace std;

class SmartDevice
{
	SmartDevice(const SmartDevice&) = delete;
	SmartDevice& operator=(const SmartDevice&) = delete;

public:
	SmartDevice() = default;
	virtual ~SmartDevice() = default;

public:
	virtual void Execute(const char* command)const = 0;
};

class SmartLight : public SmartDevice
{
	SmartLight(const SmartLight&) = delete;
	SmartLight& operator=(const SmartLight&) = delete;

public:
	SmartLight() = default;
	virtual ~SmartLight() = default;

public:
	void Execute(const char* command)const override
	{
		if (strcmp(command, "turn on") == 0)
			cout << "Smart Light Turn On!" << endl;
	}
};

class SmartSpeaker : public SmartDevice
{
	SmartSpeaker(const SmartSpeaker&) = delete;
	SmartSpeaker& operator=(const SmartSpeaker&) = delete;

public:
	SmartSpeaker() = default;
	virtual ~SmartSpeaker() = default;

public:
	void Execute(const char* command)const override
	{
		if (strcmp(command, "turn on") == 0)
			cout << "Smart Speaker Turn On!" << endl;
	}
};

int main(void)
{
	SmartLight sl; SmartSpeaker ss;
	SmartDevice* devices[] = { &sl, &ss };
	for (int i = 0; i < 2; ++i)
		devices[i]->Execute("turn on");


	return 0;
}