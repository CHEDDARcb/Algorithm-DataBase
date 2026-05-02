#include <iostream>

using namespace std;

class Person
{
	Person() = delete;
	Person(const Person&) = delete;
	Person& operator=(const Person&) = delete;

public:
	Person(const char* name)
	{
		int len = strlen(name);
		strcpy_s(mName, len + 1, name);
	}
	virtual ~Person() = default;

public:
	virtual void Introduce() = 0;

protected:
	const char* GetName()const { return mName; }

private:
	char mName[100];
};

class Student : public Person
{
	Student() = delete;
	Student(const Student&) = delete;
	Student& operator=(const Student&) = delete;

public:
	Student(const char* name)
		: Person(name)
	{
	}
	~Student() = default;

public:
	void Introduce()override
	{
		cout << "My name is " << GetName() << "." << endl;
		cout << "I'm Student." << endl;
	}
};

class Teacher : public Person
{
	Teacher() = delete;
	Teacher(const Teacher&) = delete;
	Teacher& operator=(const Teacher&) = delete;

public:
	Teacher(const char* name)
		: Person(name)
	{
	}
	virtual ~Teacher() = default;

public:
	void Introduce()override
	{
		cout << "My name is " << GetName() << "." << endl;
		cout << "I'm Teacher." << endl;
	}
};

int main(void)
{
	Student stu("Jisoo"); Teacher tea("Minho");
	Person* members[] = { &stu, &tea };
	for (int i = 0; i < 2; ++i)
		members[i]->Introduce();


	return 0;
}