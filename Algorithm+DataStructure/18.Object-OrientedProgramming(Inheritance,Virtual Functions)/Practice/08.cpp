#include <iostream>

using namespace std;

class Notification
{
	Notification() = delete;
	Notification(const Notification&) = delete;
	Notification& operator=(const Notification&) = delete;

public:
	Notification(const char* name)
	{
		strcpy_s(mRecipient, sizeof(mRecipient), name);
	}
	virtual ~Notification() = default;

public:
	virtual void Send()const = 0;

private:
	char mRecipient[100];
};

class EmailNotification : public Notification
{
	EmailNotification() = delete;
	EmailNotification(const EmailNotification&) = delete;
	EmailNotification& operator=(const EmailNotification&) = delete;

public:
	EmailNotification(const char* name)
		: Notification(name)
	{
	}
	virtual ~EmailNotification() = default;

public:
	void Send()const override
	{
		cout << "Email: Message!" << endl;
	}
};

class SMSNotification : public Notification
{
	SMSNotification() = delete;
	SMSNotification(const SMSNotification&) = delete;
	SMSNotification& operator=(const SMSNotification&) = delete;

public:
	SMSNotification(const char* name)
		: Notification(name)
	{
	}
	virtual ~SMSNotification() = default;

public:
	void Send()const override
	{
		cout << "SMS: Message!" << endl;
	}
};

int main(void)
{
	EmailNotification e("kim@example.com");
	SMSNotification s("010-1234-5678");
	Notification* notices[] = { &e, &s };
	for (int i = 0; i < 2; ++i)
		notices[i]->Send();



	return 0;
}