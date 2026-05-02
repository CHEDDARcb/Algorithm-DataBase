#include <iostream>

using namespace std;

class Person
{
	Person(const Person&) = delete;
	Person& operator=(const Person&) = delete;
public:
	Person()
		: mName{}
		, mAdress{}
		, mPhone{}
		, mID(0)
		, mMileage(0)
	{
	}
	Person(const char* _name, const char* _adress, const char* _phone)
		: mName{}
		, mAdress{}
		, mPhone{}
		, mID(0)
		, mMileage(0)
	{
		int len = strlen(_name);
		strncpy_s(mName, len + 1, _name, len);

		len = strlen(_adress);
		strncpy_s(mAdress, len + 1, _adress, len);

		len = strlen(_phone);
		strncpy_s(mPhone, len + 1, _phone, len);
	}
	~Person() = default;

public:
	void			SetName()
	{
		if (strlen(mName))
			memset(mName, 0, sizeof(mName));

		char name[256]{};
		cout << "이름를 입력하세요: ";
		cin >> name;
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);
	}

	void			SetAdress()
	{
		if (strlen(mAdress))
			memset(mAdress, 0, sizeof(mAdress));

		char adress[256]{};
		cout << "주소를 입력하세요: ";
		cin >> adress;
		int len = strlen(adress);
		strncpy_s(mAdress, len + 1, adress, len);
	}

	void			SetPhone()
	{
		if (strlen(mPhone))
			memset(mPhone, 0, sizeof(mPhone));

		char phone[256]{};
		cout << "연락처를 입력하세요: ";
		cin >> phone;
		int len = strlen(phone);
		strncpy_s(mPhone, len + 1, phone, len);
	}

	void			SetID()
	{
		int id;
		cout << "ID를 입력하세요: ";
		cin >> id;
		mID = id;
	}

	void			SetMileage()
	{
		int mileage;
		cout << "마일리지를 입력하세요: ";
		cin >> mileage;
		mMileage = mileage;
	}

public:
	const char* GetName()const { return mName; }
	const char* GetAdress()const { return mAdress; }
	const char* GetPhone()const { return mPhone; }
	const int		GetID()const { return mID; }
	const int		GetMileage()const { return mMileage; }

private:
	char	mName[256];
	char	mAdress[256];
	char	mPhone[256];
	int		mID;
	int		mMileage;
};

int main()
{
	Person p;

	p.SetName();
	p.SetAdress();
	p.SetPhone();
	p.SetID();
	p.SetMileage();

	cout << "-----고객 정보-----" << endl;
	cout << "이름: " << p.GetName() << endl;
	cout << "주소: " << p.GetAdress() << endl;
	cout << "연락처: " << p.GetPhone() << endl;
	cout << "고객ID: " << p.GetID() << endl;
	cout << "마일리지: " << p.GetMileage() << endl;

	return 0;
}