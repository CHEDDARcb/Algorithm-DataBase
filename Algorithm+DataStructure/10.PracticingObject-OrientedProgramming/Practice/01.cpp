#include <iostream>

using namespace std;

class Person
{
	Person() = delete;
	Person(const Person&) = delete;
public:
	Person(const int age, const char* name, const char sex, const char* country)
		: mAge(age)
		, mName{}
		, mSex(sex)
		, mCountry{}
	{
		int len = strlen(name);
		strncpy_s(mName, len + 1, name, len);

		len = strlen(country);
		strncpy_s(mCountry, len + 1, country, len);
	}
	~Person() = default;

public:
	const int		GetAge()const { return mAge; }
	const char		GetSex()const { return mSex; }
	const char* GetName()const { return mName; }
	const char* GetCountry()const { return mCountry; }

public:
	void Introduce()const
	{
		cout << "My name is " << mName << ", ";
		cout << mAge << "years old, ";
		cout << mSex << ", ";
		cout << "from " << mCountry << "." << endl;
	}

	void GrowUp()
	{
		++mAge;
		cout << mName << " is now " << mAge << "years old." << endl;
	}

private:
	int mAge;
	char mName[256];
	char mSex;
	char mCountry[256];
};

int main()
{
	Person person(25, "Alice", 'F', "Canada");

	person.Introduce();

	person.GrowUp();

	return 0;
}